cmake_minimum_required(VERSION 3.20)
### tests

if(_PHREEQCRM_TEST_INSTALL)
  project(TestInstall
    LANGUAGES CXX C
  )
  option(PHREEQCRM_FORTRAN_TESTING "Build Fortran test" OFF)
  if(PHREEQCRM_FORTRAN_TESTING)
    enable_language(Fortran)
  endif()
  find_package(PhreeqcRM REQUIRED)  #  sets PhreeqcRM_DIR if found
  if(yaml-cpp_FOUND)
    set(PHREEQCRM_WITH_YAML_CPP ON)
  endif()
  enable_testing()
endif()

if(PHREEQCRM_FORTRAN_TESTING)
  project(FortranAdvect Fortran)

  # TestRM Fortran library
  add_library(FortranAdvect STATIC)

  # TestRM Fortran source
  target_sources(FortranAdvect PRIVATE
    ../src/BMI_interface.F90
    ../src/IPhreeqcPhast/IPhreeqc/IPhreeqc_interface.F90
    ../src/RM_interface.F90
    Advect_f90.F90
    AdvectBMI_f90.F90
    Gas_f90.F90
    SimpleAdvect_f90.F90
    Species_f90.F90
  )

  # place [*.F[90]] files into "Source Files"
  source_group("Source Files" FILES "../src/BMI_interface.F90")
  source_group("Source Files" FILES "../src/BMI_not_implemented.inc")
  source_group("Source Files" FILES "../src/IPhreeqcPhast/IPhreeqc/IPhreeqc_interface.F90")
  source_group("Source Files" FILES "../src/RM_interface.F90")
  source_group("Source Files" FILES "Advect_f90.F90")
  source_group("Source Files" FILES "AdvectBMI_f90.F90")
  source_group("Source Files" FILES "Gas_f90.F90")
  source_group("Source Files" FILES "SimpleAdvect_f90.F90")
  source_group("Source Files" FILES "Species_f90.F90")
  
  if(_PHREEQCRM_TEST_INSTALL)
    target_sources(FortranAdvect PRIVATE
      ${PhreeqcRM_DIR}/src/IPhreeqc_interface.F90
      ${PhreeqcRM_DIR}/src/RM_interface.F90
    )
    source_group("Source Files" FILES "${PhreeqcRM_DIR}/src/IPhreeqcPhast/IPhreeqc/IPhreeqc_interface.F90")
    source_group("Source Files" FILES "${PhreeqcRM_DIR}/src/RM_interface.F90")
  else()
    target_sources(FortranAdvect PRIVATE
      ../src/IPhreeqcPhast/IPhreeqc/IPhreeqc_interface.F90
      ../src/RM_interface.F90
    )
    source_group("Source Files" FILES "../src/IPhreeqcPhast/IPhreeqc/IPhreeqc_interface.F90")
    source_group("Source Files" FILES "../src/RM_interface.F90")
  endif()


  if(PHREEQCRM_WITH_YAML_CPP)
    target_sources(FortranAdvect PRIVATE
      WriteYAMLFile_f90.F90
    )
    source_group("Source Files" FILES "WriteYAMLFile_f90.F90")

    if(_PHREEQCRM_TEST_INSTALL)
      target_sources(FortranAdvect PRIVATE
        ${PhreeqcRM_DIR}/src/YAML_interface.F90
      )
      source_group("Source Files" FILES "${PhreeqcRM_DIR}/src/YAML_interface.F90")
    else()
      target_sources(FortranAdvect PRIVATE
        ../src/YAML_interface.F90
      )
      source_group("Source Files" FILES "../src/YAML_interface.F90")
    endif()
  endif()


  # The next line sets defines/includes/libraries
  # for compiling and linking the FortranAdvect library
  target_link_libraries(FortranAdvect PhreeqcRM::PhreeqcRM)
endif()

project(TestRM CXX)

# Tests/advect.pqi
configure_file(advect.pqi advect.pqi COPYONLY)

# Tests/phreeqc.dat
configure_file(phreeqc.dat phreeqc.dat COPYONLY)

# Tests/units.pqi
configure_file(units.pqi units.pqi COPYONLY)

# Tests/units.pqi
configure_file(gas.pqi gas.pqi COPYONLY)

# test executable
add_executable(TestRM)

# TestRM C/CXX source
target_sources(TestRM PRIVATE
  AdvectBMI_cpp.cpp
  Advect_c.c
  Advect_cpp.cpp
  Gas_c.c
  Gas_cpp.cpp
  main.cpp
  SimpleAdvect_c.c
  SimpleAdvect_cpp.cpp
  Species_c.c
  Species_cpp.cpp
)

if(PHREEQCRM_WITH_YAML_CPP)
  target_sources(TestRM PRIVATE
    WriteYAMLFile_cpp.cpp
  )
endif()

if(PHREEQCRM_FORTRAN_TESTING)
  target_compile_definitions(TestRM PRIVATE TEST_FORTRAN)
endif()

# library dependencies
target_link_libraries(TestRM PhreeqcRM::PhreeqcRM)

if(PHREEQCRM_FORTRAN_TESTING)
  # Override bug reported on:
  # http://www.cmake.org/pipermail/cmake/2009-July/030954.html
  if(WIN32 AND ${CMAKE_Fortran_COMPILER_ID} STREQUAL "Intel")
    if(NOT CMAKE_Fortran_FLAGS_DEBUG MATCHES "/Od")
      set(CMAKE_Fortran_FLAGS_DEBUG "/Od ${CMAKE_Fortran_FLAGS_DEBUG}")
    endif()
  endif()
  target_link_libraries(TestRM FortranAdvect)
endif()

# test compile and run
add_test(TestCompileAndRun TestRM)

set_property(TARGET TestRM APPEND
  PROPERTY ADDITIONAL_CLEAN_FILES
    Advect_c_utility.txt
    Advect_c.chem.txt
    Advect_c.dmp
    Advect_c.log.txt
    Advect_cpp_units_utility.txt
    Advect_cpp_units_worker.chem.txt
    Advect_cpp_units_worker.log.txt
    Advect_cpp_utility.txt
    Advect_cpp.chem.txt
    Advect_cpp.dmp
    Advect_cpp.log.txt
    Advect_f90_utility.txt
    Advect_f90.chem.txt
    Advect_f90.dmp
    Advect_f90.log.txt
    AdvectBMI_cpp_utility.txt
    AdvectBMI_cpp.chem.txt
    AdvectBMI_cpp.dmp
    AdvectBMI_cpp.log.txt
    AdvectBMI_cpp.yaml
    AdvectBMI_f90.chem.txt
    AdvectBMI_f90.dmp
    AdvectBMI_f90.log.txt
    AdvectBMI_f90.yaml
    Advectcpp_utility.txt
    Advectcpp.dmp
    Gas_c.chem.txt
    Gas_c.log.txt
    Gas_cpp.chem.txt
    Gas_cpp.log.txt
    Gas_f90.chem.txt
    Gas_f90.log.txt
    SimpleAdvect_c.chem.txt
    SimpleAdvect_c.log.txt
    SimpleAdvect_cpp.chem.txt
    SimpleAdvect_cpp.log.txt
    SimpleAdvect_f90.chem.txt
    SimpleAdvect_f90.log.txt
    Species_c_utility.txt
    Species_c.chem.txt
    Species_c.dmp
    Species_c.log.txt
    Species_cpp_utility.txt
    Species_cpp.chem.txt
    Species_cpp.dmp
    Species_cpp.log.txt
    Species_f90_utility.txt
    Species_f90.chem.txt
    Species_f90.dmp
    Species_f90.log.txt
)

if(MSVC AND BUILD_SHARED_LIBS)
  # copy PhreeqcRM dll
  add_custom_command(TARGET TestRM POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:PhreeqcRM> $<TARGET_FILE_DIR:TestRM>
  )
  if(PHREEQCRM_WITH_YAML_CPP)
    # copy yaml-cpp dll
    add_custom_command(TARGET TestRM POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:yaml-cpp> $<TARGET_FILE_DIR:TestRM>
    )
  endif()
endif()

# MPI test
# get_property(exe_location TARGET testrm PROPERTY LOCATION)
# message (STATUS "exe_location = ${exe_location}")
if(PHREEQCRM_BUILD_MPI)
  add_test(NAME TestMPI
           COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3
           ${MPIEXEC_PREFLAGS}
           $<TARGET_FILE:TestRM>
           ${MPIEXEC_POSTFLAGS}
           )
endif()

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#   message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

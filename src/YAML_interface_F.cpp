#ifdef USE_YAML
#include <cstring>
#include <string>
#include <vector>
#include "YAMLPhreeqcRM.h"
#include "YAML_interface_F.h"

int CreateYAMLPhreeqcRM_F(void)
{
	return YAMLPhreeqcRMLib::CreateYAMLPhreeqcRM();
}
int DestroyYAMLPhreeqcRM_F(int* id)
{
	return YAMLPhreeqcRMLib::DestroyYAMLPhreeqcRM(*id);
}
IRM_RESULT        YAMLAddOutputVars_F(int* id, char* option_in, char* def_in)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::string option = option_in;
		std::string def = def_in;
		yrm_ptr->YAMLAddOutputVars(option, def);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLClear_F(int* id)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->Clear();
		return IRM_OK;
	}
	return IRM_BADINSTANCE;

}
IRM_RESULT WriteYAMLDoc_F(int* id, const char* file_name)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->WriteYAMLDoc(file_name);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLCloseFiles_F(int* id)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLCloseFiles();
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLCreateMapping_F(int* id, int* grid2chem, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> grid2chem_v(*dim, 0);
		memcpy(grid2chem_v.data(), grid2chem, (*dim) * sizeof(int));
		yrm_ptr->YAMLCreateMapping(grid2chem_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLDumpModule_F(int* id, int* idump_on, int* iappend)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool dump_on = (bool)*idump_on;
		bool append = (bool)*iappend;
		yrm_ptr->YAMLDumpModule(dump_on, append);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLFindComponents_F(int* id)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLFindComponents();
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLInitialSolutions2Module_F(int* id, int* ic1, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> ic1_v(*dim, -1);
		memcpy(ic1_v.data(), ic1, (*dim) * sizeof(int));
		yrm_ptr->YAMLInitialSolutions2Module(ic1_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLInitialEquilibriumPhases2Module_F(int* id, int* ic1, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> ic1_v(*dim, -1);
		memcpy(ic1_v.data(), ic1, (*dim) * sizeof(int));
		yrm_ptr->YAMLInitialEquilibriumPhases2Module(ic1_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLInitialExchanges2Module_F(int* id, int* ic1, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> ic1_v(*dim, -1);
		memcpy(ic1_v.data(), ic1, (*dim) * sizeof(int));
		yrm_ptr->YAMLInitialExchanges2Module(ic1_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLInitialSurfaces2Module_F(int* id, int* ic1, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> ic1_v(*dim, -1);
		memcpy(ic1_v.data(), ic1, (*dim) * sizeof(int));
		yrm_ptr->YAMLInitialSurfaces2Module(ic1_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLInitialGasPhases2Module_F(int* id, int* ic1, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> ic1_v(*dim, -1);
		memcpy(ic1_v.data(), ic1, (*dim) * sizeof(int));
		yrm_ptr->YAMLInitialGasPhases2Module(ic1_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLInitialSolidSolutions2Module_F(int* id, int* ic1, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> ic1_v(*dim, -1);
		memcpy(ic1_v.data(), ic1, (*dim) * sizeof(int));
		yrm_ptr->YAMLInitialSolidSolutions2Module(ic1_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLInitialKinetics2Module_F(int* id, int* ic1, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> ic1_v(*dim, -1);
		memcpy(ic1_v.data(), ic1, (*dim) * sizeof(int));
		yrm_ptr->YAMLInitialKinetics2Module(ic1_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLInitialPhreeqc2Module_F(int* id, int* ic1, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> ic1_v(*dim, -1);
		memcpy(ic1_v.data(), ic1, (*dim) * sizeof(int));
		yrm_ptr->YAMLInitialPhreeqc2Module(ic1_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLInitialPhreeqc2Module_mix_F(int* id, int* ic1, int* ic2, double* f1, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> ic1_v(*dim, -1), ic2_v(*dim, -1);
		std::vector<double> f1_v(*dim, 0.0);
		memcpy(ic1_v.data(), ic1, (*dim)*sizeof(int));
		memcpy(ic2_v.data(), ic2, (*dim) * sizeof(int));
		memcpy(f1_v.data(), f1, (*dim) * sizeof(double));
		yrm_ptr->YAMLInitialPhreeqc2Module(ic1_v, ic2_v, f1_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}; 

IRM_RESULT YAMLInitialPhreeqcCell2Module_F(int* id, 
	int* n, int* cell_numbers, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> cell_numbers_v(*dim, 0.0);
		memcpy(cell_numbers_v.data(), cell_numbers, (*dim) * sizeof(int));
		yrm_ptr->YAMLInitialPhreeqcCell2Module(*n, cell_numbers_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}

IRM_RESULT YAMLLoadDatabase_F(int* id, const char* database)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLLoadDatabase(database);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLLogMessage_F(int* id, const char* str)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLLogMessage(str);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLOpenFiles_F(int* id)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLOpenFiles();
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLOutputMessage_F(int* id, const char* str)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLOutputMessage(str);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLRunCells_F(int* id)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLRunCells();
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLRunFile_F(int* id, int* iworkers, int* iinitial_phreeqc, 
	int* iutility, const char* file_name)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool workers = (bool)*iworkers;
		bool initial_phreeqc = (bool)*iinitial_phreeqc;
		bool utility = (bool)*iutility;

		yrm_ptr->YAMLRunFile(workers, initial_phreeqc, utility, file_name);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLRunString_F(int* id, int* iworkers, int* iinitial_phreeqc, 
	int* iutility, const char* input_string)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool workers = (bool)*iworkers;
		bool initial_phreeqc = (bool)*iinitial_phreeqc;
		bool utility = (bool)*iutility;
		yrm_ptr->YAMLRunString(workers, initial_phreeqc, utility, input_string);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLScreenMessage_F(int* id, const char* str)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLScreenMessage(str);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetComponentH2O_F(int* id, int* itf)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool tf = (bool)itf;
		yrm_ptr->YAMLSetComponentH2O(tf);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetConcentrations_F(int* id, double* c, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> c_v(*dim, 0.0);
		memcpy(c_v.data(), c, (*dim) * sizeof(double));
		yrm_ptr->YAMLSetConcentrations(c_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetCurrentSelectedOutputUserNumber_F(int* id, int* n_user)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetCurrentSelectedOutputUserNumber(*n_user);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetDensityUser_F(int* id, double* density, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> density_v(*dim, 0.0);
		memcpy(density_v.data(), density, (*dim) * sizeof(double));
		yrm_ptr->YAMLSetDensityUser(density_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetDumpFileName_F(int* id, const char* dump_name)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetDumpFileName(dump_name);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetErrorHandlerMode_F(int* id, int* mode)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetErrorHandlerMode(*mode);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetErrorOn_F(int* id, int* itf)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool tf = (bool)*itf;
		yrm_ptr->YAMLSetErrorOn(tf);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetFilePrefix_F(int* id, const char* prefix)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetFilePrefix(prefix);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetGasCompMoles_F(int* id, double* gas_moles, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> gas_moles_v(*dim, 0.0);
		memcpy(gas_moles_v.data(), gas_moles, (*dim) * sizeof(double));
		yrm_ptr->YAMLSetGasCompMoles(gas_moles_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetGasPhaseVolume_F(int* id, double* gas_volume, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> gas_volume_v(*dim, 0.0);
		memcpy(gas_volume_v.data(), gas_volume, (*dim) * sizeof(double));
		yrm_ptr->YAMLSetGasPhaseVolume(gas_volume_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetGridCellCount_F(int* id, int* count)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetGridCellCount(*count);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetNthSelectedOutput_F(int* id, int* n)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetNthSelectedOutput(*n);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetPartitionUZSolids_F(int* id, int* itf)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool tf = (bool)*itf;
		yrm_ptr->YAMLSetPartitionUZSolids(tf);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetPorosity_F(int* id, double* por, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> por_v(*dim, 0.0);
		memcpy(por_v.data(), por, (*dim) * sizeof(double));
		yrm_ptr->YAMLSetPorosity(por_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetPressure_F(int* id, double* p, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> p_v(*dim, 0.0);
		memcpy(p_v.data(), p, (*dim) * sizeof(double));
		yrm_ptr->YAMLSetPressure(p_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetPrintChemistryMask_F(int* id, int* cell_mask, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<int> cell_mask_v(*dim, 0.0);
		memcpy(cell_mask_v.data(), cell_mask, (*dim) * sizeof(int));
		yrm_ptr->YAMLSetPrintChemistryMask(cell_mask_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetPrintChemistryOn_F(int* id, int* iworkers, int* iinitial_phreeqc, 
	int* iutility)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool workers = (bool)*iworkers;
		bool initial_phreeqc = (bool)*iinitial_phreeqc;
		bool utility = (bool)*iutility;
		yrm_ptr->YAMLSetPrintChemistryOn(workers, initial_phreeqc, utility);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetRebalanceByCell_F(int* id, int* itf)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool tf = (bool)*itf;
		yrm_ptr->YAMLSetRebalanceByCell(tf);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetRebalanceFraction_F(int* id, double* f)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetRebalanceFraction(*f);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetRepresentativeVolume_F(int* id, double* rv, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> rv_v(*dim, 0.0);
		memcpy(rv_v.data(), rv, (*dim) * sizeof(double));
		yrm_ptr->YAMLSetRepresentativeVolume(rv_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetSaturationUser_F(int* id, double* sat, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> sat_v(*dim, 0.0);
		memcpy(sat_v.data(), sat, (*dim) * sizeof(double));
		yrm_ptr->YAMLSetSaturationUser(sat_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetScreenOn_F(int* id, int* itf)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool tf = (bool)*itf;
		yrm_ptr->YAMLSetScreenOn(tf);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetSelectedOutputOn_F(int* id, int* itf)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool tf = (bool)*itf;
		yrm_ptr->YAMLSetSelectedOutputOn(tf);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetSpeciesSaveOn_F(int* id, int* isave_on)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool save_on = (bool)*isave_on;
		yrm_ptr->YAMLSetSpeciesSaveOn(save_on);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetTemperature_F(int* id, double* t, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> t_v(*dim, 0.0);
		memcpy(t_v.data(), t, (*dim) * sizeof(double));
		yrm_ptr->YAMLSetTemperature(t_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetTime_F(int* id, double* time)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetTime(*time);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetTimeConversion_F(int* id, double* conv_factor)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetTimeConversion(*conv_factor);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetTimeStep_F(int* id, double* time_step)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetTimeStep(*time_step);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSetUnitsExchange_F(int* id, int* option)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetUnitsExchange(*option);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetUnitsGasPhase_F(int* id, int* option)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetUnitsGasPhase(*option);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetUnitsKinetics_F(int* id, int* option)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetUnitsKinetics(*option);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetUnitsPPassemblage_F(int* id, int* option)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetUnitsPPassemblage(*option);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetUnitsSolution_F(int* id, int* option)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetUnitsSolution(*option);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetUnitsSSassemblage_F(int* id, int* option)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetUnitsSSassemblage(*option);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLSetUnitsSurface_F(int* id, int* option)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLSetUnitsSurface(*option);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLSpeciesConcentrations2Module_F(int* id, double* species_conc, int* dim)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		std::vector<double> species_conc_v(*dim, 0.0);
		memcpy(species_conc_v.data(), species_conc, (*dim) * sizeof(double));
		yrm_ptr->YAMLSpeciesConcentrations2Module(species_conc_v);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLStateSave_F(int* id, int* istate)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLStateSave(*istate);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLStateApply_F(int* id, int* istate)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLStateApply(*istate);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLStateDelete_F(int* id, int* istate)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLStateDelete(*istate);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLThreadCount_F(int* id, int* nthreads)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLThreadCount(*nthreads);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
IRM_RESULT YAMLUseSolutionDensityVolume_F(int* id, int* itf)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		bool tf = (bool)*itf;
		yrm_ptr->YAMLUseSolutionDensityVolume(tf);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
};
IRM_RESULT YAMLWarningMessage_F(int* id, const char* warnstr)
{
	YAMLPhreeqcRM* yrm_ptr = YAMLPhreeqcRMLib::GetInstance(*id);
	if (yrm_ptr != NULL)
	{
		yrm_ptr->YAMLWarningMessage(warnstr);
		return IRM_OK;
	}
	return IRM_BADINSTANCE;
}
#endif
import pytest
import os
import shutil

from constants import FilePaths

def pytest_sessionstart():
    cwd = os.getcwd()

    filenames = [FilePaths.DATABASE, FilePaths.PQI]
    for filename in filenames:
        src = filename
        dest = os.path.join(cwd, os.path.basename(filename))
        if not os.path.exists(dest):
            shutil.copy(src, dest)

@pytest.fixture
def create_yaml_file():
    try:
        import WriteYamlFile as yrm
        yrm.WriteYamlFile()
        yield
        # cleanup
        yaml = FilePaths.YAML
        if os.path.exists(yaml):
            os.remove(yaml)
    except Exception as e:
        pytest.skip(f"Cannot create yaml file: {e}")

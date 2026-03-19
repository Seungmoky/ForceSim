@echo off
set "MSBUILD=C:\Program Files\Microsoft Visual Studio\2022\Professional\MSBuild\Current\Bin\amd64\MSBuild.exe"
echo [Build] ForceConsole (x64 Debug)
"%MSBUILD%" C:\smlee\git_project\ForceSim\ForceConsole\ForceConsole.vcxproj /t:Build /p:Configuration=Debug /p:Platform=x64 /p:SolutionDir=C:\smlee\git_project\ForceSim\ /v:minimal
exit /b %ERRORLEVEL%

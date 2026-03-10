@echo off
setlocal

set "VSDEVCMD=C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\Tools\VsDevCmd.bat"
set "MSBUILD=C:\Program Files\Microsoft Visual Studio\2022\Professional\MSBuild\Current\Bin\amd64\MSBuild.exe"

if not exist "%VSDEVCMD%" (
  echo [ERROR] VsDevCmd.bat not found: %VSDEVCMD%
  exit /b 1
)

if not exist "%MSBUILD%" (
  echo [ERROR] MSBuild.exe not found: %MSBUILD%
  exit /b 1
)

call "%VSDEVCMD%" -arch=x64 -host_arch=x64 >nul
if errorlevel 1 (
  echo [ERROR] Failed to initialize Visual Studio developer environment.
  exit /b %errorlevel%
)

set "ROOT=%~dp0.."

echo [Build] ForceAlgoDll (x64 Debug)
"%MSBUILD%" "%ROOT%\ForceAlgoDll\ForceAlgoDll.vcxproj" /t:Build /m:1 /p:Configuration=Debug /p:Platform=x64 /p:SolutionDir=%ROOT%\
if errorlevel 1 exit /b %errorlevel%

echo [Build] ForceSim.App (x64 Debug)
"%MSBUILD%" "%ROOT%\ForceSim.App\ForceSim.App.csproj" /t:Build /m:1 /p:Configuration=Debug /p:Platform=x64
exit /b %errorlevel%

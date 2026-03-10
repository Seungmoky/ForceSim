@echo off
setlocal

call "%~dp0build_debug_x64.cmd"
set "BUILD_RC=%ERRORLEVEL%"

if not "%BUILD_RC%"=="0" (
  echo [WARN] Build failed with exit code %BUILD_RC%.
  echo [WARN] Continue debugging with last successful binaries.
)

exit /b 0

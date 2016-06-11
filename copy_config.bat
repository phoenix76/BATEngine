@echo off
echo "------------------------------------------------------------"
xcopy config.xml Bat_run_debug\x86
xcopy config.xml Bat_run_debug\x64
echo "------------------------------------------------------------"
pause
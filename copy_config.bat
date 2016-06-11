@echo off
echo "------------------------------------------------------------"
xcopy config.xml Bat_run_debug\86x
xcopy config.xml Bat_run_debug\64x
echo "------------------------------------------------------------"
pause
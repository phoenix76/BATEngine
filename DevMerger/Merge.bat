@echo off
echo "------------------------------------------------------------"
DeveloperMerger.exe
echo "------------------------------------------------------------"
xcopy "developers\temp\Engine.vcxproj" "..\Engine\Engine\Engine.vcxproj"
xcopy "developers\temp\Engine.vcxproj.filters" "..\Engine\Engine\Engine.vcxproj.filters"
pause
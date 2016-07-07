@echo off
echo "------------------------------------------------------------"
xcopy "..\Engine\Engine\Engine.vcxproj" "developers\dev1\Engine.vcxproj.xml"
xcopy "..\Engine\Engine\Engine.vcxproj.filters" "developers\dev1\Engine.vcxproj.filters.xml"
pause
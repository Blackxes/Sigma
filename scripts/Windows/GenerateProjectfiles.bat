:: Cleanup project before creating them just in case
call CleanProject.bat

:: Actual project file generation
cd ..\..\
call vendor\premake\premake5.exe vs2022

echo "Open up the SigmaSolution.sln and build Sandbox."
echo "After that enjoy :D"
pause
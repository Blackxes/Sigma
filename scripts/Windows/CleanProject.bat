cd ..\..\
rmdir /s /q bin
rmdir /s /q bin-int
Get-ChildItem -Recurse | Where{$_.Name -Match "build"} | Remove-Item
rmdir /s /q **\CMake
del /s *.sln
del /s *.vcxproj
del /s *.vcxproj.filters
del /s *.vcxproj.user
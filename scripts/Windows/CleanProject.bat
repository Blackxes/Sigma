cd ..\..\


:: Long live chatgpt
::
:: === List of directory names to delete ===
set dirs_to_delete=bin bin-int build

:: Loop through each directory name
for %%d in (%dirs_to_delete%) do (
    echo Looking for directories named "%%d"...
    
    :: Recursively find and delete each match under current directory
    for /d /r %%x in (%%d) do (
        if exist "%%x" (
            echo Deleting: %%x
            rd /s /q "%%x"
        )
    )
)

del /s /q *.sln
del /s /q *.vcxproj
del /s /q *.vcxproj.filters
del /s /q *.vcxproj.user

pause
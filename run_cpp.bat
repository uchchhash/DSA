@echo off

:: Check if a filename was provided
if "%~1"=="" (
    echo Usage: %0 filename.cpp
    exit /b 1
)

:: Get the filename without extension
set filename=%~n1

:: Compile the C++ file
g++ -o "%filename%" "%~1"

:: Check if compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b 1
)

:: Run the executable
"%filename%"

@echo off

set source="%cd%\_site\*"
for %%a in ("%~dp0..") do set parent=%%~fa
set target="%parent%\clone\pyaston.github.io"

:main
set /p command=^>
if "%command%"=="s" call :start
if "%command%"=="b" call :build
if "%command%"=="a" explorer %~dp0
if "%command%"=="c" explorer %target%
goto main


:start
rem Start jekyll serve
rem bundle exec jekyll clean
call bundle exec jekyll serve --trace
goto main


:build
rem Build jekyll serve
call bundle exec jekyll build
xcopy /E /H /Y %source% %target%
goto main
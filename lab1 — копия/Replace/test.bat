rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM=%~1

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err
echo Test 1 passed

rem При запуске с правильными параметрами ожидается нулевой код возврата 
%PROGRAM% test-data\input1.txt "%TEMP%\output.txt" replace ""
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" test-data\output_empty_string.txt 
if ERRORLEVEL 1 goto err
echo Test 2 passed

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% test-data\input.txt "%TEMP%\output.txt" 3 4
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" test-data\output.txt 
if ERRORLEVEL 1 goto err
echo Test 3 passed

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% test-data\input.txt "%TEMP%\output.txt" 4 2
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" test-data\output_cant_find_string.txt 
if ERRORLEVEL 1 goto err
echo Test 4 passed

echo OK
exit /b 0

:err
echo Program testing failed
exit /b 1

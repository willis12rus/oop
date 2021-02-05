rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err
echo Test 1 passed

rem При запуске с неверными параметрами ожидается ненулевой код возврата
%PROGRAM% f > nul
if  ERRORLEVEL 1 goto err
echo Test 2 passed

rem При запуске с неверными параметрами ожидается ненулевой код возврата
%PROGRAM% 500 > nul
if  ERRORLEVEL 1 goto err
echo Test 3 passed

rem При запуске с неверными параметрами ожидается ненулевой код возврата
%PROGRAM% -500 > nul
if  ERRORLEVEL 1 goto err
echo Test 4 passed

rem При запуске с правильными параметрами ожидается нулевой код возврата 
%PROGRAM% 0 > "%TEMP%\output.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" test-data\output0.txt 
if ERRORLEVEL 1 goto err
echo Test 5 passed

rem При запуске с правильными параметрами ожидается нулевой код возврата 
%PROGRAM% 255 > "%TEMP%\output.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" test-data\output255.txt 
if ERRORLEVEL 1 goto err
echo Test 6 passed

rem При запуске с правильными параметрами ожидается нулевой код возврата 
%PROGRAM% 12 > "%TEMP%\output.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" test-data\output12.txt 
if ERRORLEVEL 1 goto err
echo Test 7 passed


echo OK
exit /b 0

:err
echo Program testing failed
exit /b 1

@call debug
if "%include_get_filename%" == "true" goto :eof
set include_get_filename=true
set filepath=%1
set filepath=%filepath:\"=%
set filepath=%filepath:"=%
set filename= 
:no2
if not "%filepath:~-1%" equ "\" (
     set filename=%filepath:~-1%%filename%&set filepath=%filepath:~0,-1%&goto no2
)
set filename=%filename:~0,-5%
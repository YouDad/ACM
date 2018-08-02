@call debug
if "%include_set_path%" == "true" goto :eof
set include_set_path=true
set path=%path%;%cd%;%cd%\EXE;%cd%\SRC;%cd%\bin\;
set acm_path=%cd%
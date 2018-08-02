@call debug
call set_path.bat
call get_filename.bat "%~1"
cd SRC
echo 开始编译%filename%.cpp
g++ %filename%.cpp -o %filename%.exe -ggdb3 -O0
echo 编译完成,开始移动
move /Y %filename%.exe %acm_path%\EXE\%filename%.exe > nul
echo 移动完成
@call debug
call set_path.bat
call get_filename.bat "%~1"
cd SRC
echo ��ʼ����%filename%.cpp
g++ %filename%.cpp -o %filename%.exe -ggdb3 -O0
echo �������,��ʼ�ƶ�
move /Y %filename%.exe %acm_path%\EXE\%filename%.exe > nul
echo �ƶ����
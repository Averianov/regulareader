@echo off
REM Скрипт сборки для компиляции regula.cpp в статическую библиотеку
ECHO Компиляция regula.cpp...

REM Используем mingw для компиляции
g++ -std=c++11 -c ./source/regula.cpp -o ./source/regula.o

REM Создаем статическую библиотеку
ar rcs ./source/libregula.a ./source/regula.o

ECHO Сборка завершена! 
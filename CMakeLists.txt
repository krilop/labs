cmake_minimum_required(VERSION 3.23)
project(LW1_task2 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab1.1 lab1/task1/main.c)
add_executable(lab1.3 lab1/task3/main.c)
add_executable(lab1.2 lab1/task2/main.c)
add_executable(lab1.4 lab1/task4/main.c)

add_executable(lab2.3 lab2/task3/main.c)
add_executable(lab2.2 lab2/task2/main.c)
add_executable(lab2.1 lab2/task1/main.c)

add_executable(lab3.3 lab3/task3/main.c)
add_executable(lab3.2 lab3/task2/main.c)
add_executable(lab3.1 lab3/task1/main.c)

add_executable(lab4.3 lab4/task3/main.c lab4/task3/functions.c lab4/task3/header.h)
add_executable(lab4.2 lab4/task2/main.c lab4/task2/functions.c lab4/task2/header.h)
add_executable(lab4.1 lab4/task1/main.c lab4/task1/functions.c lab4/task1/header.h)

add_executable(lab5.3 lab5/task3/main.c lab5/task3/functions.c lab5/task3/header.h)
add_executable(lab5.2 lab5/task2/main.c lab5/task2/functions.c lab5/task2/header.h)
add_executable(lab5.1 lab5/task1/main.c lab5/task1/functions.c lab5/task1/header.h)

add_executable(lab6.2 lab6/task2/main.c lab6/task2/functions.c lab6/task2/header.h)
add_executable(lab6.1 lab6/task1/main.c lab6/task1/functions.c lab6/task1/header.h)

add_executable(lab7 lab7/main.c lab7/functions.c lab7/header.h)

add_executable(lab8 lab8/main.c lab8/functions.c lab8/header.h)

cmake_minimum_required(VERSION 3.23)
project(LW1_task2 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab1.1 term1/lab1/task1/main.c)
add_executable(lab1.3 term1/lab1/task3/main.c)
add_executable(lab1.2 term1/lab1/task2/main.c)
add_executable(lab1.4 term1/lab1/task4/main.c)

add_executable(lab2.3 term1/lab2/task3/main.c)
add_executable(lab2.2 term1/lab2/task2/main.c)
add_executable(lab2.1 term1/lab2/task1/main.c)

add_executable(lab3.3 term1/lab3/task3/main.c)
add_executable(lab3.2 term1/lab3/task2/main.c)
add_executable(lab3.1 term1/lab3/task1/main.c)

add_executable(lab4.3 term1/lab4/task3/main.c term1/lab4/task3/functions.c term1/lab4/task3/header.h)
add_executable(lab4.2 term1/lab4/task2/main.c term1/lab4/task2/functions.c term1/lab4/task2/header.h)
add_executable(lab4.1 term1/lab4/task1/main.c term1/lab4/task1/functions.c term1/lab4/task1/header.h)

add_executable(lab5.3 term1/lab5/task3/main.c term1/lab5/task3/functions.c term1/lab5/task3/header.h)
add_executable(lab5.2 term1/lab5/task2/main.c term1/lab5/task2/functions.c term1/lab5/task2/header.h)
add_executable(lab5.1 term1/lab5/task1/main.c term1/lab5/task1/functions.c term1/lab5/task1/header.h)

add_executable(lab6.2 term1/lab6/task2/main.c term1/lab6/task2/functions.c term1/lab6/task2/header.h)
add_executable(lab6.1 term1/lab6/task1/main.c term1/lab6/task1/functions.c term1/lab6/task1/header.h)

add_executable(lab7 term1/lab7/main.c term1/lab7/functions.c term1/lab7/header.h)

add_executable(lab8 term1/lab8/main.c term1/lab8/functions.c term1/lab8/header.h)

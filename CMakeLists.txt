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

#add_executable(parsing term2/lab1/main.c term2/lab1/functions.c term2/lab1/functions.h term2/lab1/sorts.c term2/lab1/sorts.h term2/lab1/basket.txt)

add_executable(compress term2/lab2/compress.c term2/lab2/functionsForCompressing.c term2/lab2/functionsForCompressing.h term2/lab2/file/book.txt)
add_executable(decompress term2/lab2/decompress.c term2/lab2/functionsForDecompressing.c term2/lab2/functionsForDecompressing.h term2/lab2/file/book.txt)

add_executable(bmpEditor term2/lab3/main.c term2/lab3/functions.h term2/lab3/functions.c)

add_executable(acinatorGame term2/lab4/main.c term2/lab4/functions.h term2/lab4/functions.c term2/lab4/binarytree.c term2/lab4/binarytree.h)

add_executable(hashNcache term2/lab5/main.c term2/lab5/functions.c term2/lab5/functions.h term2/lab5/cache.c term2/lab5/cache.h)

#target_link_libraries(bmpEditor m)

# Лабораторные работы ОАИП
### ![](https://i.ibb.co/6WJd2wN/extrasign.png) **Данный код не является образцовым. Прикрепляю ссылку на [анализатор кода.](https://sonarcloud.io/project/overview?id=krilop_labs)**
**Если вы хотите связаться с автором, ссылки в профиле вам в этом помогут.**
## Содержание
### Первый семестр: 
1. **[Лабораторная 1](#лабораторная-1)**
2. **[Лабораторная 2](#лабораторная-2)**
3. **[Лабораторная 3](#лабораторная-3)**
4. **[Лабораторная 4](#лабораторная-4)**
6. **[Лабораторная 5](#лабораторная-5)**
6. **[Лабораторная 6](#лабораторная-6)**
7. **[Лабораторная 7](#лабораторная-7)**
8. **[Лабораторная 8](#лабораторная-8)**
### Второй семестр:
1. **[Лабораторная 1](#лабораторная-1)**
## Лабораторная 1

**[Задача 1](https://github.com/krilop/labs/tree/master/term1/lab1/task1.c)**. Вввести длины ребер куба. Найти объем куба и площадь его боковой поверхности. Результат вывести с точностью до трех знаков после запятой.\
**[Задача 2](https://github.com/krilop/labs/tree/master/term1/lab1/task2.c)**. Определить, имеется ли среди целых чисел a, b и c хотя бы одно чётное.\
**[Задача 3](https://github.com/krilop/labs/tree/master/term1/lab1/task3.c)**. Составьте алгоритм решения неравенства ax2+bx+c<0.\
**[Задача 4](https://github.com/krilop/labs/tree/master/term1/lab1/task4.c)**. Для натурального числа К напечатать фразу "мы нашли К грибов в лесу", согласовав окончание слова "гриб" с числом К.

## Лабораторная 2

**[Задача 1](https://github.com/krilop/labs/tree/master/term1/lab2/task1.c)**. Дано натуральное число n. Выяснить, можно ли представить n! в виде произведения трёх последовательных целых чисел.\
**[Задача 2](https://github.com/krilop/labs/tree/master/term1/lab2/task2.c)**. Дана последовательность, каждый член которой равен его порядковому номеру в последовательности, возведенному в куб. Номера её первого и последнего членов - 1 и n соответственно.  Найдите сумму S и произведение P тех её членов, номера  которых являются:
а) нечетными
б) четными\
**[Задача 3](https://github.com/krilop/labs/tree/master/term1/lab2/task3.c)**. Дано число Х в градусах. Найти значение sinX используя разложение в ряд Тейлора

## Лабораторная 3

#### Доп. условия:

* Во всех заданиях использовать статические массивы.
Сначала выделить место на 100 элементов, а потом использовать столько, сколько скажет пользователь.
* Предусмотреть ввод с клавиатуры и инициализацию массива случайными значениями (по желанию пользователя).
* При вводе чисел обязательно выводить приглашающие строки, а также выполнять проверку на корректность ввода;
* избегать названий переменных, не отражающих своей сути, например, а, nn, s и т.п. Исключение - счетные переменные в циклах i. 
* Для индексации лучше использовать col (столбец) и row (строка).\

**[Задача 1](https://github.com/krilop/labs/tree/master/term1/lab3/task1.c)**. В одномерном массиве, состоящем из n вещественных элементов, вычислить:
- количество элементов массива, равных 0;
- сумму элементов массива, расположенных после минимального элемента.

**[Задача 2](https://github.com/krilop/labs/tree/master/term1/lab3/task2.c)**. В массиве из n элементов циклически сдвинуть все четные элементы на k влево. Нечетные оставить на своих местах.\
**[Задача 3](https://github.com/krilop/labs/tree/master/term1/lab3/task3.c)**. Для арифметических операций с большими числами, которые не могут быть представлены в памяти компьютера, используется следующий прием. Каждая цифра таких чисел записывается в отдельный элемент массива, и необходимые операции проводятся с элементами массива цифр. Составить программу, выполняющую сложение 30-значных чисел.

## Лабораторная 4

#### Доп. условия:

* Во всех заданиях использовать статические массивы.
  Сначала выделить место на 100х100 элементов, а потом использовать столько, сколько скажет пользователь.
* Предусмотреть ввод с клавиатуры и инициализацию массива случайными значениями (по желанию пользователя).
* При вводе чисел обязательно выводить приглашающие строки, а также выполнять проверку на корректность ввода;
* избегать названий переменных, не отражающих своей сути, например, а, nn, s и т.п. Исключение - счетные переменные в циклах i.
* Для индексации лучше использовать col (столбец) и row (строка).\

**[Задача 1](https://github.com/krilop/labs/tree/master/term1/lab4/task1.c)**. Дана целочисленная квадратная матрица. Определить: 
* Сумму элементов в тех столбцах, которые не содержат отрицательных элементов;
* Минимум среди сумм модулей элементов диагоналей, параллельных побочной диагонали матрицы.

**[Задача 2](https://github.com/krilop/labs/tree/master/term1/lab4/task2.c)**. Найти в матрице первый столбец, все элементы которого равны нулю. Знаки элементов строки с таким же номером изменить на противоположные.\
**[Задача 3](https://github.com/krilop/labs/tree/master/term1/lab4/task3.c)**. В квадратной матрице размером NxN найти минмальный четный элемент в 3-ой области(см. рис. 1)\
\
![](https://i.ibb.co/nsLyw5b/image.png)\
 **Рисунок 1**

## Лабораторная 5
#### Доп. условия:
* В случае невозможности выполнения операции, неверных аргументов, не нахождения элементов - выводить соответствующие сообщения на экран. 
* Ни одна функция не должна превышать размера в 40-50 строк. Исключение может составить только функция main при условии аккуратной организации и хорошей читаемости. 
* Функции для работы с массивом не должны ничего выводить на экран. Исключение - функция для просмотра массива. Поэтому любые сообщения должны выводиться на экран в функциях более высокого уровня, которые отвечают за интерфейс пользователя (например, функция main). 
* Функции для работы с массивом/матрицей должны быть вынесены в отдельные файлы исходного кода arrays.h и arrays.c. В файле с main библиотека включается с помощью директивы #include ""
* Во всех заданиях использовать динамическое выделение памяти. Желательно делать все функции типа void.

**[Задача 1](https://github.com/krilop/labs/tree/master/term1/lab5/task1.c)**. Заполнить массив случайными числами. Удалить из массива все элементы с чётным значением.\
**[Задача 2](https://github.com/krilop/labs/tree/master/term1/lab5/task2.c)**. В двумерном массиве натуральных чисел (количество чисел в строке может быть различным, последнее число - 0) удалить строку с минимальной суммой элементов (порядок остальных строк не менять).\
**[Задача 3](https://github.com/krilop/labs/tree/master/term1/lab5/task3.c)**. Дан двумерный массив ненулевых целых чисел. Определить максимально длинную последовательность положительных чисел. Массив просматривается построчно сверху вниз, а в каждой строке - слева направо. Сохранение знака при переходе на новую строку также учитывать.
## Лабораторная 6
#### Доп. условия:
* Все сортировки оформлять через функции.
* Во второй задаче использовать дополнительные массивы запрещено.
* Если не указан конкретный тип сортировки, он остается на выбор программиста.
* Во всех заданиях использовать динамическое выделение памяти.
* Желательно делать все функции типа void.
* Для 1-й задачи необходимо замерить время выполнения сортировки в секундах и/или миллисекундах (проверять будем на больших размерах массива – 1000, 10000).
* Провести сравнение времени сортировки с другим способом на ваш выбор, например, пузырьком.
* Рассмотреть “худший” случай (массив отсортирован в обратном порядке).

**[Задача 1](https://github.com/krilop/labs/tree/master/term1/lab6/task1.c)**. В одномерном массиве выполнить сортировку элементов расположенных после первого положительного. Методом Шелла.\
**[Задача 2](https://github.com/krilop/labs/tree/master/term1/lab6/task2.c)**. В матрице размером NxM выполнить сортировку строк по возрастанию произведения отрицательных элементов методом слияния.(Работает, но ожидается обновление)

## Лабораторная 7
#### Доп. условия:
* Во всех заданиях использовать динамическое выделение памяти.
* Во всех задачах разрабатывать свои функции для работы со строками.(string.h запрещена) 
* Желательно использовать указатели на функции для каждого задания.
* Необходимо создать Меню для выбора пользователем задачи 1 или 2, обращение к которым реализовать через указатель на функцию.

**[Задача 1](https://github.com/krilop/labs/tree/master/term1/lab7/main.c)**. Дана строка. Найти сумму чисел в строке.\
**[Задача 2](https://github.com/krilop/labs/tree/master/term1/lab7/main.c)**. Даны строки S, S0 и числа k, m. Вставить c k-ой позиции строки S первые k символов из строки S0

## Лабораторная 8
#### Доп. условия:
* Во всех заданиях использовать динамическое выделение памяти.
* Во всех задачах разрабатывать свои функции для работы со строками.(string.h запрещена)
* Желательно использовать указатели на функции для каждого задания.
* Организовать ввод массива строк через аргументы командной строки (int main(int argc, char **argv){…}). После этого скопировать строки из командной строки в динамический массив и отсортировать его заданным методом.

**[Задача 1](https://github.com/krilop/labs/tree/master/term1/lab8/main.c)**. Отсортировать методом слияния массив строк по убыванию длины строки.(Работает, но ожидается обновление)
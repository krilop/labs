#include<stdio.h>

int main()
{
    float side;
    float volume;
    float square;
    printf("input num:");
    while (scanf_s("%f", &side) == 1 && side >= 0 || getchar() != '\n') {
        printf("Uncorrect input");
        rewind(stdin);
    }
    volume = side * side * side;
    square = side * side * 4;
    printf("Volume of cube with side %f = %.4f\n", side, volume);
    printf("Side surface area of a cube with side %f = %.4f\n", side, square);
    return 0;
}
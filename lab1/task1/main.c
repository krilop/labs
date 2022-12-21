#include<stdio.h>
int main() {
    float side, volume, square;
    printf("input num:");
    
    if (scanf_s("%f", &side)==1 && side >= 0)
    {
        volume = side * side * side;
        square = side * side * 4;
        printf("Volume of cube with side %f = %.4f\n", side, volume);
        printf("Side surface area of a cube with side %f = %.4f\n", side, square);
    }
    else printf("Uncorrect input");
    return 0;
}
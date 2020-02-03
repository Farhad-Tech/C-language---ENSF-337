// lab4exA.c

// ENSF 337 Fall 2018 Lab 4 Exercise A

#include <stdio.h>

int main(void)
{
    int i;
    int a[ ] = { 1000, 1200, 300, 1400, 1500, 30 };
    int *z;

    *a = 99;
    *(a + 2) = 55;

    a[1] = 11;

    z = a + 2;
    printf("*z %d\n", *z);


    i = 2;

    *(z-1) = *(z-i) + z[0];

    z[1] = *z * i;



    *(z+2) = *(&a[2] - i);



    z + 3;

    z[3] = -9;

    for (int i = 0; i<(sizeof(a)/sizeof(a[0])); i++){
      printf("%d\n", a[i]);
    }

    i = a - &a[6];

    printf("i %d\n", i);

    // point one

    return 0;
}

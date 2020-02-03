/*
 *
 * lab2exe_B1.c
 * ENSF 337 - Lab 2 - Execise B1
 */

#include <stdio.h>

void foo(int *a, int *b);

int main(void)
{
  int x = 1000;
  int y = 2000;
  int *p;
  p = &y; //y=2000
  foo(p, &x); //2000,1000
  printf("x is %d, y is %d.\n", x, y);
  return 0;
}

void foo(int *a, int *b)//2000,1000
{
  *a += 10;//2010
  *b += 20;//1020

  /* point one */

  *b += 1;
}

/*
 *
 * lab2exe_B2.c
 * ENSF 337 - Lab 2 - Execise B2
 */

#include <stdio.h>

void bar(int *a, int *b);

void quux(int *p, int *q);

int main(void)
{
  int x = 500, y = 600;
  quux(&x, &y);//500,600
  printf("x is %d, y is %d.\n", x, y);
  return 0;
}

void bar(int *a, int *b)//500,600
{
  *a += 3;//503
  *b += 4;//604

  /* point one */

  printf("*a is %d, *b is %d.\n", *a, *b);
}

void quux(int *p, int *q)//500,600
{
  int n;
  n = *p;//500
  bar(&n, q);//500,600
  printf("*p is %d, *q is %d.\n", *p, *q);
}

/* prog_one.c
 * ENSF 337 Fall 2018 Lab 4 Exercise  E
 *
 */

#include <stdio.h>
#include <limits.h>
#include "read_input.h"

#define SIZE 50

int main(void)
{
  double n = 0;
  char digits[SIZE];

  int y = EOF;

  while (1)
    {
      printf("\n\nEnter a REAL number or press Ctrl-D to quit: ");
      y = read_real(digits, SIZE, &n);

      if(y == 1)
	printf("\nYour REAL value is: %lf", n);
      else if(y == EOF){
	printf("\nGood Bye.\n");
	break;
      }
      else
	printf("\n%s is an invalid.", digits);
    }

  return 0;
}

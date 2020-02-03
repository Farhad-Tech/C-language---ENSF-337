/* read_int.c
 * ENSF 337 Fall 2018 Lab 4 Exercise  E
 *
 * Author:   M. Moussavi
 */

#include "read_input.h"

int read_real(char* digits, int n, double * num)
{
  if(get_string(digits, n)== EOF)
    return EOF;

  if(is_valid_double(digits)){
    if(digits[0] == '-')
      *num = -convert_to_double(digits + 1);
    else if(digits[0] == '+')
      *num = convert_to_double(digits + 1);
    else
      *num = convert_to_double(digits);
    return 1;
  }

  return 0;
}

int is_valid_double(const char* digits){
  int valid = 1;
  int i;
  int dots = 0;

  /* i = index where first digit should be */
  if(digits[0] == '+' || digits[0] == '-')
    i = 1;
  else
    i = 0;

  /* Must have at least one digit, and no non-digits. */
  if (digits[i] == '\0')
    valid = 0;
  else
    while (valid && (digits[i] != '\0')) {
      if(digits[i] < '0' ||  digits[i] > '9')
        valid = 0;
      if(digits[i] == '.'){ // If it has 1 dot, then valid
        valid = 1;
        dots ++;
      }
      if(dots > 1) // If it has more that 1 dot, then not valid
        valid = 0;
      i++;
    }

  return valid;
}

double convert_to_double(const char *digits){

  double sum = 0;
  int i = 0;
  int d = 1;
  while(digits[i] != '\0') {
    if (digits[i] == '.'){ // If it notices '.' it skips it to the next value
      i++;
      while(digits[i] != '\0') { // Now we focus on fractional part
        sum = sum + ((double)digits[i] - '0')/(pow(10, d)); // Add decimal parts until it reaches '/0'
        i++;
        d++;
      }
      return sum; // returns sum if it has decimal parts
    }
    sum = 10 * sum + (digits[i] - '0');
    i++;
  }

  return sum; // returns sum if it doesn't have decimal parts
}

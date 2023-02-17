#include <stdlib.h>
#include <time.h>
// #include <stdio.h>
/* more headers go here */

/*
 * main - Entry point
 *
 * Return: print whether an integer stored in a \
variable is positive or negative
*/
int main(void)
{
  int n;

  srand(time(0));
  n = rand() - RAND_MAX / 2;
  // if (n == 0)
  // {
  // printf("%d is zero\n", n);
  // }
  // else if (n > 0)
  // {
  // printf("%d is positive\n", n);
  // }
  // else
  // {
  // printf("%d is negative\n", n);
  // }

  if (n > 0)
  {
    write(1, "is positive\n", 12);
  }
  else if (n == 0)
  {
    write(1, "is zero\n", 8);
  }
  else
  {
    write(1, "is negative\n", 12);
  }
  return (0);
}

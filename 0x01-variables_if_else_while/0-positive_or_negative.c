#include <stdlib.h>
#include <time.h>
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
  if (n == 0)
  {
    printf("%d is zero\n", n);
  }
  else if (n > 0)
  {
    printf("%d is positive\n", n);
  }
  else
  {
    printf("%d is negative\n", n);
  }
  return (0);
}

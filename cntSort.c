/*
 * implementation of counting sort
 *
 * project: hw5
 * name: Daniel Duff 
 * user??
 * date: 07/15/19
 * file: cntSort.c
 * pseudo code: First, I declared my variables, i for my for loops, and an unsigned array called sorted which is where I first put the sorted output before copying it back over to the original data array.  My first for loop then stores the count of each character in its associated array index in the array count.  The next for loop then changes the count array so it will contain the correct position of that character in the array.  The third for loop creates the sorted array based on the numbers held in the count array. and then the last loop copies over the sorted array to the data array for testing in the main.c driver as well as prints the now sorted data array.
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>

void cntSort(unsigned m, unsigned n, unsigned data[])
{
  unsigned *count;
  unsigned sorted[n];
  int i;
  
  /* allocate memory */
  count = (unsigned *)malloc(sizeof(unsigned) * m);

  for (i = 0; i < n; ++i) {
    count[data[i]] += 1;
  }

  for (i = 1; i <= m; ++i) {
    count[i] += count[i - 1];
  }
  
  for (i = 0; i < n; ++i) {
    sorted[count[data[i]] - 1] = data[i];
    --count[data[i]];
  }

  for (i = 0; i < n; ++i) {
    data[i] = sorted[i];
    printf("%u ", data[i]);
  }

  printf("\n");

  /* free up memory */
  free(count);
}


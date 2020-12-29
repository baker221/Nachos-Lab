/* sort.c
 *    Test program to sort a large number of integers.
 *
 *    Intention is to stress virtual memory system.
 *
 *    Ideally, we could read the unsorted array off of the file system,
 *	and store the result back to the file system!
 */

#include "syscall.h"

const int size = 20;

int main() {
  int A[size];

  int i, j, tmp;

  /* first initialize the array, in reverse sorted order */
  for (i = 0; i < size; i++)
    A[i] = size - i - 1;

  /* then sort! */
  for (i = 0; i < size - 1; i++)
    for (j = 0; j < (size - 1 - i); j++)
      if (A[j] > A[j + 1]) { /* out of order -> need to swap ! */
        tmp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = tmp;
      }
  Exit(A[0]); /* and then we're done -- should be 0! */
}

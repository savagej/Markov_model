#include <iostream>
#include <stdlib.h>
#include "read_write.h"

int numrow = 256;

int main() {
  Arrays* mat = load_matrix("distances.txt", numrow, numrow+1, 1);
  double ** output = mat->two_dim;

  for (int ii = 0; ii < numrow; ii++) {
    for (int jj = 0; jj < numrow; jj++) {
      printf ("%g",output[ii][jj]);
    }
    printf("\n");
  }
  //free(mat);
  return 0;
}



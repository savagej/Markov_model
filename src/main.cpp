#include <iostream>
#include <stdlib.h>
#include "read_write.h"

int numrow = 256;

int main() {
  double** mat = load_matrix("distances.txt", numrow, numrow+1, 1);

  double array[numrow][numrow];
  double oxygens[numrow];
  for (int ii = 0; ii < numrow; ii++) {
    oxygens[ii] = mat[ii][0];    
    for (int jj = 1; jj < numrow+1; jj++) {
      array[ii][jj-1] = mat[ii][jj];
    }
    printf("\n");
  }
  free(mat);
  return 0;
}



#include <iostream>
#include <stdlib.h>
#include "read_write.h"
#include "run_markov.h"

int numrow = 256;
int times = 10000;

int main(int argc, char *argv[]) {
  Arrays* distances = load_matrix(argv[1], numrow, numrow+1, 1);
  Arrays* adjacencies = load_matrix(argv[2], numrow, numrow+1, 1);

  double **distance = distances->two_dim;
  double **adjacancy = adjacencies->two_dim;

  for (int ii = 0; ii < times; ii++) {
    fprintf(stderr,"%d\r",ii);
    run_markov(distance,adjacancy, numrow, numrow);
    print_matrix(argv[3], numrow, numrow, ii, adjacancy);
  }

  free(distances);
  free(adjacencies);
  return 0;
}



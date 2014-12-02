#include <iostream>
#include <stdlib.h>
#include "read_write.h"
#include "run_markov.h"

int numrow = 256;
int times = 10000;
int equil = 1000;

int main(int argc, char *argv[]) {
  Arrays* distances = load_matrix(argv[1], numrow, numrow+1, 1);
  Arrays* adjacencies = load_matrix(argv[2], numrow, numrow, 0);

  double **distance = distances->two_dim;
  double **adjacancy = adjacencies->two_dim;
  print_header(argv[3],numrow,distances->oxygens);

  for (int tt = 0; tt < equil; tt++) {
    fprintf(stderr,"equil_time %d\n",tt);
    run_markov(distance,adjacancy, numrow, numrow);
  }

  for (int tt = 0; tt < times; tt++) {
    fprintf(stderr,"time %d\n",tt);
    run_markov(distance,adjacancy, numrow, numrow);
    print_matrix(argv[3], numrow, numrow, tt, adjacancy);
  }

  free(distances);
  free(adjacencies);
  return 0;
}



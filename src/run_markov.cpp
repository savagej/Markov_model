#include <iostream>
#include <stdlib.h>
#include <math.h> 
#include "run_markov.h"

using namespace std;

void run_markov(double** dist,double** adj,unsigned int nrow, unsigned int ncol) {
  for (int ii = 0; ii < nrow; ii++) {
    for (int jj = ii+1; jj < ncol; jj++) {
      if (adj[ii][jj] != 0) {
        double prob[ncol];
        double total_prob = 0;
        for (int kk = 0; kk < ncol; kk++) {
          if (kk == jj) {
            prob[kk] = exp(-dist[ii][kk]);
            total_prob += prob[kk];
          } else if (adj[ii][kk] != 0) {
            prob[kk] = exp(-dist[ii][kk]);
            total_prob += prob[kk];
          } else {
            prob[kk] = 0;
          }
        }
        double choice = (double) rand() /RAND_MAX * total_prob;
        total_prob = 0;
        int kk = 0;
        while (total_prob < choice) {
          total_prob += prob[kk];
          kk ++;
        }
        double buffer = adj[ii][jj];
        adj[ii][jj] = 0;
        adj[ii][kk] = buffer;
      }
    }
  }
}

#include <iostream>
#include <stdlib.h>
#include <math.h> 
#include "run_markov.h"

using namespace std;

void run_markov(double** dist,double** adj,unsigned int nrow, unsigned int ncol) {
  int switches = 0;
  for (int ii = 0; ii < nrow; ii++) {
    for (int jj = ii+1; jj < ncol; jj++) {
      if (adj[ii][jj] != 0) { // If a h-bond exists
        double prob[ncol];
        double total_prob = 0;
        for (int kk = 0; kk < ncol; kk++) {  // find the probability of each neighboring bond
          if (ii == kk) { // skip diagonal
            prob[kk] = 0;
          } else if (kk == jj) { //if 
            prob[kk] = probability(dist[ii][kk]);
            total_prob += prob[kk];
          } else if (adj[ii][kk] == 0) {
            if (dist[ii][kk] < 3.5) {
              prob[kk] = probability(dist[ii][kk]);
              //cerr << ii << " " << jj << " " << kk << " " << prob[kk] << " probability : dist " << dist[ii][kk] << " adj " << adj[ii][kk] <<"\n";
              total_prob += prob[kk];
            } else {
              prob[kk] = 0;
            }
          } else {
            prob[kk] = 0;
          }
        }
        if (total_prob == 0) 
          continue;
        double choice = (double) rand() /RAND_MAX * total_prob;
        int kk = 0;
        total_prob = prob[0];
        while (total_prob < choice) {
          kk ++;
          total_prob += prob[kk];
        }
        if (kk == ii) 
          cerr << "problem \n";
        if (kk != jj) {
          //cerr << kk << " to " << jj << " changed: " << dist[ii][kk] << " " << dist[ii][jj] << "probs:: " << choice << " " << total_prob <<"\n";
          switches++;
          adj[ii][kk] = adj[ii][jj];
          adj[kk][ii] = -adj[ii][jj];
          adj[ii][jj] = 0;
          adj[jj][ii] = 0;
        }
      }
    }
  }
  cerr << switches << "\n";
}

double probability (double distance) {
  return exp(-distance);
  //return (-distance);
}

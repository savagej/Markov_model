#include <iostream>
#include <fstream>
//#include <stdlib.h>
#include "read_write.h"

using namespace std;

Arrays* load_matrix(char* filename, unsigned int nrow, unsigned int ncol, unsigned int get_oxygens) {

  FILE *mfile;
  mfile = fopen(filename, "r");
  if(mfile != NULL) {

    int c;
    unsigned int i, j;

    for(i = 0; i < 1; i++) { // skip header
      while((c = getc(mfile)) != '\n' && c != EOF);
    }

    double **matrix =  (double**) malloc(sizeof(double*) * nrow);
    for (int ii = 0; ii < nrow; ii++) {
      matrix[ii] = (double*) malloc(sizeof(double) * ncol);
    }

    if(matrix == NULL) {
      perror("Out of memory\n");
      exit(1);
    }

    for(i = 0; i < nrow; i++) {
      for(j = 0; j < ncol; j++) {
        if(fscanf(mfile, "%lg", &(matrix[i][j])) == 0) {
          fprintf(stderr, "Incorrect number of rows or columns"
                  "at i = %d, and j=%d, nrow=%d, ncol=%d\n", i, j, nrow, ncol);
          exit(1);
        }
      }  
    }

    fclose(mfile);
    Arrays* test = (Arrays*) malloc(sizeof(Arrays));
    if (get_oxygens == 1) {
      double **array =  (double**) malloc(sizeof(double*) * nrow);
      for (int ii = 0; ii < nrow; ii++) {
        array[ii] = (double*) malloc(sizeof(double) * ncol);
      }
      double *oxygens = (double*) malloc(sizeof(double) * ncol);
  
      for (int ii = 0; ii < nrow; ii++) {
        oxygens[ii] = matrix[ii][0];    
        for (int jj = 1; jj < nrow+1; jj++) {
          array[ii][jj-1] = matrix[ii][jj];
        }
      }
      test->oxygens = oxygens;
      test->two_dim = array;
    } else {
      test-> two_dim = matrix;
    }

    return test;
    
  }else {
    perror("Could not open file\n");
  }

  return NULL;

};

void print_matrix(char* filename, unsigned int nrow, unsigned int ncol, unsigned int time, double** matrix) {

  ofstream myfile;
  myfile.open (filename,ios::app);
  myfile << "TIMESTEP " << time << "\n";

  unsigned int i, j;
  for(i = 0; i < nrow; i++) {
    for(j = 0; j < ncol; j++) {
      myfile << matrix[i][j] << " ";
    }  
    myfile << "\n";
  }

  myfile.close();
}

void print_header(char* filename, unsigned int nrow, double* matrix) {
  ofstream myfile;
  myfile.open (filename,ios::out);
  myfile << "#oxygens ";

  unsigned int i;
  for(i = 0; i < nrow; i++) {
      myfile << matrix[i] << " ";
  }
  myfile << "\n";

  myfile.close();
}



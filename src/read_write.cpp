#include <iostream>
#include <stdlib.h>


double** load_matrix(char* filename, unsigned int nrow, unsigned int ncol, unsigned int skip) {

  FILE *mfile;
  mfile = fopen(filename, "r");
  if(mfile != NULL) {

    int c;
    unsigned int i, j;

    if(skip > 0) {
      for(i = 0; i < skip; i++) {
        while((c = getc(mfile)) != '\n' && c != EOF);
      }
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
    return matrix;
    
  }else {
    perror("Could not open file\n");
  }

  return NULL;

}


double** build_matrix(int nrow) {
  //double matrix[nrow][nrow];
  double** matrix;
  matrix = (double**) malloc(nrow*sizeof(double*));
  for (int ii = 0; ii < nrow; ii++) {
    matrix[ii] = (double*) malloc(nrow*sizeof(double));
  }
  for (int ii = 0; ii < nrow; ii++) {
    for (int jj = 0; jj < nrow; jj++) {
      matrix[ii][jj] = rand();
    }
  }
  return matrix;
}

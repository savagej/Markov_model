typedef struct {
  double *oxygens;
  double **two_dim;
} Arrays;
Arrays* load_matrix(char* filename, unsigned int nrow, unsigned int ncol, unsigned int skip);
void print_matrix(char* filename, unsigned int nrow, unsigned int ncol, unsigned int time, double** matrix);

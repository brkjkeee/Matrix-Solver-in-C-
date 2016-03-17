typedef struct {
	float **field;
	unsigned int volume;
	char *name;
}matrix;

void init_matrix(matrix &m);
void free_matrix(matrix &m);
void input_matrix(matrix &m);
void default_matrix(matrix &m);
void out_matrix(matrix &m);

//not realised functions

////need using another method, maybe swap by name
//void swap_matrix(float **m1, float **m2, int size);
//
//void multiply_number(float **m, int size, float num);
//
//void addtition_matrix(float **a, float **b, float **c, int size);
//
//void subtraction_matrix(float **a, float **b, float **c, int size);
//
////need reallocation, cose 2x3 does not transpose to 3x2
//void transposition_matrix(float **m, int size) ;
//
////need reallocation: row(a)xcol(b) = row&col(c). (1 1 1)x(1 1 1)t = (1)
//void multiply_matrix(float **a, float **b, float **c, int size);
//
////need debug
//float determinant_matrix(float **m, int size);
//
////only works with 3x3
//void inverse_matrix(matrix m);

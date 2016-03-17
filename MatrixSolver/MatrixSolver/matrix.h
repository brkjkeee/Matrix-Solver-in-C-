typedef struct {
	float **field;
	unsigned int volume;
	char name;
}matrix;

void init_matrix(matrix &m);
void free_matrix(matrix &m);
void input_matrix(matrix &m);
void default_matrix(matrix &m);
void out_matrix(matrix &m);

//not realised functions
//void swap_matrix(float **m1, float **m2, int size);
//void multiply_number(float **m, int size, float num);
//void addtition_matrix(float **a, float **b, float **c, int size);
//void subtraction_matrix(float **a, float **b, float **c, int size);
//void transposition_matrix(float **m, int size);
//void multiply_matrix(float **a, float **b, float **c, int size);
//float determinant_matrix(float **m, int size);
//void inverse_matrix(matrix m);
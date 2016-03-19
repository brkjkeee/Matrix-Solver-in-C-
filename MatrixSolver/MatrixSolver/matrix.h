typedef struct matrix {
	float **field;
	unsigned int volume;
	double det;
	char name;
};

void init_matrix(matrix &m);
void free_matrix(matrix &m);
void input_matrix(matrix &m);
void default_matrix(matrix &m);
void out_matrix(matrix &m);
void swap_matrix(matrix &m1, matrix &m2);
void multiply_number(matrix &m, float num);
void addtition_matrix(matrix &m1, matrix &m2, matrix &m3);
void subtraction_matrix(matrix &m1, matrix &m2, matrix &m3);
void transposition_matrix(matrix &m);
void multiply_matrix(matrix &m1, matrix &m2, matrix &m3);
double determinant_matrix(matrix &m);

//void inverse_matrix(matrix &m);
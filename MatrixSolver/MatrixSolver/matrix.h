typedef struct matrix {
	float **field;
	unsigned int volume;
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

//not realised functions

////need reallocation, cose 2x3 does not transpose to 3x2
//void transposition_matrix(matrix &m) ;
//
////need reallocation: row(a)xcol(b) = row&col(c). (1 1 1)x(1 1 1)t = (1)
//void multiply_matrix(matrix &m1, matrix &m2, matrix &m3);
//
////need debug
//float determinant_matrix(matrix &m);
//
////only works with 3x3
//void inverse_matrix(matrix &m);

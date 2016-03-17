#include <iostream>
#include <conio.h>
#include "matrix.h"
#define ESC 27
#define EOS '\n'

using namespace std;

void init_matrix(matrix &m) {
	m.field = (float**)malloc(sizeof(float*));
	m.field[0] = (float*)malloc(sizeof(float));
	m.volume = 0;
}

void free_matrix(matrix &m) {
	int stringNum = m.volume / _msize(m.field[0]);
	for (int i = 0; i < stringNum; i++)	free(m.field[i]);
	free(m.field);
}

void input_matrix(matrix &m) {
	free_matrix(m);
	init_matrix(m);
	int i = 0;
	cout << "Input matrix " << m.name << endl << endl;
	do {
		cout << "Enter " << i + 1 << " string of matrix " << m.name << ": ";
		do {
			cin >> m.field[i][_msize(m.field[i]) / sizeof(float) - 1];
			if (cin.rdbuf()->in_avail() != 1) m.field[i] = (float*)realloc(m.field[i], _msize(m.field[i]) + sizeof(float));
		} while (cin.get() != EOS);

		m.volume += _msize(m.field[i]);

		m.field = (float**)realloc(m.field, _msize(m.field) * sizeof(float*));
		m.field[i + 1] = (float*)malloc(sizeof(float));
		i++;
	} while (_getch() != ESC);
}

void default_matrix(matrix &m) {
	const int SIZE = 3;
	init_matrix(m);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			m.field[i] = (float*)realloc(m.field[i], _msize(m.field[i]) + sizeof(float));
		}
		m.volume += _msize(m.field[i]);
		m.field = (float**)realloc(m.field, _msize(m.field) * sizeof(float*));
		m.field[i + 1] = (float*)malloc(sizeof(float));
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			m.field[i][j] = 0;
		}
	}
	for (int i = 0; i < SIZE; i++)	m.field[i][i] = 1;
}

void out_matrix(matrix &m) {
	cout << "Matrix " << m.name << ":" << endl;
	int stringNum = m.volume / _msize(m.field[0]);
	for (int i = 0; i < stringNum; i++) {
		for (int j = _msize(m.field[i]) / sizeof(float); j > 0; j--) {
			cout << m.field[i][_msize(m.field[i]) / sizeof(float) - j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//not realised functions

////need using another method, maybe swap by name
//void swap_matrix(float **m1, float **m2, int size) {
//	float buffer;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			buffer = m1[i][j];
//			m1[i][j] = m2[i][j];
//			m2[i][j] = buffer;
//		}
//	}
//}
//
//void multiply_number(float **m, int size, float num) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			m[i][j] = m[i][j] * num;
//		}
//	}
//}
//
//void addtition_matrix(float **a, float **b, float **c, int size) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			c[i][j] = a[i][j] + b[i][j];
//		}
//	}
//}
//
//void subtraction_matrix(float **a, float **b, float **c, int size) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			c[i][j] = a[i][j] - b[i][j];
//		}
//	}
//}
//
////need reallocation, cose 2x3 does not transpose to 3x2
//void transposition_matrix(float **m, int size) {
//	float buffer = 0;
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < 1 + i; j++) {
//			buffer = m[j][i];
//			m[j][i] = m[i][j];
//			m[i][j] = buffer;
//		}
//	}
//}
//
////need reallocation: row(a)xcol(b) = row&col(c). (1 1 1)x(1 1 1)t = (1)
//void multiply_matrix(float **a, float **b, float **c, int size) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
//		}
//	}
//}
//
////need debug
//float determinant_matrix(float **m, int size) {
//	//need dynamic float p[size][size];
//	float det = 0;
//	int k = 1;
//
//	if (size == 1) {
//		det = m[0][0];
//		return det;
//	}
//
//	if (size == 2) {
//		det = m[0][0] * m[1][1] - (m[1][0] * m[0][1]);
//		return det;
//	}
//
//	if (size > 2) {
//		for (int i = 0; i < size; i++) {
//			int di = 0;
//			for (int ki = 0; ki < size - 1; ki++) {
//				if (ki == i)  di = 1;
//				int dj = 0;
//				for (int kj = 0; kj < size - 1; kj++) {
//					if (kj == 0)  dj = 1;
//					p[ki][kj] = m[ki + di][kj + dj];
//				}
//			}
//			det = det + k * m[i][0] * determinant_matrix(p, size - 1);
//			k = -k;
//		}
//	}
//
//	return det;
//}
//
////only works with 3x3
//void inverse_matrix(matrix m) {
//	matrix e;
//	e.matrix = (float **)malloc(sizeof(float*));
//	e.matrix[0] = (float*)malloc(sizeof(float));
//	e.volume = 0;
//	default_matrix(e);
//
//	float div, mult;
//	int a, b, c;
//
//	//only works if div != 0 and bug with a * a(-1) ~e
//		for (int k = 0; k < size; k++) {
//			div = m[k][k];
//			for (int i = 0; i < size; i++) {
//				m[k][i] /= div;
//				e[k][i] /= div;
//			}
//			//needed next for different conditions
//				if (k == 0)			a = 1, b = 3, c = 1;
//				else if (k == 1)	a = 0, b = 3, c = 2;
//				else if (k == 2)	a = 0, b = 2, c = 1;
//
//				for (int i = a; i < b; i += c) {
//					mult = m[i][k];
//					for (int j = 0; j < size; j++) {
//						m[i][j] -= m[k][j] * mult;
//						e[i][j] -= e[k][j] * mult;
//					}
//				}
//		}
//	swap_matrix(m, e, size);
//}

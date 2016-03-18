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
	unsigned int stringNum = m.volume / _msize(m.field[0]);
	for (unsigned int i = 0; i < stringNum; i++)	free(m.field[i]);
	free(m.field);
}

void input_matrix(matrix &m) {
	free_matrix(m);
	init_matrix(m);
	unsigned int i = 0;
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

	for (unsigned int i = 0; i < SIZE; i++) {
		for (unsigned int j = 0; j < SIZE - 1; j++) {
			m.field[i] = (float*)realloc(m.field[i], _msize(m.field[i]) + sizeof(float));
		}
		m.volume += _msize(m.field[i]);
		m.field = (float**)realloc(m.field, _msize(m.field) * sizeof(float*));
		m.field[i + 1] = (float*)malloc(sizeof(float));
	}

	for (unsigned int i = 0; i < SIZE; i++) {
		for (unsigned int j = 0; j < SIZE; j++) {
			m.field[i][j] = 0;
		}
	}
	for (unsigned int i = 0; i < SIZE; i++)	m.field[i][i] = 1;
}

void out_matrix(matrix &m) {
	cout << "Matrix " << m.name << ":" << endl;
	unsigned int stringNum = m.volume / _msize(m.field[0]);
	unsigned int rowNum = _msize(m.field[0]) / sizeof(float);
	for (unsigned int i = 0; i < stringNum; i++) {
		for (unsigned int j = 0; j < rowNum; j++) {
			cout << m.field[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void swap_matrix(matrix &m1, matrix &m2) {
	float **bufferField = m1.field;
	m1.field = m2.field;
	m2.field = bufferField;

	unsigned int bufferVol = m1.volume;
	m1.volume = m2.volume;
	m2.volume = bufferVol;
}

void multiply_number(matrix &m, float num) {
	unsigned int stringNum = m.volume / _msize(m.field[0]);
	unsigned int rowNum = _msize(m.field[0]) / sizeof(float);
	for (unsigned int i = 0; i < stringNum; i++) {
		for (unsigned int j = 0; j < rowNum; j++) {
			m.field[i][j] = m.field[i][j] * num;
		}
	}
}

void addtition_matrix(matrix &m1, matrix &m2, matrix &m3) {
	unsigned int stringNum = m1.volume / _msize(m1.field[0]);
	unsigned int rowNum = _msize(m1.field[0]) / sizeof(float);

	free_matrix(m3);
	init_matrix(m3);

	for (unsigned int i = 0; i < stringNum; i++) {
		for (unsigned int j = 0; j < rowNum - 1; j++) {
			m3.field[i] = (float*)realloc(m3.field[i], _msize(m3.field[i]) + sizeof(float));
		}
		m3.volume += _msize(m3.field[i]);
		m3.field = (float**)realloc(m3.field, _msize(m3.field) * sizeof(float*));
		m3.field[i + 1] = (float*)malloc(sizeof(float));
	}

	for (unsigned int i = 0; i < stringNum; i++) {
		for (unsigned int j = 0; j < rowNum; j++) {
			m3.field[i][j] = m1.field[i][j] + m2.field[i][j];
		}
	}
}

void subtraction_matrix(matrix &m1, matrix &m2, matrix &m3) {
	unsigned int stringNum = m1.volume / _msize(m1.field[0]);
	unsigned int rowNum = _msize(m1.field[0]) / sizeof(float);

	free_matrix(m3);
	init_matrix(m3);

	for (unsigned int i = 0; i < stringNum; i++) {
		for (unsigned int j = 0; j < rowNum - 1; j++) {
			m3.field[i] = (float*)realloc(m3.field[i], _msize(m3.field[i]) + sizeof(float));
		}
		m3.volume += _msize(m3.field[i]);
		m3.field = (float**)realloc(m3.field, _msize(m3.field) * sizeof(float*));
		m3.field[i + 1] = (float*)malloc(sizeof(float));
	}

	for (unsigned int i = 0; i < stringNum; i++) {
		for (unsigned int j = 0; j < rowNum; j++) {
			m3.field[i][j] = m1.field[i][j] - m2.field[i][j];
		}
	}
}

void transposition_matrix(matrix &m) {
	unsigned int stringNum = m.volume / _msize(m.field[0]);
	unsigned int rowNum = _msize(m.field[0]) / sizeof(float);

	matrix e;
	init_matrix(e);

	for (unsigned int i = 0; i < rowNum; i++) {
		for (unsigned int j = 0; j < stringNum - 1; j++) {
			e.field[i] = (float*)realloc(e.field[i], _msize(e.field[i]) + sizeof(float));
		}
		e.volume += _msize(e.field[i]);
		e.field = (float**)realloc(e.field, _msize(e.field) * sizeof(float*));
		e.field[i + 1] = (float*)malloc(sizeof(float));
	}

	for (unsigned int i = 0; i < rowNum; i++) {
		for (unsigned int j = 0; j < stringNum; j++) {
			e.field[i][j] = m.field[j][i];
		}
	}

	swap_matrix(e, m);
	free_matrix(e);
}

void multiply_matrix(matrix &m1, matrix &m2, matrix &m3) {
	unsigned int stringNum = m1.volume / _msize(m1.field[0]);
	unsigned int rowNum = _msize(m2.field[0]) / sizeof(float);

	unsigned int rowNumM1 = _msize(m1.field[0]) / sizeof(float);

	if (stringNum == rowNum) {			//strings A equials rows B

		free_matrix(m3);
		init_matrix(m3);
		for (unsigned int i = 0; i < stringNum; i++) {
			for (unsigned int j = 0; j < rowNum - 1; j++) {
				m3.field[i] = (float*)realloc(m3.field[i], _msize(m3.field[i]) + sizeof(float));
			}
			m3.volume += _msize(m3.field[i]);
			m3.field = (float**)realloc(m3.field, _msize(m3.field) * sizeof(float*));
			m3.field[i + 1] = (float*)malloc(sizeof(float));
		}

		float summ = 0;
		for (unsigned int i = 0; i < stringNum; i++) {
			for (unsigned int j = 0; j < rowNum; j++) {
				summ = 0;
				for (unsigned int e = 0; e < rowNumM1; e++)	summ += m1.field[i][e] * m2.field[e][j];
				m3.field[i][j] = summ;
			}
		}
	}
}

// not realised functions

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

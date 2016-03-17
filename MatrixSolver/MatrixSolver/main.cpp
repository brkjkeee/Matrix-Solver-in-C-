#include <iostream>
#include <math.h>
#include "fraction.h"
#define EOS '\n'

using namespace std;

void input_matrix(float m[3][3], char* text) {	
	system("CLS");
	for (int i = 0; i < 3; i++) {
		cout << "Enter " << i + 1 << " string of matrix " << text << ": ";
		for (int j = 0; j < 3; j++) {
			cin >> m[i][j];
		}
	}
}

void out_matrix(float m[3][3], char* text) {	
	cout << "Matrix "<< text << ":";
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void swap_matrix(float m1[3][3], float m2[3][3]) {
	float buffer;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			buffer = m1[i][j];
			m1[i][j] = m2[i][j];
			m2[i][j] = buffer;
		}
	}
}

void multiply_number(float m[3][3], float num) {	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = m[i][j] * num;
		}
	}
}

void addtition_matrix(float a[3][3], float b[3][3], float c[3][3]) {	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void subtraction_matrix(float a[3][3], float b[3][3], float c[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}

void transposition_matrix(float m[3][3]) {
	float buffer = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1 + i; j++) {
			buffer = m[j][i];
			m[j][i] = m[i][j];
			m[i][j] = buffer;
		}
	}
}

void multiply_matrix(float a[3][3], float b[3][3], float c[3][3]) {
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
		}
	}
}

//need debug
float determinant_matrix(float m[3][3], int size) {
	float p[3][3];
	float det = 0;
	int k = 1;

	if (size == 1) {
		det = m[0][0];
		return det;
	}

	if (size == 2) {
		det = m[0][0] * m[1][1] - (m[1][0] * m[0][1]);
		return det;
	}

	if (size > 2) {
		for (int i = 0; i < size; i++) {
			int di = 0;
			for (int ki = 0; ki < size - 1; ki++) {
				if (ki == i)  di = 1;
				int dj = 0;
				for (int kj = 0; kj < size - 1; kj++) {
					if (kj == 0)  dj = 1;
					p[ki][kj] = m[ki + di][kj + dj];
				}
			}
			det = det + k * m[i][0] * determinant_matrix(p, size-1);
			k = -k;
		}
	}	

	return det;
}

void inverse_matrix(float m[3][3]) {
	float e[3][3] = { {1, 0, 0} ,
					  {0, 1, 0} , 
					  {0, 0, 1} };
	float div, mult;
	int a, b, c;

	//only works if div != 0 and bug with A * A(-1) ~ E
	for (int k = 0; k < 3; k++) {
		div = m[k][k];
		for (int i = 0; i < 3; i++) {
			m[k][i] /= div;
			e[k][i] /= div;
		}
		//needed next FOR different conditions
		if (k == 0)			a = 1, b = 3, c = 1;
		else if (k == 1)	a = 0, b = 3, c = 2;
		else if (k == 2)	a = 0, b = 2, c = 1;

		for (int i = a; i < b; i += c) {
			mult = m[i][k];
			for (int j = 0; j < 3; j++) {
				m[i][j] -= m[k][j] * mult;
				e[i][j] -= e[k][j] * mult;
			}
		}
	}
	swap_matrix(m, e);
}

void menu() {
	cout << "Universal matrix calculator" << endl << endl;

	cout << "INPUT operations:" << endl;
	cout << "1.Enter A matrix" << endl;
	cout << "2.Enter B matrix" << endl;
	cout << "3.Enter C matrix" << endl;
	cout << "4.Enter number 'c'" << endl << endl;

	cout << "Actions:" << endl;
	cout << "5.Multiply matrix on number 'c'" << endl;
	cout << "6.Additition matrix A+B" << endl;
	cout << "7.Substraction matrix A-B" << endl;
	cout << "8.Transpose matrix" << endl;
	cout << "9.Myltiply matrixes A*B=C" << endl;
	cout << "10.Search for determinant" << endl;
	cout << "11.Inverse matrix" << endl << endl;

	cout << "Additional:" << endl;
	cout << "12.Show matrix" << endl;
	cout << "13.Swap matrix" << endl;
	cout << "14.Reset to default" << endl << endl;
	

	cout << "15.Exit" << endl;

	cout << endl << endl;
}

void default_matrix(float m[3][3]) { 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++)	m[i][i] = 1;
}

int main() {
	float a[3][3], b[3][3], c[3][3], num = 0;
	default_matrix(a); default_matrix(b); default_matrix(c);
	int swt = 0;
	char m;

	while (swt != 15) {
		system("CLS");
		menu();
		cout << "Choose action: ";
		cin >> swt;

		switch (swt) {
		case 1:
			system("CLS");
			cout << "Input matrix A" << endl << endl;
			input_matrix(a, "A");
			system("Pause");
			break;

		case 2:
			system("CLS");
			cout << "Input matrix B" << endl << endl;
			input_matrix(b, "B");
			system("Pause");
			break;

		case 3:
			system("CLS");
			cout << "Input matrix C" << endl << endl;
			input_matrix(c, "C");
			system("Pause");
			break;

		case 4:
			system("CLS");
			cout << "Input number 'c'" << endl << endl;
			cout << "Enter a number: ";
			cin >> num;
			system("Pause");
			break;

		case 5:
			system("CLS");
			cout << "Operation MULTIPLY on number 'c'" << endl << endl;
			cout << "Switch matrix (A, B, C): ";
			cin >> m;
			cout << endl;
			cout << "Initial parameters:" << endl << endl;
			if (m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô' || m == 'ô' || m == 'F' || m == 'f' || m == '1') {
				out_matrix(a, "A"); 
				cout << "Number 'c': " << num << endl << endl;

				multiply_number(a, num);

				cout << endl << "Result:" << endl << endl;
				out_matrix(a, "A");
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b, "B");
				cout << "Number 'c': " << num << endl << endl;

				multiply_number(b, num);

				cout << endl << "Result:" << endl << endl;
				out_matrix(b, "B");
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c, "C");
				cout << "Number 'c': " << num << endl << endl;

				multiply_number(c, num);

				cout << endl << "Result:" << endl << endl;
				out_matrix(c, "C");
			}
			system("Pause");
			break;

		case 6:
			system("CLS");
			cout << "Operation ADDITION matrixes A+B" << endl << endl;
			cout << "Initial parameters:" << endl << endl;
			out_matrix(a, "A");
			out_matrix(b, "B");

			addtition_matrix(a, b, c);
			
			cout << endl << "Result:" << endl << endl;
			out_matrix(c, "C");
			system("Pause");
			break;

		case 7:
			system("CLS");
			cout << "Operation SUBSTRACTION matrixes A-B" << endl << endl;
			cout << "Initial parameters:" << endl << endl;
			out_matrix(a, "A");
			out_matrix(b, "B");

			subtraction_matrix(a, b, c);
			
			cout << endl << "Result:" << endl << endl;
			out_matrix(c, "C");
			system("Pause");
			break;

		case 8:
			system("CLS");
			cout << "Operation transpose matrix" << endl << endl;
			cout << "Switch matrix (A, B, C): ";
			cin >> m;
			cout << endl;
			cout << "Initial parameters:" << endl << endl;
			if (m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô' || m == 'ô' || m == 'F' || m == 'f' || m == '1') {
				out_matrix(a, "A");
				
				transposition_matrix(a);

				cout << endl << "Result:" << endl << endl;
				out_matrix(a, "A");
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b, "B");

				transposition_matrix(b);

				cout << endl << "Result:" << endl << endl;
				out_matrix(b, "B");
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c, "C");

				transposition_matrix(c);

				cout << endl << "Result:" << endl << endl;
				out_matrix(c, "C");
			}
			system("Pause");
			break;

		case 9: 
			system("CLS");
			cout << "Operation myltiply matrixes" << endl << endl;
			cout << "Initial parameters:" << endl << endl;
			out_matrix(a, "A");
			out_matrix(b, "B");

			multiply_matrix(a,b,c);

			cout << endl << "Result:" << endl << endl;
			out_matrix(c, "C");
			system("Pause");
			break;

		case 10: 
			system("CLS");
			cout << "Operation searching DETERMINANT of matrix" << endl << endl;
			cout << "Switch matrix (A, B, C): ";
			cin >> m;
			cout << endl;
			cout << "Initial parameters:" << endl << endl;
			if (m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô' || m == 'ô' || m == 'F' || m == 'f' || m == '1') {
				out_matrix(a, "A");

				cout << endl << "Result:" << endl << endl;
				cout << "det[A] = " << determinant_matrix(a,3) << endl << endl;
				out_matrix(a, "A");
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b, "B");

				cout << endl << "Result:" << endl << endl;
				cout << "det[B] = " << determinant_matrix(b,3) << endl << endl;
				out_matrix(b, "B");
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c, "C");

				cout << endl << "Result:" << endl << endl;
				cout << "det[C] = " << determinant_matrix(c,3) << endl << endl;
				out_matrix(c, "C");
			}
			system("Pause");
			break;

		case 11: 
			system("CLS");
			cout << "Operation searching INVERSE matrix" << endl << endl;
			cout << "Switch matrix (A, B, C): ";
			cin >> m;
			cout << endl;
			cout << "Initial parameters:" << endl << endl;
			if (m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô' || m == 'ô' || m == 'F' || m == 'f' || m == '1') {
				out_matrix(a, "A");

				cout << endl << "Result:" << endl << endl;
				inverse_matrix(a);

				out_matrix(a, "A(-1)");
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b, "B");

				cout << endl << "Result:" << endl << endl;
				inverse_matrix(b);
				out_matrix(b, "B(-1)");
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c, "C");

				cout << endl << "Result:" << endl << endl;
				inverse_matrix(c);
				out_matrix(c, "C(-1)");
			}
			system("Pause");
			break;

		case 12:
			system("CLS");
			out_matrix(a, "A");
			out_matrix(b, "B");
			out_matrix(c, "C");
			system("Pause");
			break;

		case 13:
			system("CLS");
			cout << "Operation SWAP matrix" << endl << endl;

			cout << "1.A <-> B" << endl;
			cout << "2.A <-> C" << endl;
			cout << "3.B <-> C" << endl;
			cout << "4.Exit" << endl << endl;

			cout << "Choose action: " << endl;
			cin >> m;
			cout << endl;
			if     (m == '1')	swap_matrix(a, b);
			else if(m == '2')	swap_matrix(a, c);
			else if(m == '3')	swap_matrix(b, c);
			
			system("Pause");
			break;

		case 14:
			system("CLS");
			cout << "Operation RESET to default" << endl << endl;
			cout << "Switch matrix (A, B, C): ";
			cin >> m;
			cout << endl;
			if		(m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô' 
					|| m == 'ô' || m == 'F' || m == 'f' || m == '1')										default_matrix(a);
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' 
					|| m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') 	default_matrix(b);
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') 								default_matrix(c);
			
			system("Pause");
			break;

		default:
			break;
		}
	}
	
	return 0;
}
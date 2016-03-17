#include <iostream>
#include <conio.h>
#include "fraction.h"
#include "matrix.h"
#define EOS '\n'

using namespace std;

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

	cout << endl;
}

int main() {
	matrix a, b, c;
	a.name = "A";
	b.name = "B";
	c.name = "C";
	default_matrix(a); default_matrix(b); default_matrix(c);

	float num = 0;
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
			input_matrix(a);
			system("Pause");
			break;

		case 2:
			system("CLS");
			input_matrix(b);
			system("Pause");
			break;

		case 3:
			system("CLS");
			input_matrix(c);
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
				out_matrix(a); 
				cout << "Number 'c': " << num << endl << endl;

				//multiply_number(a, num);

				cout << endl << "Result:" << endl << endl;
				out_matrix(a);
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b);
				cout << "Number 'c': " << num << endl << endl;

				//multiply_number(b, num);

				cout << endl << "Result:" << endl << endl;
				out_matrix(b);
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c);
				cout << "Number 'c': " << num << endl << endl;

				//multiply_number(c, num);

				cout << endl << "Result:" << endl << endl;
				out_matrix(c);
			}
			system("Pause");
			break;

		case 6:
			system("CLS");
			cout << "Operation ADDITION matrixes A+B" << endl << endl;
			cout << "Initial parameters:" << endl << endl;
			out_matrix(a);
			out_matrix(b);

			//addtition_matrix(a, b, c);
			
			cout << endl << "Result:" << endl << endl;
			out_matrix(c);
			system("Pause");
			break;

		case 7:
			system("CLS");
			cout << "Operation SUBSTRACTION matrixes A-B" << endl << endl;
			cout << "Initial parameters:" << endl << endl;
			out_matrix(a);
			out_matrix(b);

			//subtraction_matrix(a, b, c);
			
			cout << endl << "Result:" << endl << endl;
			out_matrix(c);
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
				out_matrix(a);
				
				//transposition_matrix(a);

				cout << endl << "Result:" << endl << endl;
				out_matrix(a);
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b);

				//transposition_matrix(b);

				cout << endl << "Result:" << endl << endl;
				out_matrix(b);
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c);

				//transposition_matrix(c);

				cout << endl << "Result:" << endl << endl;
				out_matrix(c);
			}
			system("Pause");
			break;

		case 9: 
			system("CLS");
			cout << "Operation myltiply matrixes" << endl << endl;
			cout << "Initial parameters:" << endl << endl;
			out_matrix(a);
			out_matrix(b);

			//multiply_matrix(a,b,c);

			cout << endl << "Result:" << endl << endl;
			out_matrix(c);
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
				out_matrix(a);

				cout << endl << "Result:" << endl << endl;
				//cout << "det[A] = " << determinant_matrix(a,3) << endl << endl;
				out_matrix(a);
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b);

				cout << endl << "Result:" << endl << endl;
				//cout << "det[B] = " << determinant_matrix(b,3) << endl << endl;
				out_matrix(b);
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c);

				cout << endl << "Result:" << endl << endl;
				//cout << "det[C] = " << determinant_matrix(c,3) << endl << endl;
				out_matrix(c);
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
				out_matrix(a);

				cout << endl << "Result:" << endl << endl;
				//inverse_matrix(a);

				out_matrix(a);
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b);

				cout << endl << "Result:" << endl << endl;
				//inverse_matrix(b);
				out_matrix(b);
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c);

				cout << endl << "Result:" << endl << endl;
				//inverse_matrix(c);
				out_matrix(c);
			}
			system("Pause");
			break;

		case 12:
			system("CLS");
			out_matrix(a);
			out_matrix(b);
			out_matrix(c);
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
			/*if     (m == '1')	swap_matrix(a, b);
			else if(m == '2')	swap_matrix(a, c);
			else if(m == '3')	swap_matrix(b, c);*/
			
			system("Pause");
			break;

		case 14:
			system("CLS");
			cout << "Operation RESET to default" << endl << endl;
			cout << "Switch matrix (A, B, C): ";
			cin >> m;
			cout << endl;
			if (m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô'
				|| m == 'ô' || m == 'F' || m == 'f' || m == '1') {
				free_matrix(a);
				default_matrix(a);
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ','
				|| m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				free_matrix(b);
				default_matrix(b);
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				free_matrix(c);
				default_matrix(c);
			}
			
			system("Pause");
			break;

		default:
			break;
		}
	}
	free_matrix(a);
	free_matrix(b);
	free_matrix(c);
	return 0;
}
#include <iostream>
#include <conio.h>
#include "fraction.h"
#include "matrix.h"
#define ESC 27
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
	float num = 0;
	unsigned int swt = 0, count = 0;
	char m;

	matrix a, b, c;
	a.name = 'A';
	b.name = 'B'; 
	c.name = 'C';
	default_matrix(a); default_matrix(b); default_matrix(c);
			 	
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
			cout << "Switch matrix (" << a.name << "," << b.name << "," << c.name << "): ";
			cin >> m;
			cout << endl;
			cout << "Initial parameters:" << endl << endl;
			if (m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô' || m == 'ô' || m == 'F' || m == 'f' || m == '1') {
				out_matrix(a);
				cout << "Number 'c': " << num << endl << endl;

				//multiply_number(a, size, num);

				cout << endl << "Result:" << endl << endl;
				out_matrix(a);
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b);
				cout << "Number 'c': " << num << endl << endl;

				//multiply_number(b, size, num);

				cout << endl << "Result:" << endl << endl;
				out_matrix(b);
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c);
				cout << "Number 'c': " << num << endl << endl;

				//multiply_number(c, size, num);

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

			//addtition_matrix(a, b, c, size);
			
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

			//subtraction_matrix(a, b, c, size);
			
			cout << endl << "Result:" << endl << endl;
			out_matrix(c);
			system("Pause");
			break;

		case 8:
			system("CLS");
			cout << "Operation transpose matrix" << endl << endl;
			cout << "Switch matrix ("<< a.name <<","<< b.name << "," << c.name << "): ";
			cin >> m;
			cout << endl;
			cout << "Initial parameters:" << endl << endl;
			if (m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô' || m == 'ô' || m == 'F' || m == 'f' || m == '1') {
				out_matrix(a);
				
				//transposition_matrix(a, size);

				cout << endl << "Result:" << endl << endl;
				out_matrix(a);
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b);

				//transposition_matrix(b, size);

				cout << endl << "Result:" << endl << endl;
				out_matrix(b);
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c);

				//transposition_matrix(c, size);

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

			//multiply_matrix(a,b,c, size);

			cout << endl << "Result:" << endl << endl;
			out_matrix(c);
			system("Pause");
			break;

		case 10: 
			system("CLS");
			cout << "Operation searching DETERMINANT of matrix" << endl << endl;
			cout << "Switch matrix (" << a.name << "," << b.name << "," << c.name << "): ";
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
			cout << "Switch matrix (" << a.name << "," << b.name << "," << c.name << "): ";
			cin >> m;
			cout << endl;
			cout << "Initial parameters:" << endl << endl;
			if (m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô' || m == 'ô' || m == 'F' || m == 'f' || m == '1') {
				out_matrix(a);

				cout << endl << "Result:" << endl << endl;
				//inverse_matrix(a, size);

				out_matrix(a);
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
				out_matrix(b);

				cout << endl << "Result:" << endl << endl;
				//inverse_matrix(b, size);

				out_matrix(b);
			}
			else if (m == 'Ñ' || m == 'ñ' || m == 'C' || m == 'c' || m == '3') {
				out_matrix(c);

				cout << endl << "Result:" << endl << endl;
				//inverse_matrix(c, size);

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

			cout << "1." << a.name << " <-> " << b.name << endl;
			cout << "2." << a.name << " <-> " << c.name << endl;
			cout << "3." << b.name << " <-> " << c.name << endl;
			cout << "4.Exit" << endl << endl;

			cout << "Choose action: " << endl;
			cin >> m;
			cout << endl;
			//if     (m == '1')	swap_matrix(a, b, size);
			//else if(m == '2')	swap_matrix(a, c, size);
			//else if(m == '3')	swap_matrix(b, c, size);
			
			system("Pause");
			break;

		case 14:
			system("CLS");
			cout << "Operation RESET to default" << endl << endl;
			cout << "Switch matrix (" << a.name << "," << b.name << "," << c.name << "): ";
			cin >> m;
			cout << endl;
			if (m == 'A' || m == 'a' || m == 'À' || m == 'à' || m == 'Ô' || m == 'ô' || m == 'F' || m == 'f' || m == '1') {
				free_matrix(a);
				default_matrix(a);
			}
			else if (m == 'Â' || m == 'â' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'È' || m == 'è' || m == 'Á' || m == 'á' || m == 'B' || m == 'b' || m == '2') {
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
	
	return 0;
}
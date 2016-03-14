#include <iostream>
#include <math.h>
#include "fraction.h"
#define EOS '\n'

using namespace std;

//Ввод матрицы в систему
void input_matrix(float m[3][3], char* text) {	
	system("CLS");
	for (int i = 0; i < 3; i++) {
		cout << "Введите " << i + 1 << " строку матрицы " << text << ": ";
		for (int j = 0; j < 3; j++) {
			cin >> m[i][j];
		}
	}
}

//Вывод матрицы на консоль
void out_matrix(float m[3][3], char* text) {	
	cout << "Матирица "<< text << ":";
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//Перестановка матриц местами
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

//Умножение матрицы на число А*с
void multiply_number(float m[3][3], float num) {	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = m[i][j] * num;
		}
	}
}

//Сложение матриц А+В
void addtition_matrix(float a[3][3], float b[3][3], float c[3][3]) {	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

//Вычитание матриц А-В
void subtraction_matrix(float a[3][3], float b[3][3], float c[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}

//Транспонирование матриц
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

//Умножение матриц А*В
void multiply_matrix(float a[3][3], float b[3][3], float c[3][3]) {
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
		}
	}
}

//Определитель матрицы //debug
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

//Обратная матрица
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

//Вывод текста меню на консоль
void menu() {
	cout << "Универсальный матричный калькулятор" << endl << endl;

	cout << "1.Задание матрицы А" << endl;
	cout << "2.Задание матрицы В" << endl;
	cout << "3.Задание матрицы С" << endl;
	cout << "4.Задание числа 'с'" << endl << endl;

	cout << "5.Умножение матрицы на число 'с'" << endl;
	cout << "6.Сложение матриц А+В" << endl;
	cout << "7.Вычитание матриц A-B" << endl;
	cout << "8.Транспонирование" << endl;
	cout << "9.Умножение матриц A*B=C" << endl;
	cout << "10.Нахождение определителя" << endl;
	cout << "11.Обратная матрица" << endl << endl;

	cout << "12.Выход" << endl;

	cout << endl << endl;
}

//Матрица по умолчанию
void default_matrix(float m[3][3]) { 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++)	m[i][i] = 1;
}

int main() {
	setlocale(LC_ALL,"Russian");

	float a[3][3], b[3][3], c[3][3], num = 0;
	default_matrix(a); default_matrix(b); default_matrix(c);
	int swt = 0;
	char m;

	while (swt != 12) {
		system("CLS");
		menu();
		cout << "Выберите действие: ";
		cin >> swt;

		switch (swt) {
		case 1:
			system("CLS");
			cout << "Ввод матрицы А" << endl << endl;
			input_matrix(a, "A");
			system("Pause");
			break;

		case 2:
			system("CLS");
			cout << "Ввод матрицы B" << endl << endl;
			input_matrix(b, "B");
			system("Pause");
			break;

		case 3:
			system("CLS");
			cout << "Ввод матрицы C" << endl << endl;
			input_matrix(c, "C");
			system("Pause");
			break;

		case 4:
			system("CLS");
			cout << "Ввод числа 'c'" << endl << endl;
			cout << "Введите число: ";
			cin >> num;
			system("Pause");
			break;

		case 5:
			system("CLS");
			cout << "Операция умножения на число 'c'" << endl << endl;
			cout << "Укажите матрицу (A, B, C): ";
			cin >> m;
			cout << endl;

			if (m == 'A' || m == 'a' || m == 'А' || m == 'а' || m == 'Ф' || m == 'ф' || m == 'F' || m == 'f' || m == '1') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(a, "A"); 
				cout << "Число 'с': " << num << endl << endl;

				multiply_number(a, num);

				cout << endl << "Результат" << endl << endl;
				out_matrix(a, "A");
			}
			else if (m == 'В' || m == 'в' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'И' || m == 'и' || m == 'Б' || m == 'б' || m == 'B' || m == 'b' || m == '2') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(b, "B");
				cout << "Число 'с': " << num << endl << endl;

				multiply_number(b, num);

				cout << endl << "Результат" << endl << endl;
				out_matrix(b, "B");
			}
			else if (m == 'С' || m == 'с' || m == 'C' || m == 'c' || m == '3') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(c, "C");
				cout << "Число 'с': " << num << endl << endl;

				multiply_number(c, num);

				cout << endl << "Результат" << endl << endl;
				out_matrix(c, "C");
			}
			system("Pause");
			break;

		case 6:
			system("CLS");
			cout << "Операция сложения матриц A+B" << endl << endl;
			cout << "Начальные параметры" << endl << endl;
			out_matrix(a, "A");
			out_matrix(b, "B");

			addtition_matrix(a, b, c);
			
			cout << endl << "Результат" << endl << endl;
			out_matrix(c, "C");
			system("Pause");
			break;

		case 7:
			system("CLS");
			cout << "Операция вычитания матриц A-B" << endl << endl;
			cout << "Начальные параметры" << endl << endl;
			out_matrix(a, "A");
			out_matrix(b, "B");

			subtraction_matrix(a, b, c);
			
			cout << endl << "Результат" << endl << endl;
			out_matrix(c, "C");
			system("Pause");
			break;

		case 8:
			system("CLS");
			cout << "Операция транспонирования матриц" << endl << endl;
			cout << "Укажите матрицу (A, B, C): ";
			cin >> m;
			cout << endl;
			if (m == 'A' || m == 'a' || m == 'А' || m == 'а' || m == 'Ф' || m == 'ф' || m == 'F' || m == 'f' || m == '1') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(a, "A");
				
				transposition_matrix(a);

				cout << endl << "Результат" << endl << endl;
				out_matrix(a, "A");
			}
			else if (m == 'В' || m == 'в' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'И' || m == 'и' || m == 'Б' || m == 'б' || m == 'B' || m == 'b' || m == '2') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(b, "B");

				transposition_matrix(b);

				cout << endl << "Результат" << endl << endl;
				out_matrix(b, "B");
			}
			else if (m == 'С' || m == 'с' || m == 'C' || m == 'c' || m == '3') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(c, "C");

				transposition_matrix(c);

				cout << endl << "Результат" << endl << endl;
				out_matrix(c, "C");
			}
			system("Pause");
			break;

		case 9: 
			system("CLS");
			cout << "Операция умножения матриц" << endl << endl;
			cout << "Начальные параметры" << endl << endl;
			out_matrix(a, "A");
			out_matrix(b, "B");

			multiply_matrix(a,b,c);

			cout << endl << "Результат" << endl << endl;
			out_matrix(c, "C");
			system("Pause");
			break;

		case 10: 
			system("CLS");
			cout << "Операция нахождения определителя матриц" << endl << endl;
			cout << "Укажите матрицу (A, B, C): ";
			cin >> m;
			cout << endl;
			if (m == 'A' || m == 'a' || m == 'А' || m == 'а' || m == 'Ф' || m == 'ф' || m == 'F' || m == 'f' || m == '1') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(a, "A");

				cout << endl << "Результат" << endl << endl;
				cout << "det[A] = " << determinant_matrix(a,3) << endl << endl;
				out_matrix(a, "A");
			}
			else if (m == 'В' || m == 'в' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'И' || m == 'и' || m == 'Б' || m == 'б' || m == 'B' || m == 'b' || m == '2') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(b, "B");

				cout << endl << "Результат" << endl << endl;
				cout << "det[B] = " << determinant_matrix(b,3) << endl << endl;
				out_matrix(b, "B");
			}
			else if (m == 'С' || m == 'с' || m == 'C' || m == 'c' || m == '3') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(c, "C");

				cout << endl << "Результат" << endl << endl;
				cout << "det[C] = " << determinant_matrix(c,3) << endl << endl;
				out_matrix(c, "C");
			}
			system("Pause");
			break;

		case 11: 
			system("CLS");
			cout << "Операция нахождения обратной матрицы" << endl << endl;
			cout << "Укажите матрицу (A, B, C): ";
			cin >> m;
			cout << endl;
			if (m == 'A' || m == 'a' || m == 'А' || m == 'а' || m == 'Ф' || m == 'ф' || m == 'F' || m == 'f' || m == '1') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(a, "A");

				cout << endl << "Результат" << endl << endl;
				inverse_matrix(a);

				out_matrix(a, "A(-1)");
			}
			else if (m == 'В' || m == 'в' || m == 'D' || m == 'd' || m == '<' || m == ',' || m == 'И' || m == 'и' || m == 'Б' || m == 'б' || m == 'B' || m == 'b' || m == '2') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(b, "B");

				cout << endl << "Результат" << endl << endl;
				inverse_matrix(b);
				out_matrix(b, "B(-1)");
			}
			else if (m == 'С' || m == 'с' || m == 'C' || m == 'c' || m == '3') {
				cout << "Начальные параметры" << endl << endl;
				out_matrix(c, "C");

				cout << endl << "Результат" << endl << endl;
				inverse_matrix(c);
				out_matrix(c, "C(-1)");
			}
			system("Pause");
			break;

		default:
			break;
		}
	}
	
	return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include "Matrix.h"
#include <conio.h>
#include <Windows.h>

void menu()
{
	cout << "Ingresar opcion: " << endl;
	cout << "1) exportar a txt , 2) eliminar fila, 3) eliminar columna, 4) filtrar, 5) indexar, 6) editar dato, 7) ordenar " << endl;
}
void menufiltrar(matrix& a)
{
	string dat;
	char xd;
	int col;
	int dato;
	cout << "1) comienza con, 2) termina con, 3) mayor que, 4) menor que, 5) igual que, 6) exportar" << endl;
	while (true)
	{
		if (_kbhit())
		{
			char op = _getch();
			if (op == '1') {
				cout << endl;
				cout << "ingrese primeras letras o numeros: ";
				cin >> dat;
				cout << "ingrese columna que desea filtrar: ";
				cin >> col;
				startsw(a, col, dat);
				printMatrix(a);
				menufiltrar(a);
				
			}
			else if (op == '2')
			{
				cout << "ingrese letras o numeros finales: ";
				cin >> xd;
				cout << endl;
				cout << "ingrese columna que desea filtrar: ";
				cin >> col;
				cout << endl;
				endsw(a, col, xd);
				printMatrix(a);
				menufiltrar(a);
			}
			else if (op == '3')
			{
				cout << endl;
				cout << "ingrese numero que desea filtrar: ";
				cin >> dato;
				cout << "ingrese columna que desea filtrar: ";
				cin >> col;
				filtermajor(a, col, dato);
				printMatrix(a);
				menufiltrar(a);
			}
			else if (op == '4')
			{
				cout << endl;
				cout << "ingrese numero que desea filtrar: ";
				cin >> dato;
				cout << "ingrese columna que desea filtrar: ";
				cin >> col;
				filterminor(a, col, dato);
				printMatrix(a);
				menufiltrar(a);
			}
			else if (op == '5')
			{
				cout << endl;
				cout << "ingrese numero o string que desea filtrar: ";
				cin >> dat;
				cout << "ingrese columna que desea filtrar: ";
				cin >> col;
				filter(a, col, dat);
				printMatrix(a);
				menufiltrar(a);
			}
			else if (op == '6')
			{
				exportm(a);
				break;
			}
		}
	}

}

int main()
{
	matrix upc = readCSV("upc.csv");
	printMatrix(upc);
	int size = upc.size();
	int row = 0;
	int col = 0;
	int colindex = 0;
	string data;
	menu();
	while (true)
	{
		

		if (_kbhit())
		{
			char opt = _getch();

			if (opt == '4') menufiltrar(upc);
			else if (opt == '1') {
				exportm(upc);
				cout << "exportado existoso" << endl;
				break;
			
			}
			else if (opt == '2') {
				cout << "ingrese fila a eliminar: ";
				cin >> row;
				deleteRow(upc,row);
				printMatrix(upc);
				menu();
			}
			else if (opt == '3'){
				cout << "ingrese columna a eliminar: ";
				cin >> col;
				deleteCol(upc, col);
				printMatrix(upc);
				menu();
			}
			else if (opt == '5')
			{
				cout << "ingrese columna a indexar: ";
				cin >> colindex;
				indexcol(upc, colindex);
				orden(upc);
				/*printMatrix(upc);*/
				menu();
			}
			else if (opt == '6')
			{
				cout << "ingrese columna: ";
				cin >> col;
				cout << endl;
				cout << "ingrese fila: ";
				cin >> row;
				cout << "ingrese dato a modificar: ";
				cin >> data;
				edit(upc, row, col, data);
				printMatrix(upc);
				menu();
			}
			else if (opt == '7')
			{
				sortm(upc); 
				cout << "Ordenado existoso" << endl;
				
				printMatrix(upc);
				return 0;
			}
		}

		Sleep(100);
	}
	return 0;
	

	/*deleteRow(upc, 2);
	deleteCol(upc, 3);*/
	/*edit(upc, 1, 2, "69");
	printMatrix(upc);*/
	/*indexcol(upc, 4);*/
	/*filter(upc,0, "Dariana");*/
	/*startsw(upc, 0, "Dar");*/
	//endsw(upc, 0, "a");
	//filtermajor(upc, 2, 19);
	//sortm(upc);
	//sortx(upc);
	//printMatrix(upc);
	//exportm(upc);
	//
}

#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

using vec = vector<string>;
using matrix = vector<vec>;
ofstream outfile;
void sortx(matrix& bar);
void mergeSort(matrix& left, matrix& right, matrix& bars);
//======================================================================

matrix readCSV(string filename)
{
	char separa = ','; // cuando lee esto en el cvs separa la columna
	matrix matriz;
	string row;
	string item;

	ifstream in(filename);
	while (getline(in, row))
	{
		vec R;
		stringstream ss(row);
		while (getline(ss, item, separa)) R.push_back(item);
		matriz.push_back(R);
	}
	in.close();
	return matriz;
}

//======================================================================

void printMatrix(const matrix& M)
{
	
	for (vec row : M)
	{
		for (string s : row) cout << setw(12) << left << s << " ";    
		cout << '\n';
	}
	cout << endl;
}

//======================================================================

void deleteRow(matrix & M, int row)
{
	if (row < M.size()) M.erase(M.begin() + row);
}

//======================================================================

void deleteCol(matrix & M, int col)
{
	for (vec& row : M)
	{
		if (col < row.size()) row.erase(row.begin() + col);
	}
}

//======================================================================
void indexcol(matrix& M, int col)
{
	
	int i = 0;
	for(vec row : M)
	{
		if (i != col)
		{
			deleteCol(M, i);
			col--;
		}
		if (i == col)
			i++;
	}
}
//======================================================================

void edit(matrix & M, int i, int j, string value)
{
	if (i < M.size() && j < M[i].size()) M[i][j] = value;
}

//======================================================================
void filter(matrix& M, int col, string str) {
	
	int row = M.size(); // numero de las filas
	for (int i = 1; i < row;i++) // comienza en 1 por que la primera fila es el titulo de cada columna
	{
	
		if (M[i][col] != str) //si es diferente borra
		{
			deleteRow(M, i);
			i--; // reduce el contador por que se reducen las filas
		}
		row = M.size(); // row = al nuevo numero de filas despues de reducirse
	}
	
}
//======================================================================
void startsw(matrix& M, int col, string str) {

	int row = M.size();
	for (int i = 1; i < row; i++)
	{

		if (!M[i][col].find(str) == 0) // funcion que evalua si comienza con el string dado
		{
			deleteRow(M, i);
			i--;
		}
		row = M.size();
	}

}

//======================================================================
void endsw(matrix& M, int col, string str) {
	
	int row = M.size();
	for (int i = 1; i < row; i++)
	{
		
		if (!M[i][col].find_last_of(str, M[i][col].size()) == 0) // hay un error aca aun no lo arreglo
		{
			deleteRow(M, i);
			i--;
		}
		row = M.size();
	}

}

//======================================================================
void filterminor(matrix& M, int col, int str) {
	int num = 0;
	int row = M.size();
	for (int i = 1; i < row; i++)
	{
		num = stoi(M[i][col]); //convierte el string en int 
		if (num > str) //evalua los ints
		{
			deleteRow(M, i);
			i--;
		}
		row = M.size();
	}
	
}

//======================================================================
void filtermajor(matrix& M, int col, int str) {

	int num = 0;
	int row = M.size();
	for (int i = 1; i < row; i++)
	{
		num = stoi(M[i][col]);
		if (num < str)
		{
			deleteRow(M, i);
			i--;
		}
		row = M.size();
	}

}

//======================================================================

void sortm(matrix& M)//este es un sort del stl
{
		sort(M.begin()+1, M.end()); 
}
//======================================================================
void sortx(matrix& M) //este es un sort propio pero no ignora la primera fila al reordenar
{
	if (M.size() <= 1) return;

	int mid = (M.size() / 2);
	matrix left;
	matrix right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(M[j]);
	for (size_t j = 0; j < (M.size()) - mid; j++)
		right.push_back(M[mid + j]);

	sortx(left);
	sortx(right);
	mergeSort(left, right, M);
}
void mergeSort(matrix& left, matrix& right, matrix& bars) //este sort es necesario para que el sortx funcione
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j] < right[k]) {
			bars[i] = left[j];
			j++;
		}
		else {
			bars[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		bars[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		bars[i] = right[k];
		k++; i++;
	}
}
//======================================================================
void exportm(const matrix& M)
{
	outfile.open("upc.txt");
	if (outfile.good()) 
	{
		for (vec row : M)
		{
			for (string s : row) outfile << setw(12) << left << s << " ";
			outfile << endl;
		}
		outfile << endl;
		outfile.close();
	}
}
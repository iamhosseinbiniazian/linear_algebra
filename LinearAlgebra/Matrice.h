#include<iostream>
#include <string>
#include<cstring>
#include<string.h>
#include<vector>
#include<fstream>
#include <boost/lexical_cast.hpp>
#include <boost/numeric/conversion/cast.hpp>
#define SHOW(a)  #a
#pragma once
using namespace std;
template <typename T>
class Matrice
{
protected:
		T** matrix;
		int NumRow;
		int NumColumn;
		void split(const string& s, char delim,vector<string>& v);
public:
	Matrice(void);
	Matrice(int NumRow, int NumColumn);
	Matrice(int NumRow, int NumColumn,T Number);
	int getColumn();
	int getRow();
	void PrintMatrix();
	T CalTrace();
	Matrice<T>* MultiplyByScaler(T Scaler);
	T getEntryIJ(int i, int j);
	void setEntryIJ(int i, int j,T Number);
	Matrice<T>* Transpose();
	Matrice<T>* Add(Matrice<T> Matrix);
	Matrice<T>* Subtract(Matrice<T> Matrix);
	Matrice<T>* Multiplication(Matrice<T> Matrix);
	void ReadfromFile(char* fileName);
	Matrice<T>* DeleteRow(int i);
	Matrice<T>* DeleteColumn(int i);
	Matrice<T>* DeleteRowColumn(int i,int j);
	T Determinant();
	bool IsUpperTriangular();
	bool IsLowerTriangular();
	bool IsZero();
	Matrice<T>& operator=(Matrice&& other);
	~Matrice(void);
};



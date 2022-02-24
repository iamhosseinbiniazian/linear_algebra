#include<iostream>
#include <string>
#include<cstring>
#include<string.h>
#include<fstream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cmath>
#include <boost/lexical_cast.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include "Matrice.h"
#define SHOW(a)  #a
using namespace std;
using namespace boost;
//////////////////////Constractor/////////////////////////////////
template <typename T> Matrice<T>::Matrice(void){}

template <typename T> Matrice<T>::Matrice(int NumRow, int NumColumn) {
	(*this).NumRow = NumRow;
	(*this).NumColumn = NumColumn;
	matrix = new T*[NumRow];
	for (int i = 0; i < NumRow; ++i)
		matrix[i] = new T[NumColumn];
	/////////////////initilaize with Zero/////////////////
	for (int i = 0;i<NumRow;i++)
	{
		for (int j = 0;j<NumColumn;j++) {
			matrix[i][j] = 0;
		}
	}
}
template <typename T> Matrice<T>::	Matrice(int NumRow, int NumColumn,T Number)
{
	(*this).NumRow = NumRow;
	(*this).NumColumn = NumColumn;
	matrix = new T*[NumRow];
	for (int i = 0; i < NumRow; ++i)
		matrix[i] = new T[NumColumn];
	/////////////////initilaize with Zero/////////////////
	for (int i = 0;i<NumRow;i++)
	{
		for (int j = 0;j<NumColumn;j++) {
			matrix[i][j] =Number;
		}
	}

}
////////////////////////////////////End Constractor///////////////////////
template <typename T> void Matrice<T>::split(const string& s, char delim,vector<string>& v)
{
 int i = 0;
    int pos = s.find(delim);
    while (pos != string::npos) {
      v.push_back(s.substr(i, pos-i));
      i = ++pos;
      pos = s.find(delim, pos);

      if (pos == string::npos)
         v.push_back(s.substr(i, s.length()));
    }
}
	template <typename T> int Matrice<T>::getRow()
	{
		return (*this).NumRow;
	}
	template <typename T> int Matrice<T>::getColumn()
	{
		return (*this).NumColumn;
	}
template <typename T> void Matrice<T>::PrintMatrix()
{

	for (int row = 0; row<NumRow; row++)
	{
		for (int column = 0;column<NumColumn;column++){
			cout << (*this).matrix[row][column] << "|";
		}
		cout << "\n";
		for (double column = 0;column<NumColumn;column++)
		{
			cout << "---";
		}
		cout << "\n";

	}
}
template <typename T> T Matrice<T>::CalTrace()
{
	T TSum = 0;
	if ((*this).getRow() == (*this).getColumn())
	{
		for (int i = 0;i<(*this).getRow();i++)
		{
			TSum += this->getEntryIJ(i, i);
		}
	}
	else
	{
		cout << "This matrice not squre/ it isn't have trace" << endl;
		exit(0);
	}
	return TSum;
}
template <typename T> Matrice<T>* Matrice<T>::MultiplyByScaler(T Scaler)
{
	Matrice<T>* MBS;
	int row = (*this).getRow();
	int column = (*this).getColumn();
	MBS = new Matrice(column, row);
	for (int i = 0;i<row;i++)
	{
		for (int j = 0;j<column;j++)
		{
			MBS->setEntryIJ(i, j, Scaler*(this->getEntryIJ(i, j)));
		}
	}
	return MBS;
}

template <typename T> T Matrice<T>::getEntryIJ(int i, int j)
{
	return matrix[i][j];
}
template <typename T> void Matrice<T>::setEntryIJ(int i, int j,T Number)
{
	(*this).matrix[i][j] = Number;
}

template <typename T> Matrice<T>* Matrice<T>::Transpose()
{
	Matrice<T>* Tran;
	int row = (*this).getRow();
	int column = (*this).getColumn();
	Tran = new Matrice<T>(column, row);
	for (int i = 0;i<row;i++)
	{
		for (int j = 0;j<column;j++)
		{
			Tran->setEntryIJ(j, i, this->getEntryIJ(i, j));
		}
	}
	return Tran;
}
template<typename T> Matrice<T>* Matrice<T>::Subtract(Matrice<T> Matrix) {
	Matrice<T>* SubMatrix;
	if (((*this).getRow() == Matrix.getRow()) && ((*this).getColumn() == Matrix.getColumn()))
	{
		(SubMatrix) = new Matrice<T>(Matrix.getRow(), getColumn());
		for (int i = 0;i<Matrix.getRow();i++)
		{
			for (int j = 0;j<Matrix.getColumn();j++)
			{
				SubMatrix->setEntryIJ(i, j, (*this).getEntryIJ(i, j) - Matrix.getEntryIJ(i, j));
			}
		}
	}
	else
	{
		cout << "You can't add two Matrice" << endl;
		exit(0);
	}
	return (SubMatrix);
}


//////////////////////////////////////////////////
template <typename T> Matrice<T>* Matrice<T>::Add(Matrice<T> Matrix)
{
	Matrice<T>* Addmatrix;
	if (((*this).getRow() == Matrix.getRow()) && ((*this).getColumn() == Matrix.getColumn()))
	{
		(Addmatrix) = new Matrice<T>(Matrix.getRow(), getColumn());
		for (int i = 0;i<Matrix.getRow();i++)
		{
			for (int j = 0;j<Matrix.getColumn();j++)
			{
				Addmatrix->setEntryIJ(i, j, (*this).getEntryIJ(i, j) + Matrix.getEntryIJ(i, j));
			}
		}
	}
	else
	{
		cout << "You can't add two Matrice" << endl;
		exit(0);
	}
	return (Addmatrix);
}
/////////////////////////////////////////////////
template <typename T> void Matrice<T>::ReadfromFile(char* fileName)
{
	T sum;
	fstream myReadFile;
	myReadFile.open(fileName);
	int row = 0;
	int column = 1;
	sum=0;
	string line;
	if (myReadFile.is_open())
	{
		while (!myReadFile.eof())
		{
			getline(myReadFile, line);
			++row;
		}
		for ( int k = 0;k<line.length();k++)
			if (isspace(line[k]))
				column = column + 1;
		(*this).NumRow = row;
		(*this).NumColumn = column;
		matrix = new T*[NumRow];
		for (int i = 0; i < NumRow; ++i)
			matrix[i] = new T[NumColumn];
		myReadFile.clear();
		myReadFile.seekg(0, ios::beg);
		int i = 0;
		int j = 0;
		vector<string> vv;
		for(i=0;i<NumRow;i++)
		{
			getline(myReadFile, line);
			split(line,' ',vv);
			for(int jj=0;jj<NumColumn;jj++)
				matrix[i][jj]=numeric_cast<T>((boost::lexical_cast<long double>(vv[jj])));
			vv.clear();
			
		}

		/////////////////////////////////////////end if/////////////////////
	}
	else {
		cout << "File not open" << endl;
		cin.get();
		exit(0);
	}
	
	myReadFile.close();
}
template <typename T>  Matrice<T>* Matrice<T>::DeleteRow(int RowDelete)
{
	int	RowDelete1=RowDelete-1;
	Matrice<T>* RoWD;
	RoWD=new Matrice<T>((*this).getRow()-1,(*this).getColumn());
	for(int i=0;i<(*this).getRow();i++)
	{
		for(int j=0;j<(*this).getColumn();j++)
		{
			if(i<RowDelete1)
			{
				RoWD->setEntryIJ(i,j,(*this).getEntryIJ(i,j));
			}
			else if(i==RowDelete1)
			{
				continue;
			}
			else
			{
				RoWD->setEntryIJ(i-1,j,(*this).getEntryIJ(i,j));
			}
		}
	}
	return RoWD;
}
template <typename T> Matrice<T>* Matrice<T>::DeleteColumn(int ColumnDelete)
{
	int	ColumnDelete1=ColumnDelete-1;
	Matrice<T>* ColumnD;
	ColumnD=new Matrice<T>((*this).getRow(),(*this).getColumn()-1);
	for(int i=0;i<(*this).getColumn();i++)
	{
		for(int j=0;j<(*this).getRow();j++)
		{
			if(i<ColumnDelete1)
			{
				ColumnD->setEntryIJ(j,i,(*this).getEntryIJ(j,i));
			}
			else if(i==ColumnDelete1)
			{
				continue;
			}
			else
			{
				ColumnD->setEntryIJ(j,i-1,(*this).getEntryIJ(j,i));
			}
		}
	}
	return ColumnD;

}
template <typename T> Matrice<T>* Matrice<T>::DeleteRowColumn(int i,int j)
{
	return (*this).DeleteRow(i)->DeleteColumn(j);
}
template <typename T> T Matrice<T>::Determinant()
{
	T Deter=-1;
	if(NumColumn==NumRow)
	{
		if(NumColumn==2)
	{
		Deter=(((*this).getEntryIJ(0,0))*((*this).getEntryIJ(1,1)))-(((*this).getEntryIJ(0,1))*((*this).getEntryIJ(1,0)));
		return Deter;
	}
		else
		{
				Deter=0;
			for(int j=0;j<(*this).getColumn();j++)
				Deter+=pow(-1.0,1+j+1)*((*this).getEntryIJ(0,j))*((*(*this).DeleteRowColumn(1,j+1)).Determinant());
			return Deter;
		}
	
	}
 	else
	{
		cout<<"This matrix not have Determinant"<<endl;
		return Deter;
	}
	return Deter;
}
template <typename T> bool Matrice<T>::IsUpperTriangular()
{
	if(NumColumn==NumRow)
	{
	if(!(this->IsZero()))
	{
		for(int i=0;i<NumColumn;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(matrix[i][j]!=0)
				{
					return false;
				}
			}
		}
	}
	else
	{
		cout<<"This Matrix is Zero"<<endl;
			return false;
	}
	}
	else
	{
		cout<<"This Matrix is not squre"<<endl;
			return false;
	}
	return true;
}
template <typename T> bool Matrice<T>::IsLowerTriangular()
{
	if(NumColumn==NumRow)
	{
	if(!(this->IsZero()))
	{
		for(int i=0;i<NumColumn;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(matrix[j][i]!=0)
				{
					return false;
				}
			}
		}
	}
	else
	{
		cout<<"This Matrix is Zero"<<endl;
			return false;
	}
	}
	else
	{
		cout<<"This Matrix is not squre"<<endl;
			return false;
	}
	return true;
}
template <typename T> bool Matrice<T>::IsZero()
{
	for(int i=0;i<NumRow;i++)
	{
		for(int j=0;j<NumColumn;j++)
		{
			if(matrix[i][j]!=0)
			{
				return false;
			}
		}
	}
	return true;
}
template <typename T> Matrice<T>* Matrice<T>::Multiplication(Matrice<T> Matrix){
	Matrice<T>* MM;
	T Sum=0;
	if(this->getColumn()==Matrix.getRow())
	{
		MM=new Matrice<T>(this->getRow(),Matrix.getColumn());
		for(int i = 0; i <this->getRow(); ++i)
			 {
				 for(int j = 0; j <Matrix.getColumn(); ++j)
				 {
					 Sum=0;
					 for(int k = 0; k < this->getColumn(); ++k)
						{
							Sum += this->getEntryIJ(i,k) * Matrix.getEntryIJ(k,j);
						}
						MM->setEntryIJ(i,j,Sum);
					 
				 }
			 }
	}
	else
	{
		cout<<"You Can't Multiply This Matrices"<<endl;
			exit(0);
	}
	return MM;
}
template <typename T> Matrice<T>& Matrice<T>::operator=(Matrice&& other)
{
	if(this==NULL)
	{
		(*this)=new Matrice(other.getRow(),other.getColumn());
			for(int i=0;i<other.getRow();i++)
			{
				for(int j=0;j<other.getColumn();j++)
				{
					(*this).setEntryIJ(i,j,other.getEntryIJ(i,j));
				}
			}

	}
	else if(other.getColumn()==(*this).getColumn() && other.getRow()==(*this).getRow())
	{
		for(int i=0;i<other.getRow();i++)
			{
				for(int j=0;j<other.getColumn();j++)
				{
					(*this).setEntryIJ(i,j,other.getEntryIJ(i,j));
				}
			}
	}
	else
	{
		cout<<"You Can assign"<<SHOW(other)<<"To"<<SHOW((*this))<<endl;
	}
	return *this;
}
template <typename T> Matrice<T>::~Matrice(void)
{
	//delete *matrix;
}
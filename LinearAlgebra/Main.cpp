#include<iostream>
#include <boost/lexical_cast.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include "Matrice.cpp"
#include "Identity.cpp"
#define SHOW(a)  #a
using namespace std;
unsigned int decode(unsigned long int x)
{
	int x1=(x & 0x000000FF);
	int x2=((x & 0x0000FF00)>>8);
	int x3=((x & 0x00FF0000)>>16);
	int x4=((x & 0xFF000000)>>24);
	return (x1+x3)*(x2-x4);
}
void main()
{
	cout<<max(10,20);
	/*unsigned int f=(decode(145414379)+decode(85314657)+decode(16998321)+decode(431543177))/4;
	cout<<f<<endl;*/
	/*unsigned int r=19;
	unsigned int h = (r>>1) & 0x01;
	cout<<h;*/
	/*unsigned long int x=1852110092;
	int x1=(x & 0x000000FF);
	int x2=((x & 0x0000FF00)>>8);
	int x3=((x & 0x00FF0000)>>16);
	int x4=((x & 0xFF000000)>>24);
	cout<<x1<<endl;
	cout<<x2<<endl;
	cout<<x3<<endl;
	cout<<x4<<endl;*/
	/*Matrice<double> m(4,5,15);
	Matrice<double> mm(5,5,15);
	Identity<int> ii(6);*/
	//ii.PrintMatrix();
	/*m.Multiplication(mm)->PrintMatrix();*/
	/*Matrice<double> m1;
	Matrice<double> m2;
	cout<<SHOW(m);
	m.ReadfromFile("D:\\m.txt");
	m1.ReadfromFile("D:\\m1.txt");
	m.PrintMatrix();
	m1.PrintMatrix();
	m2=m;
	m2.PrintMatrix();*/
	

	
	//m.Multiplication(m1)->PrintMatrix();
	//m.PrintMatrix();
	//m2=m.Add(m1);
}
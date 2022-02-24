#include "Identity.h"

template <typename T> Identity<T>::Identity(void)
{
}
template <typename T> Identity<T>::Identity(int RC):Matrice<T>(RC,RC)
{
	SetDiagonalWithOne();
}
template <typename T> void Identity<T>::SetDiagonalWithOne()
{
	for(int i=0;i<this->getRow();i++)
	{
			this->setEntryIJ(i,i,1);
	}
	
}
template <typename T> void Identity<T>::fu()
{
	cout<<this->getColumn();
}
template <typename T> Identity<T>::~Identity(void)
{
}

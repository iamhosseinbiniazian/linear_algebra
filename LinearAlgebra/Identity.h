#pragma once
#include "Matrice.h"
template <typename T> class Identity:
 public Matrice<T>
{
protected:
	
public:
	Identity(void);
	Identity(int RC);
	void fu();
	void SetDiagonalWithOne();
	~Identity(void);
};


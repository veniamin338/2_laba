#pragma one
#include <iostream>
#include <cmath>

class TComplex
{
public:
	TComplex();
	TComplex(double re_, double im_);
	TComplex(const TComplex& p);
	double GetRe();
	double GetIm();
	double GetMod();
	double GetFi();
	void SetRe(double re_);
	void SerIm(double im_);
	TComplex operator + (TComplex& p);
	
	TComplex operator - (TComplex& p);
	TComplex operator * (TComplex& p);
	TComplex operator / (TComplex& p);
	TComplex& operator = (TComplex& p);
	bool operator == (TComplex& p);
	friend std::istream& operator >> (std::istream& istr_, TComplex& p);

	double ComplexMod();
	void Stepen(double s_);
	void PrintTrigon();
protected:
	double re;
	double im;
	double mod;
	double fi;


};


std::ostream& operator << (std::ostream& ostr_, TComplex& p);
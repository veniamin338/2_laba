#include "Complex.h"

TComplex::TComplex()
{
	re = 0.0;
	im = 0.0;
	mod = 0.0;
	fi = 0.0;
}

TComplex::TComplex(double re_, double im_)
{
	re = re_;
	im = im_;
	mod = (*this).ComplexMod();
	//mod = pow(((*this).re * (*this).re + (*this).im * (*this).im), (0.5));
	fi = atan(im_ / re_);
}

TComplex::TComplex(const TComplex& p)
{
	re = p.re;
	im = p.im;
	mod = p.mod;
	fi = p.fi;

}

double TComplex::GetRe()
{
	return re;
}

double TComplex::GetIm()
{
	return im;
}

double TComplex::GetMod()
{
	return mod;
}

double TComplex::GetFi()
{
	return fi;
}

void TComplex::SetRe(double re_)
{
	re = re_;
	(*this).ComplexMod();
	fi = atan((*this).im / re_);
	mod = (*this).ComplexMod();
	//mod = pow(((*this).re * (*this).re + (*this).im * (*this).im), (0.5));
}

void TComplex::SerIm(double im_)
{
	im = im_;
	(*this).ComplexMod();
	fi = atan(im_ / (*this).re);
	mod = (*this).ComplexMod();
	//mod = pow(((*this).re * (*this).re + (*this).im * (*this).im), (0.5));
}

TComplex TComplex::operator+(TComplex& p)
{
	TComplex res(*this);
	res.re += p.re;
	res.im += p.im;
	return res;
}

TComplex TComplex::operator-(TComplex& p)
{
	TComplex res(*this);
	res.re -= p.re;
	res.im -= p.im;
	return res;
}

TComplex TComplex::operator*(TComplex& p)
{
	//(a+ib)(c+il) = ac-bl +i(al+cb)
	TComplex res;
	res.re = re * p.re - im * p.im;
	res.im = re * p.im + p.re * im;
	return res;
}

TComplex TComplex::operator/(TComplex& p)
{
	TComplex res;
	res.re = (re * p.re + im * p.im)/((p.re*p.re) + (p.im*p.im));
	res.im = (- (re * p.im) + (p.re * im))/((p.re * p.re) + (p.im * p.im));

	return res;
}

TComplex& TComplex::operator=(TComplex& p)
{
	re = p.re;
	im = p.im;
	return *this;
}

bool TComplex::operator==(TComplex& p)
{
	return (re == p.re) && (im == p.im);
}

double TComplex::ComplexMod()
{
	double res = 0;
	res = pow(((*this).re * (*this).re + (*this).im * (*this).im), (0.5));
	return res;
}

void TComplex::Stepen(double s_)
{
	//TComplex res(*this);
	if (s_ == 0)
	{
		re = 1;
		im = 0;
	}
	else if (s_ < 0)
	{
		s_ = s_ * (-1);
		(*this).re = pow(mod, s_) * cos(fi * s_);
		(*this).im = pow(mod, s_) * sin(fi * s_);
		(*this) = TComplex(1, 0) / (*this);
	}
	else 
	{
		(*this).re = pow(mod, s_) * cos(fi * s_);
		(*this).im = pow(mod, s_) * sin(fi * s_);
	}
		//return res;
}

void TComplex::PrintTrigon()
{
	std::cout <<re<<"+("<<im<<")i = "<< mod << " (cos (" << fi << ") + sin (" << fi << "))" << std::endl;
}

std::istream& operator>>(std::istream& istr_, TComplex& p)
{
	std::cout << "Re = " << std::endl;
	istr_ >> p.re;
	std::cout << "Im = " << std::endl;
	istr_ >> p.im;
	return istr_;
}

std::ostream& operator<<(std::ostream& ostr_, TComplex& p)
{
	ostr_ << p.GetRe() << " + " << p.GetIm() << "i\n";
	return ostr_;
}


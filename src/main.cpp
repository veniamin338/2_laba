#include <iostream>
#include "Complex.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	TComplex a(13, 18);
	TComplex a1(a);
	TComplex b(35, 39);
	TComplex b1(b);
	TComplex c(b);
	TComplex c1(b);
	c.SetRe(2);
	c.SerIm(3);
	

	cin >> a1;// ��������� ����
	cin >> b1;

	
	
	c1 = a1 + b1;
	
	cout << c1;// ��������� �����
	
	c1 = a1 - b1;
	
	cout << c1;
	
	c1 = a1 * b1;
	
	cout << c1;
	
	c1 = a1 / b1;
	
	cout << c1;
	
	
	
	c.Stepen(-5);//������������������ ���������� ������������ ����� � ������������� ����� �������
	cout << c << endl;
	c.Stepen(5);//������������������ ���������� ������������ ����� � ������������� ����� �������
	cout << c << endl;
	c.PrintTrigon();
	double k;
	k = a.ComplexMod();// ������������������ ���������� ������ ������������ �����
	cout << k << endl;
	
	return 0;

}

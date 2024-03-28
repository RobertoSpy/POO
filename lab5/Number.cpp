#include "Number.h"
#include <iostream>

using namespace std;

Number::~Number()
{
	delete[] ar;
}

Number::Number()
{
	this->nr = 0;
	this->b = 0;
}
Number::Number(const char* value, int base)
{
	int k = 0;
	for (int i = 0; value[i] != 0; i++)
	{
		k = k * b + value[i] - '0';
		this->nr = this->nr*10 + k;
	}
	this->b = base;
}
void Number::SwitchBase(int newBase)
{
	int Rest, Format = 0, P = 1,Format2=0;
	int Numar = this->nr;
	if (this->b != newBase)
	{
		if (this->b != 10)
		{
			while (Numar != 0)
			{
				Rest = Numar % 10;
				Numar /= 10;
				Format = Format + Rest * P;
				P *= this->b;
			}
			P = 1;
		}
		if (newBase != 10)
		{
			while (Format != 0)
			{
				Rest = Format % newBase;
				Format /= newBase;
				Format2 = Format2 + Rest * P;
				P *= 10;
			}
			this->nr = Format2;
		}
		else this->nr = Format;
	}
}
void Number::Print()
{
	cout<<this->nr<<" ";
}

int Number::GetDigitsCount()
{
	int c = 0;
	while (this->nr != 0)
	{
		this->nr = this->nr / 10;
		c++;
	}
	return c;

}
int Number::GetBase()
{
	return this->b;
}
int Number::operator + (Number a)
{
	int Rest, Format, P, Format2, Numar;
	if (this->b < a.b)
	{
		SwitchBase(a.b);
    }
	else if (this->b > a.b)
	{
		int Rest, Format = 0, P = 1, Format2 = 0;
		int Numar = a.nr;
		if (a.b != 10)
		{
			while (Numar != 0)
			{
				Rest = Numar % 10;
				Numar /= 10;
				Format = Format + Rest * P;
				P *= a.b;
			}
			P = 1;
		}
		if (this->b != 10)
		{
			while (Format != 0)
			{
				Rest = Format % this->b;
				Format /= this->b;
				Format2 = Format2 + Rest * P;
				P *= 10;
			}
			a.nr = Format2;
		}
		else a.nr = Format;
		a.b = this->b;
	}
	int k;
	k = this->nr + a.nr;
	P = 1;
	Format = 0;
	while (k != 0)
	{
		Rest = k % 10;
		k /= 10;
		Format = Format + Rest * P;
		P *= a.b;
	}
	return Format;
}
int Number::operator > (Number a)
{
	if (this->b < a.b)
	{
		SwitchBase(a.b);
	}
	else if (this->b > a.b)
	{
		int Rest, Format = 0, P = 1, Format2 = 0;
		int Numar = a.nr;
		if (a.b != 10)
		{
			while (Numar != 0)
			{
				Rest = Numar % 10;
				Numar /= 10;
				Format = Format + Rest * P;
				P *= a.b;
			}
			P = 1;
		}
		if (this->b != 10)
		{
			while (Format != 0)
			{
				Rest = Format % this->b;
				Format /= this->b;
				Format2 = Format2 + Rest * P;
				P *= 10;
			}
			a.nr = Format2;
		}
		else a.nr = Format;
		a.b = this->b;
	}
	if (this->nr > a.nr)
		return 1;
	else 
		return 0;
}
int Number::operator < (Number a)
{
	if (this->b < a.b)
	{
		SwitchBase(a.b);
	}
	else if (this->b > a.b)
	{
		int Rest, Format = 0, P = 1, Format2 = 0;
		int Numar = a.nr;
		if (a.b != 10)
		{
			while (Numar != 0)
			{
				Rest = Numar % 10;
				Numar /= 10;
				Format = Format + Rest * P;
				P *= a.b;
			}
			P = 1;
		}
		if (this->b != 10)
		{
			while (Format != 0)
			{
				Rest = Format % this->b;
				Format /= this->b;
				Format2 = Format2 + Rest * P;
				P *= 10;
			}
			a.nr = Format2;
		}
		else a.nr = Format;
		a.b = this->b;
	}
	if (this->nr < a.nr)
		return 1;
	else 
		return 0;
}
void Number::operator=(int x)
{
	if(this->b==0||this->b==10)
	{
		this->nr = x;
		this->b = 10;
	}
	else
	{
		int Rest, Format = 0, P = 1;
		int Numar =x;
			while (x != 0)
			{
				Rest = x % this->b;
				x /= this->b;
				Format = Format + Rest * P;
				P *= 10;
			}
			x = Format;
			this->nr = x;
	}
}
void Number::operator--()
{
	int x = this->nr;
	int k = 1;
	int y = GetDigitsCount();
	for (int i = 1; i < y; i++)
		 k = k * 10;
	x = x % k;
	this->nr = x;
}
void Number::operator--(int)
{
	this->nr = this->nr / 10;
}
int Number::operator- (Number a)
{
	int Rest, Format, P, Format2, Numar;
	if (this->b < a.b)
	{
		SwitchBase(a.b);
	}
	else if (this->b > a.b)
	{
		int Rest, Format = 0, P = 1, Format2 = 0;
		int Numar = a.nr;
		if (a.b != 10)
		{
			while (Numar != 0)
			{
				Rest = Numar % 10;
				Numar /= 10;
				Format = Format + Rest * P;
				P *= a.b;
			}
			P = 1;
		}
		if (this->b != 10)
		{
			while (Format != 0)
			{
				Rest = Format % this->b;
				Format /= this->b;
				Format2 = Format2 + Rest * P;
				P *= 10;
			}
			a.nr = Format2;
		}
		else a.nr = Format;
		a.b = this->b;
	}
	int k;
	k = this->nr - a.nr;
	P = 1;
	Format = 0;
	while (k != 0)
	{
		Rest = k % 10;
		k /= 10;
		Format = Format + Rest * P;
		P *= a.b;
	}
	return Format;
}
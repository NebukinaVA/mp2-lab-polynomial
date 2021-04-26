#pragma once

#include <iostream>
#include <string>

class Monomial
{
public:
	int deg;
	int coeff;
	int xDeg()
	{
		return (deg / 100);
	}
	int yDeg()
	{
		return ((deg / 10) % 10);
	}
	int zDeg()
	{
		return ((deg % 100) % 10);
	}
	Monomial()
	{
		deg = 0;
		coeff = 0;
	}
	Monomial(int d, int c) 
	{
		if ((d < 0) || (d > 999)) throw "Error";
		deg = d;
		coeff = c;
	}
	Monomial(const Monomial& m)
	{
		deg = m.deg;
		coeff = m.coeff;
	}
	Monomial(std::string monom)  //example: 10x^2y^8z^4
	{
		if (!IsCorrect(monom)) throw "Wrong monomial";
		std::string xyz = "xyz";
		deg = 0;
		coeff = 1;
		int len = monom.length();
		if (xyz.find(monom[0]) == std::string::npos)
			coeff = std::stod(monom);
		for (int i = 0; i < len; i++)
		{
			if (monom[i] == 'x')
			{
				if (xyz.find(monom[i + 1]) != std::string::npos)
					deg += 100;
				else if (monom[i + 1] == '\0')
					deg += 100;
				else
					deg += 100 * (monom[i + 1] - 48);
			}
			if (monom[i] == 'y')
			{
				if (xyz.find(monom[i + 1]) != std::string::npos)
					deg += 10;
				else if (monom[i + 1] == '\0')
					deg += 10;
				else
					deg += 10 * (monom[i + 1] - 48);
			}
			if (monom[i] == 'z')
			{
				if (xyz.find(monom[i + 1]) != std::string::npos)
					deg++;
				else if (monom[i + 1] == '\0')
					deg++;
				else
					deg += (monom[i + 1] - 48);
			}
		}
		
	}
	bool IsCorrect(std::string monom)
	{
		std::string letters = "xyz";
		int i = 0;
		if (monom[0] == '-') 
			i++;
		int cond = 0; // condition
		while ((cond != 3) && (cond != 4))
		{
			switch (cond)
			{
			case 0:
			{
				cond = 3;
				if ((monom[i] >= '0') && (monom[i] <= '9'))
				{
					cond = 1;
					int dot = 0;
					while (((monom[i + 1] >= '0') && (monom[i + 1] <= '9')) || (monom[i + 1] == '.'))
					{
						i++;
						if (monom[i] == '.')
						{
							dot++;
							if (monom[i + 1] == '.') dot--;
						}
					}
					if ((dot > 1) || (monom[i] == '.')) cond = 3;
				}
				if (letters.find(monom[i]) != std::string::npos)
					cond = 1;
				break;
			}
			case 1:
			{
				cond = 3;
				if (letters.find(monom[i]) != std::string::npos)
					cond = 2;
				if (monom[i] == '\0') 
					cond = 4;
				break;
			}
			case 2:
			{
				cond = 3;
				if (letters.find(monom[i]) != std::string::npos)
					cond = 2;
				if ((monom[i] >= '0') && (monom[i] <= '9'))
					cond = 1;
				if (monom[i] == '\0')
					cond = 4;
				break;
			}
			default: break;
			}
			i++;
		}
		if (cond == 4) return true;
		return false;
	}

	bool operator==(const Monomial &m) const
	{
		return ((coeff == m.coeff) && (deg == m.deg));
	}
	bool operator!=(const Monomial &m) const
	{
		return !(*this == m);
	}
	Monomial& operator+(const Monomial &m)
	{
		if (deg != m.deg) throw "Unequal degrees";
		Monomial temp(deg, coeff + m.coeff);
		return temp;
	}
	Monomial& operator*(Monomial &m)
	{
		if ((xDeg() + m.xDeg()) > 9) throw "Error";
		if ((yDeg() + m.yDeg()) > 9) throw "Error";
		if ((zDeg() + m.zDeg()) > 9) throw "Error";
		Monomial temp(deg + m.deg, coeff * m.coeff);
		return temp;
	}
	Monomial& operator-(const Monomial &m)
	{
		if (deg != m.deg) throw "Unequal degrees";
		Monomial temp(deg, coeff - m.coeff);
		return temp;
	}
	bool operator> (const Monomial& m) const // для сортировки по степеням
	{
		return (deg > m.deg);
	}
	bool operator< (const Monomial& m) const
	{
		return (deg < m.deg);
	}
	friend std::ostream& operator<<(std::ostream &out, Monomial &m)
	{
		out << m.coeff;
		out << "x";
		out << m.xDeg();
		out << "y";
		out << m.yDeg();
		out << "z";
		out << m.zDeg();
		return out;
	}
};


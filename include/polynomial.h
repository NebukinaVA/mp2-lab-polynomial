#pragma once

#include <iostream>
#include <string>
#include "list.h"
#include "monomial.h"

class Polynomial : public List<Monomial>
{
public:
	Polynomial() : List<Monomial>()
	{
	}
	Polynomial(const Polynomial& pol) : List<Monomial>() 
	{
	}
	Polynomial(std::string str)
	{
		Polynomial polynom;
		std::string temp;
		if (!IsCorrect(str)) throw "Incorrect string";
		int len = str.length();
		int i = 0;
		while (i < len)
		{
			temp.clear();
			while ((str[i] != '+') && (str[i] != '-') && (str[i] != '\0'))
			{
				temp += str[i];
				i++;
			}
			if (!temp.empty()) 
			{
				Monomial mon(temp);
				polynom.push_back(mon);
			}
			i++;
		}
	}
	bool IsCorrect(std::string str)
	{
		int len = str.length();
		if (len == 0) return false;
		int i = 0;
		std::string temp; 
		Monomial mon;
		while (i < len)
		{
			temp.clear();
			while ((str[i] != '+') && (str[i] != '-') && (str[i] != '\0'))
			{
				if (str[i] == '+') i++;
				temp += str[i];
				i++;
			}
			if (!mon.IsCorrect(temp)) return false;
			if (i < len)
				if (str[i + 1] == '\0') return false;
			i++;
		}
		return true;
	}
	Polynomial operator*(Monomial &m)  // P*M
	{
		Polynomial temp;
		Polynomial::Iterator it = begin();
		while (it != end())
		{
			temp.push_back(m*it->data);
			++it;
		}
		return temp;
	}
	Polynomial operator+(Monomial &m)  // P+M
	{
		Polynomial temp(*this);
		temp.push_back(m);
		return temp;
	}
	Polynomial operator+(Polynomial &p)  // P+P
	{
		Polynomial temp;
		Polynomial::Iterator it1 = begin();
		Polynomial::Iterator it2 = p.begin();
		while (it1 != end())
		{
			// 
		}
		// + sort polynomial
	}
	Polynomial operator*(Polynomial &p)  // P*P
	{
		Polynomial temp;
		Polynomial::Iterator it = begin();
		while (it != end())
		{
			temp = temp + (*this) * it->data;
			++it;
		}
		return temp;
	}	
	friend std::ostream& operator<<(std::ostream &out, Polynomial &p)
	{
		Polynomial::Iterator it = p.begin();
		out << it->data;
		while (it != p.end())
		{
			out << "+" << it->data;
			++it;
		}
		return out;
	}
};

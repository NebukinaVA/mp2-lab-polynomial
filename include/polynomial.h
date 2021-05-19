#pragma once

#include <iostream>
#include <string>
#include "list.h"
#include "monomial.h"

class Polynomial
{
public:
	List<Monomial> polynom;
	Polynomial() {}
	Polynomial(const Polynomial& pol)
	{
		polynom = pol.polynom;
	}
	Polynomial(std::string str)
	{
		std::string temp;
		if (!IsCorrect(str)) throw "Incorrect string";
		int len = str.length();
		int i = 0;
		if (str[0] == '-')
		{
			temp += '-';
			i++;
		}
		while (i < len)
		{
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
			temp.clear();
			if (str[i] == '-')
			{
				temp += '-';
				i++;
			}
			else
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
			if ((i == 0) && (str[i] == '-'))
			{
				temp += '-';
				i++;
			}
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
		List<Monomial>::Iterator it1 = polynom.begin();
		List<Monomial>::Iterator it2 = temp.polynom.begin();
		temp.polynom.append(m*(it1->data), it2.get_node());
		++it1;
		it2 = temp.polynom.begin();
		while (it1 != polynom.end())
		{
			temp.polynom.append(m*(it1->data), it2.get_node());
			++it1;
			++it2;
		}
		return temp;
	}
	Polynomial operator+(Monomial &m)  // P+M
	{
		Polynomial temp(*this);
		List<Monomial>::Iterator it1(temp.polynom.begin()), it2(it1);
		while (it1 != temp.polynom.end())
		{
			if (it1->data.get_deg() == m.get_deg())
			{
				if ((it1->data.coeff + m.coeff) != 0)
				{
					temp.polynom.change_node(it1->data + m, it1.get_node());
				}
				else
				{
					temp.polynom.remove(it1.get_node());
				}
				break;
			}
			else if (it1->data < m)
			{
				if (it1 == temp.polynom.begin())
				{
					temp.polynom.push_front(m);
				}
				else 
				{
					temp.polynom.append(m, it2.get_node());
				}
				break;
			}
			if (it1->next == nullptr)
			{
				temp.polynom.push_back(m);
				break;
			}
			it2 = it1;
			++it1;
		}
		return temp;
	}
	Polynomial operator+(Polynomial &p)  // P+P
	{
		Polynomial temp(*this);
		if (!(p.polynom.empty()))
		{
			if (!(polynom.empty()))
			{
				List<Monomial>::Iterator it1(temp.polynom.begin()), it2(p.polynom.begin());
				List<Monomial>::Iterator node(it1);
				while ((it1 != temp.polynom.end()) && (it2 != p.polynom.end()))
				{
					if (it1->data > it2->data)
					{
						if (it1->next == nullptr)
						{
							temp.polynom.append(it2->data, it1.get_node());
							it2++;
						}
						it1++;
					}
					else if (it1->data < it2->data)
					{
						if ((it1 == temp.polynom.begin()))
						{
							temp.polynom.push_front(it2->data);
							it1++;
							it2++;
							node = temp.polynom.begin();
						}
						else
						{
							temp.polynom.append(it2->data, node.get_node());
							node = it1;
							it1++;
							it2++;
						}
					}
					else if ((it1->data.coeff + it2->data.coeff) != 0)
					{
						temp.polynom.change_node(it1->data + it2->data, it1.get_node());
						node = it1;
						it1++;
						it2++;
					}
					else
					{
						temp.polynom.remove(node.get_node());
						node = it1;
						it1++;
						it2++;
					}
					
				}
				
			}
			else temp = p;
		}
		return temp;
	}
	Polynomial operator*(Polynomial &p)  // P*P
	{
		Polynomial temp;
		List<Monomial>::Iterator it = p.polynom.begin();
		while (it != p.polynom.end())
		{
			temp = temp + ((*this) * it->data);
			++it;
		}
		return temp;
	}

	Polynomial operator*(double c)  // P*const
	{
		Polynomial temp;
		List<Monomial>::Iterator it = polynom.begin();
		while (it != polynom.end())
		{
			temp.polynom.push_back(it->data * c);
			++it;
		}
		return temp;
	}

	Polynomial operator-(Polynomial &p)  // P-P
	{
		return (*this + p * (-1));
	}

	Polynomial operator=(Polynomial &p) 
	{
		polynom = p.polynom;
		return *this;
	}

	bool operator==(Polynomial &p)
	{
		return (polynom == p.polynom);
	}

	friend std::ostream& operator<<(std::ostream &out, Polynomial &p)
	{
		List<Monomial>::Iterator it = p.polynom.begin();
		out << it->data;
		++it;
		while (it != p.polynom.end())
		{

			if (it->data.coeff > 0) out << "+";
			out << it->data;
			++it;
		}
		return out;
	}
};

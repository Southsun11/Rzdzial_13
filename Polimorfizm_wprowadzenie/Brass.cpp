#include "Brass.h"
#include <iostream>
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);
Brass::Brass(const std::string& s , long an , double bal )
{
	this->m_fullName = s;
	this->m_acctNum = an;
	this->m_balance = bal;
}

void Brass::deposit(double amt)
{
	if (amt < 0)
		std::cout << "Nie mozna wplacic ujemnej kwoty\n";
	else
		m_balance += amt;

}
void Brass::withdraw(double amt)
{
	format initialState = setFormat();
	precis  prec = std::cout.precision(2);
	if (amt < 0)
		std::cout << "NIe mozna wyplacic ujemnej kwoty\n";
	else if (amt <= this->m_balance)
		this->m_balance -= amt;
	else
		std::cout << "Zadana suma przekracza dostepne srodki\n";
	restore(initialState, prec);

}

double Brass::balance()const
{
	return m_balance;
}
void Brass::viewAcct() const
{
	format initialState = setFormat();
	precis prec = std::cout.precision(2);
	std::cout << "Klient: " << m_fullName << std::endl;
	std::cout << "Numer rachunki: " << m_acctNum << std::endl;
	std::cout << "Stan konta: " << m_balance << " zl" << std::endl;
	restore(initialState, prec);
}
Brass::~Brass()
{

}

BrassPlus::BrassPlus(const std::string& s , long an , double bal , double ml, double r ):
	Brass(s,an,bal),m_maxLoan(ml),m_oweBank(0.0),m_rate(r)
{}
BrassPlus::BrassPlus(const Brass& bs, double ml , double r ) : Brass(bs), m_maxLoan(ml), m_oweBank(0.0), m_rate(0.0)
{}
void BrassPlus::viewAcct()const
{
	format initialState = setFormat();
	precis prec = std::cout.precision(2);
	Brass::viewAcct();
	std::cout << "Limit debetu: " << m_maxLoan << " zl\n";
	std::cout << "Kwota zadluzenia: " << m_oweBank << " zl\n";
	std::cout.precision(5);
	std::cout << "Stopa oprocentowania: " << m_rate << std::endl;
	restore(initialState, prec);
}
void BrassPlus::withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = std::cout.precision(2);
	double bal = balance();
	if (amt <= bal)
		Brass::withdraw(amt);
	else if (amt <= bal + m_maxLoan - m_oweBank)
	{
		double advance = amt - bal;
		m_oweBank += advance * (1.0 + m_rate);
		std::cout << "Zadluzenie faktyczne: " << advance << " zl\n";
		std::cout << "Odsetki: " << advance * m_rate << " zl\n";
		deposit(advance);
		Brass::withdraw(amt);
	}
	else
			std::cout << "Przekroczylismy limit debetu \n";
}

format setFormat()
{
	return std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	std::cout.setf(f, std::ios_base::floatfield);
	std::cout.precision(p);
}






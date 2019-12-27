#include "Brass.h"

AcctABC::AcctABC(const std::string& s, long an, double bal)
{
	m_fullname = s;
	m_acctNum = an;
	m_balance = bal;
}

void AcctABC::deposit(double amt)
{
	if (amt < 0)
		std::cout << "Nie mozesz wplacic ujemnej kwoty, wyplata anulowana\n";
	else
		m_balance += amt;

}

void AcctABC::withdraw(double amt)
{
	m_balance -= amt;
}

AcctABC::Formatting AcctABC::setformat() const
{
	Formatting f;
	f.flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	f.pr = std::cout.precision(2);
	return f;
}

void AcctABC::restore(Formatting& f) const
{
	std::cout.setf(f.flag, std::ios_base::floatfield);
	std::cout.precision(f.pr);
}
void Brass::withdraw(double amt)
{
	if (amt < 0)
		std::cout << "NIe mozna wyplacic ujemnej kwoty, transakcja anulowana\n";
	else if (amt <= balance())
		AcctABC::withdraw(amt);
	else
		std::cout << "zatana wartosc " << amt << "przekracza dostepne srodki\n";
}

void Brass::viewAcct()const
{
	Formatting f = setformat();
	std::cout << "Wlasciciel rachunku Brass: " << fullName() << std::endl;
	std::cout << "Numer rachunku: " << acctNum() << std::endl;
	std::cout << "Stan konta: " << balance() << std::endl;
	restore(f);
}

BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r) : AcctABC(s, an, bal), m_maxLoan(ml), m_owesBank(0.0), m_rate(r)
{}
BrassPlus::BrassPlus(const Brass& ba, double ml, double r) : AcctABC(ba), m_maxLoan(ml), m_owesBank(0.0), m_rate(r)
{
}
void BrassPlus::viewAcct() const
{
	Formatting f = setformat();
	std::cout << "Wlasciciele rachunku BrassPlus: " << fullName() << std::endl;
	std::cout << "Numer rachunku: " << acctNum() << std::endl;
	std::cout << "Stan konta: " << balance() << std::endl;
	std::cout << "Limit debety: " << m_maxLoan << std::endl;
	std::cout << "Kwota zadluzenia: " << m_owesBank << std::endl;
	std::cout.precision(5);
	std::cout << "Stopa oprocentowania: " << 100 * m_rate << "%\n";
	restore(f);
}

void BrassPlus::withdraw(double amt)
{
	Formatting f = setformat();
	double bal = balance();
	if (amt <= bal)
		AcctABC::withdraw(amt);
	else if (amt <= bal + m_maxLoan - m_owesBank)
	{
		double advance = amt - bal;
		m_owesBank += advance * (1.0 + m_rate);
		std::cout << "Zadluzenie faktycze: " << advance << " zl" << std::endl;
		std::cout << "Odsetki: " << advance * m_rate << " zl" << std::endl;
		deposit(advance);
		AcctABC::withdraw(amt);

	}
	else
		std::cout << "Przekroczymy limit debet. Operacja anulowana.\n";
	restore(f);
}
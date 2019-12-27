#pragma once
#include <string>
class Brass
{
private:
	std::string m_fullName;
	long m_acctNum;
	double m_balance;
public:
	Brass(const std::string& s = "brak", long an = -1, double bal = 0.0);
	void deposit(double amt);
	virtual void withdraw(double amt);
	double balance()const;
	virtual void viewAcct() const;
	virtual ~Brass();
};

class BrassPlus : public Brass
{
private:
	double m_maxLoan;
	double m_rate;
	double m_oweBank;
public:
	BrassPlus(const std::string& s = "brak", long an = -1, double bal = 0.0, double ml = 2000, double r = 0.11125);
	BrassPlus(const Brass& bs, double ml = 2000, double r = 0.11125);
	virtual void viewAcct()const;
	virtual void withdraw(double amt);
	void resetMax(double m) { m_maxLoan = m; }
	void resetRate(double r) { m_rate = r; }
	void resetOwes() { m_oweBank = 0; }


};


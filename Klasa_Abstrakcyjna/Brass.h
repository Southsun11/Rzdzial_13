#pragma once
#include <string>
#include <iostream>

class AcctABC
{
private:
	std::string m_fullname;
	long m_acctNum;
	double m_balance;
protected:
	struct Formatting {
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string& fullName() const { return m_fullname; }
	long acctNum() const { return m_acctNum; }
	Formatting setformat()const;
	void restore(Formatting & f) const;
public:
	AcctABC(const std::string& s = "brak", long an = -1, double bal = 0.0);
	void deposit(double amt);
	virtual void withdraw(double amt) = 0;
	double balance() const { return m_balance; }
	virtual void viewAcct() const = 0;
	virtual ~AcctABC() {};
};


class Brass : public AcctABC
{
public:
	Brass(const std::string& s = "brak", long an = -1, double bal = 0.0) :AcctABC(s, an, bal) {}
	virtual void withdraw(double amt);
	virtual void viewAcct() const;
	virtual ~Brass() {};
};
class BrassPlus : public AcctABC
{
private:
	double m_maxLoan;
	double m_rate;
	double m_owesBank;
public:
	BrassPlus(const std::string& s = "brak", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.10);
	virtual void viewAcct()const;
	virtual void withdraw(double amt);
	void reset(double m) { m_maxLoan = m; }
	void resetRate(double r) { m_rate = r; }
	void resetOwes() { m_owesBank; }
};


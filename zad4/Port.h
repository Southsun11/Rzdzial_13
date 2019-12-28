#pragma once
#include <iostream>
class Port
{
private:
	char* m_brand;
	char m_style[20];
	int m_bottles;
public:
	Port(const char* b = "Brak", const char* st = "Brak", int n = 0);
	Port(const Port& p);
	virtual ~Port();
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int bottleCount() const;
	virtual void show() const;
	friend std::ostream& operator<<(std::ostream& os, const Port& p);
};

class VintagePort : public Port
{
private:
	char* m_nickname;
	int m_year;
public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	virtual ~VintagePort();
	VintagePort& operator=(const VintagePort& vp);
	void show() const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& p);
};



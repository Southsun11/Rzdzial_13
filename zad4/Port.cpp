#include "Port.h"

Port::Port(const char* b , const char* st , int n)
{
	int size = strlen(b) + 1;
	this->m_brand = new char[size];
	strncpy_s(this->m_brand, size, b, size - 1);
	strncpy_s(this->m_style, 20, st, 19);
	m_bottles = n;
}
Port::Port(const Port& p)
{
	int size = strlen(p.m_brand)+1;
	this->m_brand = new char[size];
	strncpy_s(this->m_brand, size, p.m_brand, size - 1);
	strncpy_s(this->m_style, 20, p.m_style, 19);
	this->m_bottles = p.m_bottles;
}
Port::~Port()
{
	delete[] this->m_brand;
}
Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return *this;
	delete [] this->m_brand;
	int size = strlen(p.m_brand) + 1;
	this->m_brand = new char[size];
	strncpy_s(this->m_brand, size, p.m_brand, size - 1);
	strncpy_s(this->m_style, 20, p.m_style, 19);
	this->m_bottles = p.m_bottles;
	return *this;
}
Port& Port::operator+=(int b)
{
	this->m_bottles += b;
	return *this;
}
Port& Port::operator-=(int b)
{
	if (b > this->m_bottles)
		std::cout << "Brak wystarczajcej liczby butelek\n";
	else
		this->m_bottles -= b;
	return *this;
}
int Port::bottleCount() const
{
	return this->m_bottles;
}
void Port::show() const
{
	std::cout << "Marka: " << this->m_brand << std::endl;
	std::cout << "Rodzaj: " << this->m_style << std::endl;
	std::cout << "Butelek: " << this->m_bottles << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.m_brand << ", " << p.m_style << ", " << p.m_bottles;
	return os;
}

VintagePort::VintagePort():Port()
{
	this->m_nickname = new char[2];
	this->m_nickname[0] = 'B';
	this->m_nickname[1] = '\0';
	this->m_year = 0;
}
VintagePort::VintagePort(const char* br, int b, const char* nn, int y) :Port(br, "najlepszy rocznik", b)
{
	int size = strlen(nn) + 1;
	this->m_nickname = new char[size];
	strncpy_s(this->m_nickname, size, nn, size - 1);
	this->m_year = y;
}
VintagePort::VintagePort(const VintagePort& vp):Port(vp)
{
	int size = strlen(vp.m_nickname) + 1;
	this->m_nickname = new char[size];
	strncpy_s(this->m_nickname, size, vp.m_nickname, size - 1);
	this->m_year = vp.m_year;

}
VintagePort::~VintagePort()
{
	delete[] this->m_nickname;
}
VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
		return *this;
	delete this->m_nickname;
	int size = strlen(vp.m_nickname) + 1;
	this->m_nickname = new char[size];
	strncpy_s(this->m_nickname, size, vp.m_nickname, size - 1);
	this->m_year = vp.m_year;
	return *this;
}
void VintagePort::show() const
{
	Port::show();
	std::cout << "Nazwa: " << this->m_nickname << std::endl;
	std::cout << "Rocznik: " << this->m_year << std::endl;
}
std::ostream& operator<<(std::ostream& os, const VintagePort& p)
{
	os << (const Port&)p << ", " << p.m_nickname << ", " << p.m_year;
	return os;
}
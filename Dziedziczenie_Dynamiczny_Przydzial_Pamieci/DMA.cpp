#include "DMA.h"
#include <cctype>
BaseDMA::BaseDMA(const char* l , int r)
{
	int size = strlen(l) + 1;
	m_label = new char[size];
	strncpy_s(m_label, size, l, size);
	m_rating = r;
	}
BaseDMA::BaseDMA(const BaseDMA& b)
{
	int size = strlen(b.m_label) + 1;
	this->m_label = new char[size];
	strncpy_s(this->m_label, size, b.m_label, size);
	this->m_rating = b.m_rating;
}
BaseDMA::~BaseDMA()
{
	delete[] this->m_label;
}
BaseDMA& BaseDMA::operator=(const BaseDMA& b)
{
	if (this == &b)
		return *this;
	delete[] this->m_label;
	int size = strlen(b.m_label) + 1;
	this->m_label = new char[size];
	strncpy_s(this->m_label, size, b.m_label, size);
	this->m_rating = b.m_rating;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const BaseDMA& b)
{
	os << "Etykieta: " << b.m_label << std::endl;
	os << "Klasa: " << b.m_rating << std::endl;
	return os;
}



LackDMA::LackDMA(const char* l , const char* c , int r ): BaseDMA(l, r)
{
	std::cout << strlen(c) << std::endl;
	strncpy_s(color, COL_LEN, c, COL_LEN - 1 ); //sprawdzic 
	//std::cout << strlen(color) << std::endl;
	color[39] = '\0';
	std::cout << strlen(color)  << std::endl;
}
LackDMA::LackDMA(const BaseDMA& b, const char* c):BaseDMA(b)
{
	strncpy_s(color, COL_LEN, c, COL_LEN -1);
	color[39] = '\0';
}
std::ostream& operator<<(std::ostream& os, const LackDMA& b)
{
	os << (const BaseDMA & )b;
	os << "Kolor: " << b.color << std::endl;;
	return os;
}


	HasDMA::HasDMA(const char* l , const char* s, int r ) :BaseDMA(l, r)
	{
		int size = strlen(s) + 1;
		style = new char[size];
		strncpy_s(style,size, s, size);
	}
HasDMA::HasDMA(const HasDMA& b,const char* s ):BaseDMA(b)
{
	int size = strlen(s) + 1;
	style = new char[size];
	strncpy_s(style,size, s, size);
	//strncpy_s(style, s, size);
}
HasDMA::HasDMA(const HasDMA& h):BaseDMA(h)
{
	int size = strlen(h.style) + 1;
	this->style = new char[size];
	strncpy_s(this->style, size, h.style, size);

}
HasDMA::~HasDMA()
{
	delete[] this->style;
}
HasDMA& HasDMA::operator=(const HasDMA& h)
{
	if (this == &h)
		return *this;
	BaseDMA::operator=(h);//sprawdzic *this = hs
	delete[] style;
	int size = strlen(h.style) + 1;
	this->style = new char[size];
	strncpy_s(this->style, size, h.style, size);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const HasDMA& h)
{
	os << (const BaseDMA&)h;
	os << "Style: " << h.style << std::endl;
	return os;
}

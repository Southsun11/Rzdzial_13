#include "DMA.h"
#include <cctype>

DMA::DMA(const char* l, int r)
{
	int size = strlen(l) + 1;
	m_label = new char[size];
	strncpy_s(m_label, size, l, size);
	m_rating = r;
}
DMA::DMA(const DMA& b)
{
	int size = strlen(b.m_label) + 1;
	this->m_label = new char[size];
	strncpy_s(this->m_label, size, b.m_label, size);
	this->m_rating = b.m_rating;
}
DMA::~DMA()
{
	delete[] this->m_label;
}
DMA& DMA::operator=(const DMA& b)
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
std::ostream& operator<<(std::ostream& os, const DMA& b)
{
	os << "Etykieta: " << b.m_label << std::endl;
	os << "Klasa: " << b.m_rating << std::endl;
	return os;
}


BaseDMA::BaseDMA(const char* l, int r):DMA(l,r)
{
}
BaseDMA::BaseDMA(const BaseDMA& b):DMA(b)
{	
}
BaseDMA::~BaseDMA()
{
}
BaseDMA& BaseDMA::operator=(const BaseDMA& b)
{
	if (this == &b)
		return *this;
	DMA::operator=(b);
	return *this;
}
std::ostream& operator<<(std::ostream& os, const BaseDMA& b)
{
	os << (const DMA&)b << std::endl;
	return os;
}


LackDMA::LackDMA(const char* l, const char* c, int r) : DMA(l, r)
{
	strncpy_s(color, COL_LEN, c, COL_LEN - 1); 
	color[39] = '\0';
}

std::ostream& operator<<(std::ostream& os, const LackDMA& b)
{
	os << (const DMA&)b;
	os << "Kolor: " << b.color << std::endl;;
	return os;
}


HasDMA::HasDMA(const char* l, const char* s, int r) :DMA(l, r)
{
	int size = strlen(s) + 1;
	style = new char[size];
	strncpy_s(style, size, s, size);
}

HasDMA::HasDMA(const HasDMA& h) :DMA(h)
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
	DMA::operator=(h);//sprawdzic *this = hs
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

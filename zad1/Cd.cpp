#include "Cd.h"
#include <iostream>
//#include cctype

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	int size1 = strlen(s1) + 1;
	int size2 = strlen(s2) + 1;
	this->m_performers = new char[size1];
	this->m_label = new char[size2];
	strncpy_s(this->m_performers, size1, s1, size1 - 1);
	strncpy_s(this->m_label, size2, s2, size2 - 1);
	this->m_selections = n;
	this->m_playtime = x;
}

Cd::Cd(const Cd& d)
{
	int size = strlen(d.m_performers) + 1;
	int size2 = strlen(d.m_label) + 1;
	this->m_performers = new char[size];
	this->m_label = new char[size];
	strncpy_s(this->m_performers, size, d.m_performers, size - 1);
	strncpy_s(this->m_label, size2, d.m_label, size2 - 1);
	this->m_selections = d.m_selections;
	this->m_playtime = d.m_playtime;
}
Cd::Cd()
{
	this->m_performers = new char[1];
	this->m_performers[0] = '\0';
	this->m_label = new char[1];
	this->m_label[0] = NULL;
	this->m_selections = 0;
	this->m_playtime = 0;

	
}
Cd::~Cd()
{
	delete[] this->m_performers;
	delete[] this->m_label;
}
void Cd::report() const
{
	std::cout << this->m_performers << " " << this->m_label << " " << this->m_selections << " " << m_playtime << std::endl;
}
Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	int size1 = strlen(d.m_performers) + 1;
	int size2 = strlen(d.m_label) + 1;
	this->m_performers = new char[size1];
	this->m_label = new char[size2];
	strncpy_s(this->m_performers, size1, d.m_performers, size1 - 1);
	strncpy_s(this->m_label, size2, d.m_label, size2 - 1);
	this->m_playtime = d.m_playtime;
	this->m_selections = d.m_selections;
	return *this;
}

Classic::Classic(const char* s1, const char* s2, int n, double x, const char* s3):Cd(s1,s2,n,x)
{
	int size = strlen(s3);
	this->m_mainSong = new char[size];
	strncpy_s(this->m_mainSong, size, s3, size - 1);

}
Classic::Classic(const Cd& c, const char* s3):Cd(c)
{
	int size = strlen(s3);
	this->m_mainSong = new char[size];
	strncpy_s(this->m_mainSong, size, s3, size - 1);
}


Classic::Classic():Cd()
{
		this->m_mainSong = new char[1];
		this->m_mainSong[0] = '\0';
}
Classic::Classic(const Classic& c):Cd(c)
{
	int size = strlen(c.m_mainSong) + 1;
	this->m_mainSong = new char[size];
	strncpy_s(this->m_mainSong, size, c.m_mainSong, size - 1);

}
Classic::~Classic()
{
	delete[] this->m_mainSong;
}
Classic& Classic::operator=(const Classic& c)
{
	if (this == &c)
		return *this;
	Cd::operator=(c);
	delete[] this->m_mainSong;
	int size = strlen(c.m_mainSong);
	this->m_mainSong = new char[size];
	strncpy_s(this->m_mainSong, size, c.m_mainSong, size - 1);
	return *this;
}
void Classic::report() const
{
	Cd::report();
	std::cout << "Glowny utwor: " << this->m_mainSong << std::endl;
}

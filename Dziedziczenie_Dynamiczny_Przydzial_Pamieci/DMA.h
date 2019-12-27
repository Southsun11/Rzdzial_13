#pragma once
#include <iostream>
class BaseDMA
{
private:
	char* m_label;
	int m_rating;
public:
	BaseDMA(const char* l = "brak", int r = 0);
	BaseDMA(const BaseDMA& b);
	virtual ~BaseDMA();
	BaseDMA& operator=(const BaseDMA& b);
	friend std::ostream & operator<<(std::ostream& os,const  BaseDMA& b);
};


class LackDMA:public BaseDMA
{
private:
	enum { COL_LEN  = 40};
	char color[COL_LEN];
public:
	LackDMA(const char* l = "brak", const char * c = "brak", int r = 0);
	LackDMA(const BaseDMA& b, const char* c );
	friend std::ostream & operator<<(std::ostream& os, const LackDMA& b);

};

class HasDMA: public BaseDMA
{
private:
	char* style;
public:
	HasDMA(const char * l = "brak", const char * s = "brak", int r = 0);
	HasDMA(const HasDMA& b, const char* s );
	HasDMA(const HasDMA& h);
	virtual ~HasDMA();
	HasDMA& operator=(const HasDMA& h);
	friend std::ostream& operator<<(std::ostream& os, const HasDMA& h);
};
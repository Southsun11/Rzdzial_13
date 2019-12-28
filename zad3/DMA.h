#pragma once
#include <iostream>

class DMA
{
private:
	char* m_label;
	int m_rating;
public:
	DMA(const char* l = "brak", int r = 0);
	DMA(const DMA& b);
	DMA& operator=(const DMA& b);
	virtual ~DMA() = 0;
	friend std::ostream& operator<<(std::ostream& os, const  DMA& b);
};

class BaseDMA: public DMA
{
public:
	BaseDMA(const char* l = "brak", int r = 0);
	BaseDMA(const BaseDMA& b);
	virtual ~BaseDMA();
	BaseDMA& operator=(const BaseDMA& b);
	friend std::ostream& operator<<(std::ostream& os, const  BaseDMA& b);
};


class LackDMA :public DMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	LackDMA(const char* l = "brak", const char* c = "brak", int r = 0);
	friend std::ostream& operator<<(std::ostream& os, const LackDMA& b);

};

class HasDMA : public DMA
{
private:
	char* style;
public:
	HasDMA(const char* l = "brak", const char* s = "brak", int r = 0);
	HasDMA(const HasDMA& h);
	virtual ~HasDMA();
	HasDMA& operator=(const HasDMA& h);
	friend std::ostream& operator<<(std::ostream& os, const HasDMA& h);
};
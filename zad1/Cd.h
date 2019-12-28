#pragma once
class Cd
{
private:
	char* m_performers;
	char* m_label;
	int m_selections;
	double m_playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	~Cd();
	virtual void report() const;
	Cd & operator=(const Cd& d);

};


class Classic : public Cd
{
private:
	char* m_mainSong;
public:
	Classic(const char* s1, const char* s2, int n, double x, const char* s3);
	Classic(const Cd& c, const char* s3);
	Classic();
	Classic(const Classic& c);
	~Classic();
	Classic& operator=(const Classic& c);
	virtual void report() const;
};

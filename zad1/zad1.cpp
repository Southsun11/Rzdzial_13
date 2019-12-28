#include <iostream>
#include "Cd.h"
void Bravo(const Cd& disk);
int main()
{
    Cd c1("Beatles", "Capitol", 13, 35.5);
    Classic c2("Sonata fortepianowa B-dur, Fantazja C-moll", "Alfred Brendel", 2, 57.17, "Philips");
    Cd * pcd = &c1;
    std::cout << "Bezposrednie uzycie obiektu:\n";
    c1.report();
    c2.report();
    std::cout << "Uzycie wskaznika typu Cd:\n";
    pcd->report();
    pcd = &c2;
    pcd->report();
    std::cout << "Wywolanie funkcji z argumentem w postaci referencji do typu Cd:\n";
    Bravo(c1);
    Bravo(c2);
    std::cout << "Test przypisania:\n";
    Classic copy;
    copy = c2;
    copy.report();

    Cd temp;
    temp.report();
    return 0;

}

void Bravo(const Cd& disk)
{
    disk.report();
}
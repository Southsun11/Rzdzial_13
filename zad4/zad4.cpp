#include <iostream>
#include "Port.h"
int main()
{
    
    Port p1;
    Port p2("Szato Brio","brazowe", 100);
    Port p3(p2);
    std::cout << "Klasa Port, metoda show" << std::endl;
    p1.show();
    p2.show();
    p3.show();
    std::cout << "\n\nKlasa Port wywolanie cout\n";
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << "\n\nOperator przypisania\n";
    p1 = p2;
    p1.show();
    std::cout << p1 << std::endl;
    std::cout << "\n\nOperacje na butelkach \n";
    std::cout << p1.bottleCount() << std::endl;
    p1 -= 100;
    std::cout << p1.bottleCount() << std::endl;
    p1 += 100;
    std::cout << p1.bottleCount() << std::endl;
    
    VintagePort vp1;
    VintagePort vp2("Cabernee", 200, "Szlachetny", 1980);
    VintagePort vp3(vp2);
    std::cout << "\n\nKlaca VintagePort metoda show\n";
    vp1.show();
    vp2.show();
    vp3.show();
    std::cout << "\n\nKlasa VintagePort wywolanie cout\n";
    std::cout << vp1 << std::endl;
    std::cout << vp2 << std::endl;
    std::cout << vp3 << std::endl;
    
    return 0;
       

}


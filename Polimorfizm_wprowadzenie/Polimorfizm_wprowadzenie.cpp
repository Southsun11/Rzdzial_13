#include <iostream>
#include "Brass.h"
int main()
{
    Brass Piggy("Bonifacy Kot", 381299, 12000.000);
    BrassPlus Hoggy("Horacy  Biedronka", 382288, 9000.00);
    Piggy.viewAcct();
    std::cout << std::endl;
    Hoggy.viewAcct();
    std::cout << std::endl;
    std::cout << "Wplata 3000 zl na rachunek pana Biedronki:\n";
    Hoggy.deposit(3000);
    std::cout << "Nowy stan konta: ";
    Hoggy.viewAcct();
    std::cout << std::endl;
    std::cout << "Wyplata 12600 z rachunku pana kota\n";
    Piggy.withdraw(12600);
    std::cout << "Stan konta Kota: ";
    Piggy.viewAcct();
    std::cout << std::endl;
    std::cout << "Wyplata 12600 zl z rachunku pana Biedronki:\n";
    Hoggy.withdraw(12600);
    Hoggy.viewAcct();
    return 0;
}


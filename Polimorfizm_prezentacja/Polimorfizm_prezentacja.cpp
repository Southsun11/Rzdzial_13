#include <iostream>
#include "Brass.h"
#include <string>
const int Clients = 4;
int main()
{
    Brass* p_clients[Clients];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    for (int i = 0; i < Clients; i++)
    {
        std::cout << "Podaj imie i nazwisko klienta:";
        getline(std::cin, temp);
        std::cout << "Podaj numer rachunku:";
        std::cin >> tempnum;
        std::cout << "Podaj stan poczatkowy:";
        std::cin >> tempbal;
        std::cout << "Wpisz 1 dla rachunku Brass, 2 dla rachunku BrassPlus: ";
        while (std::cin >> kind && (kind != '1' && kind != '2'))
            std::cout << "Wpisz 1 lub 2" << std::endl;
        if (kind == 1)
            p_clients[i] = new Brass(temp, tempnum, tempbal); // sprawdzic
        else
        {
            double tmax, trate;
            std::cout << "Podaj limit debetu: ";
            std::cin >> tmax;
            std::cout << "Podaj stope oprocentowania, jako ulamek dziesiety: ";
            std::cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (std::cin.get() != '\n')
            continue;
    }
    std::cout << std::endl;
    for (int i = 0; i < Clients; i++)
    {
        p_clients[i]->viewAcct();
        std::cout << std::endl;
    }
    for (int i = 0; i < Clients; i++)
        delete p_clients[i];
    std::cout << "Gotowe\n";
    return 0;


}


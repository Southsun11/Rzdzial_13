#include <iostream>
#include "DMA.h"

int main()
{
    LackDMA test("etykieta", "dlugi napis taki zeby mial dyzo znakowsdf hajdfsdl kfs dfjh skldjfh sdjf", 30);
    std::cout << test;


    /*BaseDMA shirt("Portobello", 8);
    LackDMA balloon("czerwony", "Blimpo", 4);
    HasDMA map("Merkator", "Buffalo Keys", 5);
    std::cout << "Wypisanie obiekty BaseDMA\n";
    std::cout << shirt;
    std::cout << "Wypisanie obiekty LackDMA\n";
    std::cout << balloon;
    std::cout << "Wypisanie obiekty HasDMA\n";
    std::cout << map;
    LackDMA balloon2(balloon);
    std::cout << "Wynik kopiowania LackDMA\n";
    std::cout << balloon2;
    HasDMA map2;
    map2 = map;
    std::cout << "Operator przypisania HasDMA\n";
    std::cout << map2;
    LackDMA balloon3;
    balloon3 = balloon2;
    std::cout << "Operator przypisania LackDMA\n";
    std::cout << balloon3;
    HasDMA map3(map2);
    std::cout << "Wynik kopiowania HasDMA\n";
    std::cout << map3;*/
    return 0;
    
}


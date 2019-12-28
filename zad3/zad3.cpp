
#include <iostream>
#include "DMA.h"
int main()
{  
    DMA * tablica[10]; 
    tablica[0] = new BaseDMA();
    tablica[1] = new LackDMA();
    tablica[2] = new HasDMA();
    for (int i = 0; i < 3; i++)
        std::cout << *tablica[i]  ;
    
}

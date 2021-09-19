#include <iostream>
#include <cstdlib>
#include <random>

int xCPU;
int yCPU;

void print(char (&table)[3][3]) {
    system("clear");
    for (size_t i = 0; i < 3; i++){
        std::cout << "|";
        for (size_t j = 0; j < 3; j++)
            std::cout << table[i][j] <<  "\t | ";
        std::cout << std::endl << "--------------------------" << std::endl;
    }
}

void launch()   {
    int x, y;
    char table[3][3], c;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cin >> x >> y >> c;
            table[x][y] = c;
        }
    }    
    
    char temp[9];
    int index = 0, pos = 100, interval;


    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            temp[index++] = table[i][j];
            
    for (size_t i = 0; i < 9; i++)
    {
        std::cout << table[i];
    } std::cout << std::endl;
        
}

int main()  {
    launch();
    return 0;
}
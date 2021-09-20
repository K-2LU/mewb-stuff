#include"updateCPU.hpp"

bool defCPU(char (&table)[3][3], bool (&visited)[3][3], int &emptyCells, int &x, int &y)    {
    if(table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == '-')
        update(table, visited, 2, 2, emptyCells);

    if(table[0][1] == 'X' && table[1][1] == 'X' && table[2][1] == '-')  
        update(table, visited, 2, 1, emptyCells);

    if(table[0][2] == 'X' && table[1][1] == 'X' && table[2][0] == '-')  
        update(table, visited, 2, 0, emptyCells);

    if(table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == '-')  
        update(table, visited, 1, 2, emptyCells);

    if(table[1][0] == '-' && table[1][1] == 'X' && table[2][2] == 'X')  
        update(table, visited, 1, 0, emptyCells);

    if(table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == '-')  
        update(table, visited, 2, 2, emptyCells);

    if(table[2][0] == 'X' && table[1][0] == 'X' && table[0][0] == '-')  
        update(table, visited, 0, 0, emptyCells);
    
    if(table[2][0] == '-' && table[1][1] == 'X' && table[0][2] == 'X')  
        update(table, visited, 0, 2, emptyCells);
}
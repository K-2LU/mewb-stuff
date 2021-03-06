#include "data.hpp"
#include "updateCPU.hpp"

bool defCPU(char (&table)[3][3], bool (&visited)[3][3], int &emptyCells, int &x, int &y) {
    int detect = 0, hdetect, hx, hy;
    bool hphen = false;

    // horizontal sweep
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(table[i][j] == 'X')  detect += 1;
            if(table[i][j] == '-')  hphen = true, hdetect = j;
        }   if(detect==2 && hphen == true){
            update(table, visited, i, hdetect, emptyCells);
            return true;
        }

        detect = 0, hphen = false;
    }
    
    // vertical sweep
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(table[j][i] == 'X')  detect += 1;
            if(table[j][i] == '-')  hphen = true, hdetect = j;
        }   if(detect==2 && hphen == true){
            update(table, visited, hdetect, i, emptyCells);
            return true;
        }

        detect = 0, hphen = false;
    }

    // for pos: 00 11 22
    for (size_t i = 0, j = 0; i < 3 && j < 3; i++, j++)
    {
        if(table[i][j] == 'X')  detect += 1;
        if(table[i][j] == '-')  hphen = true, hx = i, hy = j;
        
        if(detect==2 && hphen == true){
            update(table, visited, hx, hy, emptyCells);
            return true;
        }
        detect = 0, hphen = false;
    }

    // for pos: 02 11 20 
    for (size_t i = 0, j = 2; i < 3 && j >= 0; i++, j--)  {
        if(table[j][i] == 'X')  detect += 1;
        if(table[j][i] == '-')  hphen = true, hx = j, hy = i;
        
        if(detect==2 && hphen == true){
            update(table, visited, hx, hy, emptyCells);
            return true;
        }
    }
    
    return false;
}

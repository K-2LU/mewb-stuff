#include "data.hpp"

bool defCPU(char (&table)[3][3], bool (&visited)[3][3], int &emptyCells, int &x, int &y) {
    char temp[9];
    int index = 0, pos = 100, interval;


    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            temp[index++] = table[i][j];


    for (size_t i = 0; i < 5; i++)  {
        if(temp[i] == 'X'){

        for (size_t j = i; j < 7; j++)
            {
                interval = j - i;
                if(interval == 0)   continue;
                
                if(temp[j] == 'X' && interval >=1 && temp[interval] == '-'){
                    pos = j+interval;
                    break;
                }
            }
            if(pos >= 0 && pos <9) break;
        }
    }
    
    if(pos < 9) {
        table[pos/3][pos%3] = 'O', visited[pos/3][pos%3] = true, emptyCells -= 1; 
        return true;
    }

    return false;
}
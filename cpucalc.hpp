#include "defensive.hpp"

void cpuComp(char (&table)[3][3], bool (&visited)[3][3], int &emptyspace, int &xCPU, int &yCPU){
    bool change = false;
    int x, y;

    if(visited[1][1] == false){
        table [1][1] = 'O', visited[1][1] = true, emptyspace -= 1;
        xCPU = 1; yCPU = 1;
        return;
    }
    
     /* 
    if(table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] == '-'){
        table[0][2] == 'O', visited[0][2] = true, emptyspace -= 1;
        return;
    }
    
    if(table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == '-'){
        table[1][2] == 'O', visited[1][2] = true, emptyspace -= 1;
        return;
    }

    if(table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == '-'){
        table[2][2] == 'O', visited[2][2] = true, emptyspace -= 1;
        return;
    }*/

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(table[i][j]=='X'){
                change = defCPU(table, visited, emptyspace, x, y);
                if(change == true) return;
            }
        }
        
    }

    if(!change){
        int x = rand()%3, y = rand()%3;

        while(visited[x][y]==true) {
            x = rand()%3, y = rand()%3;
            if(visited[x][y]==false)    {
                table[x][y] = 'O', visited[x][y] = true, emptyspace -=1;
                //return;
                break;
            }
        }
    }
    
    table[x][y] = 'O', visited[x][y] = true, emptyspace -=1;
    xCPU = x;
    yCPU = y;
}
#include "defensive.hpp"

void cpuComp(char (&table)[3][3], bool (&visited)[3][3], int &emptyspace, int &xCPU, int &yCPU){
    bool change = false;
    int x, y;

    if(visited[1][1] == false){
        table [1][1] = 'O', visited[1][1] = true, emptyspace -= 1;
        xCPU = 1; yCPU = 1;
        return;
    }
    if(visited[1][1] == true && emptyspace >=8){
        int x = rand()%3, y = rand()%3;

        while(visited[x][y]==true) {
            x = rand()%3, y = rand()%3;
            if(visited[x][y]==false)    {
                table[x][y] = 'O', visited[x][y] = true, emptyspace -=1;
                xCPU = x;
                yCPU = y;
                return;
            }
        }
    }

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

    xCPU = x;
    yCPU = y;
}
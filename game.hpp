#include "display.hpp"
#include "calculate.hpp"
#include "cpucalc.hpp"
#include "data.hpp"

void launch()   {

    int x, y, emptyCells = 9;
    int xCPU, yCPU;
    bool visited[3][3];
    char table[3][3];

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            table[i][j] = '-', visited[i][j]= false;
    
    print(table);
        
    while(true){
        std::cout <<"P1: ";
        std::cin >> x >> y;

        while(visited[x][y] == true){
            cout << "Invalid move!\n";
            std::cin >> x >> y;
        }
        table[x][y] = 'X', visited[x][y] = true, emptyCells -=1;

        print(table);
        if(compute(x, y, table, 'X', emptyCells)){
            std::cout << "P1 wins\n";
            break;
        }

        cpuComp(table, visited, emptyCells, xCPU, yCPU);
        print(table);
        std::cout << "CPU: " << xCPU << ' ' << yCPU << std::endl;
        
        if(compute(xCPU, yCPU, table, 'O', emptyCells)){
            std::cout << "P2 wins\n";
            break;
        }
        
        if(emptyCells==1){
            std::cout << "Draw" << std::endl;
            break;
        }
    }
}

        /*
        std::cout <<"P2: ";

         std::cin >> x >> y;
        while(visited[x][y] == true){
            cout << "Invalid move!\n";
            std::cin >> x >> y;
        }
        table[x][y] = 'O', visited[x][y] = true;
        */
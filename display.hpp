#include <iostream>

using std::cout;

void print(char (&table)[3][3]) {
    system("clear");
    for (size_t i = 0; i < 3; i++){
        cout << "|";
        for (size_t j = 0; j < 3; j++)
            cout << table[i][j] <<  "\t | ";
        cout << std::endl << "--------------------------" << std::endl;
    }
}
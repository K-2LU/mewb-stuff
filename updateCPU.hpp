void update(char (&table)[3][3], bool (&visited)[3][3], int x, int y, int &emptyCells) {
    table[x][y] = 'O', visited[x][y] = true, emptyCells -= 1; 
}
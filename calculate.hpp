bool compute(int x, int y, char (&table)[3][3], char key, int &emptyCells) {
    int x1, x2, x3;
    int y1, y2, y3;
    x1=x, y1=y;
    
    x2 = (x1+1)%3;
    x3 = (x1+2)%3;

    y2 = (y1+1)%3;
    y3 = (y1+2)%3;
    
    //walk(x1, x2, x3);   // horizontal walk
    if(table[x1][y]==key && table[x2][y]==key && table[x3][y]==key)
        return true;

    //walk(y1, y2, y3);   // vertical walk
    if(table[x][y1]==key && table[x][y2]==key && table[x][y3]==key)
            return true;

    if(x==0 && y==0)
        if(table[x][y]==key && table[1][1]==key && table[2][2]==key)
            return true;

    if(x==2 && y==2)
        if(table[x][y]==key && table[1][1]==key && table[0][0]==key)
            return true;

    if((x==0 && y==2) || (x==2 && y==0))
        if(table[x][y]==key && table[1][1]==key && table[y][x]==key)
            return true;

    return false;
}

void walk(int &x1, int &x2, int &x3){
    x2 = (x1+1)%3;
    x3 = (x1+2)%3;
}
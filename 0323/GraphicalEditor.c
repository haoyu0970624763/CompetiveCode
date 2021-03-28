#include <stdio.h>
#include <stdlib.h>
int row = 0, column = 0;
char table[250][250];
void findRegion( int y, int x, char color, char original);


int main(int argc, char *argv[])
{

    char instruction;
    char C;
    
    char name[100];

    while (scanf("%c", &instruction))
    {
        if (instruction == 'I')
        {

            int input1, input2;
            scanf("%d", &column);
            scanf("%d", &row);

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    table[i][j] = 'O';
                }
            }
        }
        else if (instruction == 'C')
        {
            if (row != 0 && column != 0)
            {
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        table[i][j] = 'O';
                    }
                }
            }
        }
        else if (instruction == 'L')
        {
            int x, y;
            scanf("%d", &y);
            scanf("%d", &x);
            scanf(" %c", &C);
            if (row != 0 && column != 0 && (y <= column && x <= row))
            {
                table[x-1][y-1] = C;
            }
        }
        else if (instruction == 'V')
        {
            int y, x1, x2;

            scanf("%d", &y);
            scanf("%d", &x1);
            scanf("%d", &x2);
            scanf(" %c", &C);
            if (x1 > x2)
            {
                int tmp = x2;
                x2 = x1;
                x1 = tmp;
            }
            if (row != 0 && column != 0 && (y <= column && x2 <= row))
            {

                for (int i = x1; i <= x2; i++)
                {
                    table[i-1][y-1] = C;
                }
            }
        }
        else if (instruction == 'H')
        {
            int y1, y2, x;
            scanf("%d", &y1);
            scanf("%d", &y2);
            scanf("%d", &x);
            scanf(" %c", &C);
            if (y1 > y2)
            {
                int tmp = y2;
                y2 = y1;
                y1 = tmp;
            }
            if (row != 0 && column != 0 && (y2 <= column && x <= row))
            {
                for (int i = y1; i <= y2; i++)
                {
                    table[x-1][i-1] = C;
                }
            }
        }
        else if (instruction == 'F')
        {
            int x, y;
            char origin;
            scanf("%d", &y);
            scanf("%d", &x);
            scanf(" %c", &C);
            if (row != 0 && column != 0 && (y <= column && x <= row))
            {
                origin = table[x-1][y-1];
                table[x-1][y-1]=C;
                findRegion( y-1, x-1, C, origin);
            }
        }
        else if (instruction == 'K')
        {

            int x1, x2, y1, y2;
            scanf("%d", &y1);
            scanf("%d", &x1);
            scanf("%d", &y2);
            scanf("%d", &x2);
            scanf(" %c", &C);
            if (x1 > x2)
            {
                int tmp = x2;
                x2 = x1;
                x1 = tmp;
            }
            if (y1 > y2)
            {
                int tmp = y2;
                y2 = y1;
                y1 = tmp;
            }
            if (row != 0 && column != 0 && (y2 <= column && x2 <= row))
            {

                for (int i = x1; i <= x2; i++)
                {
                    for (int j = y1; j <= y2; j++)
                    {
                        table[i- 1][j-1] = C;
                    }
                }
            }
        }
        else if (instruction == 'S')
        {
            scanf("%s", name);
            puts(name);

            if (row != 0 && column != 0)
            {
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        printf("%c", table[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        else if (instruction == 'X')
        {
            break;
        }
    }
    return 0;
}
void findRegion(int y, int x, char color, char original)
{
    int l=y;
    int m=x;
    if (color == original)
    {
        return;
    }   
    // left
    if ( y-1 >= 0 && table[x][y-1] == original)
    {
        table[x][y-1] = color;
        findRegion(y-1, x, color, original);
    }
    // right
    if (y + 1 < column && table[x][y+1] == original)
    {
        table[x][y+1] = color;
        findRegion(y+1, x, color, original);
    }
    //up
    if (x-1 >= 0 && table[x-1][y] == original)
    {
        table[x-1][y] = color;
        findRegion(y, x-1, color, original);
    }
    //down
    if (x+1 < row && table[x+1][y] == original)
    {

        table[x+1][y] = color;
        findRegion(y, x+1, color, original);
    }
};
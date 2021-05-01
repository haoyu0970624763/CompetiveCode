#include <stdio.h>
int main()
{

    int inputNum;
    int matrix[100][100];
    int row[100] = {0}, col[100] = {0};
    int errorRow, errorCol;
    int errorRowIndex, errorColIndex;
    while (scanf("%d", &inputNum))
    {
        if (inputNum == 0)
        {
            break;
        }
        errorRow = 0;
        errorCol = 0;
        errorRowIndex = 0;
        errorColIndex = 0;

        for (int i = 0; i < inputNum; i++)
        {
            row[i]=0;
            col[i]=0;
        }
        
        for (int i = 0; i < inputNum; i++)
        {
            for (int j = 0; j < inputNum; j++)
            {
                scanf("%d", &matrix[i][j]);
                row[i] += matrix[i][j];
            }
        }
        for (int j = 0; j < inputNum; j++)
        {
            for (int i = 0; i < inputNum; i++)
            {
                col[j] += matrix[i][j];
            }
        }
        for (int i = 0; i < inputNum; i++)
        {
            if (row[i] & 0x01)
            {
                errorRow++;
                errorRowIndex = i + 1;
            }
            if (col[i] & 0x01)
            {
                errorCol++;
                errorColIndex = i + 1;
            }
        }
        if (errorRow == 0 && errorCol == 0)
        {
            printf("OK\n");
        }
        else if (errorRow == 1 && errorCol == 1)
        {
            printf("Change bit (%d,%d)\n", errorRowIndex, errorColIndex);
        }
        else
        {
            printf("Corrupt\n");
        }
    }
    return 0;
}
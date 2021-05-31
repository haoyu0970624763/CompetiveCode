#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int StandardNum;
    int CompareNum;
    int count = 1;
    char readLine[5];
    char NumList1[1200] = {};
    char NumList2[1200] = {};
    int NumList1Index;
    int NumList2Index;
    while (1)
    {
        
        cin.getline(readLine, 5);

        StandardNum=atoi(readLine);

        if (StandardNum == 0)
        {
            break;
        }

        int correctflag = 1;
        int wrongFlag = 0;

        NumList1Index = 0;
        NumList2Index = 0;
        char standard[StandardNum][120];
        


        for (int i = 0; i < StandardNum; i++)
        {
            cin.getline(standard[i], 120);
        }

        cin.getline(readLine, 5);
    
        CompareNum=atoi(readLine);;

        char compare[CompareNum][120];

        for (int i = 0; i < CompareNum; i++)
        {
            cin.getline(compare[i],120);
        }

        if (CompareNum == StandardNum)
        {
            for (int i = 0; i < CompareNum; i++)
            {
                
                if (strcmp(standard[i],compare[i]) != 0)
                {
                    correctflag = 0;
                    break;
                }
            }
        }
        else
        {
            correctflag = 0;
        }

        if (correctflag == 0)
        {
            for (int i = 0; i < StandardNum; i++)
            {
                for (int j = 0; j < strlen(standard[i]); j++)
                {
                    if (standard[i][j] >= '1' && standard[i][j] <= '9')
                    {
                        NumList1[NumList1Index] = standard[i][j];
                        NumList1Index++;
                    }
                }
            }

            for (int i = 0; i < CompareNum; i++)
            {
                for (int j = 0; j < strlen(compare[i]); j++)
                {
                    if (compare[i][j] >= '1' && compare[i][j] <= '9')
                    {
                        NumList2[NumList2Index] = compare[i][j];
                        NumList2Index++;
                    }
                }
            }
            if (NumList1Index != NumList2Index)
            {
                wrongFlag = 1;
            }
            else
            {
                for (int i = 0; i < NumList1Index - 1; i++)
                {
                    if (NumList1[i] != NumList2[i])
                    {
                        wrongFlag = 1;
                        break;
                    }
                }
            }
        }
        printf("Run #%d: ", count);
        if (correctflag)
        {
            printf("Accepted\n");
        }
        else if (wrongFlag)
        {
            printf("Wrong Answer\n");
        }
        else
        {
            printf("Presentation Error\n");
        }
        count++;
    }
    return 0;
}
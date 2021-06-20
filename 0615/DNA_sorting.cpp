#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    int caseNum;
    int strlen;
    int strNum;

    cin >> caseNum;

    while (caseNum > 0)
    {
        
        int min = INT32_MAX;
        int strIndex;
        cin >> strlen;
        cin >> strNum;

        string str[strNum];
        int SortNum[strNum];

        for (int i = 0; i < strNum; i++)
        {
            cin >> str[i];
            SortNum[i] = 0;
        }

        for (int i = 0; i < strNum; i++)
        {
            for (int j = 0; j < strlen; j++)
            {
                for (int k = j + 1; k < strlen; k++)
                {
                    if (str[i][j] > str[i][k])
                    {
                        SortNum[i]++;
                    }
                }
            }
        }

        for (int i = 0; i < strNum; i++)
        {
            for (int j = 0; j < strNum; j++)
            {
                if (SortNum[j] < min && (SortNum[j] != -1))
                {
                    min = SortNum[j];
                    strIndex = j;
                }
            }
            min = INT32_MAX;
            SortNum[strIndex]= -1;
            cout << str[strIndex] << endl;
        }
        

        caseNum --;
        if(caseNum > 0){
            cout << endl ;
        }
    }
}
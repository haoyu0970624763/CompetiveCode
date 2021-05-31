#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int taskNum;

    cin >> taskNum;

    for (int i = 0; i < taskNum; i++)
    {
        if( i !=0 ){
            printf("\n");
        }
        char readline[5];
        char input[100];
        char subStr[50];
        int errorFlag;

        cin >> input;

        for (int j = 0; j < strlen(input) / 2; j++)
        {
            errorFlag = 0;
            subStr[j] = input[j];
            if (strlen(input) % (j + 1) != 0)
            {
                if (j == strlen(input) / 2 - 1)
                {
                    printf("%ld\n", strlen(input));
                }
                continue;
            }
            else
            {
                int subIndex = 0;
                for (int k = 0; k < strlen(input); k++)
                {
                    if (input[k] == subStr[subIndex])
                    {
                        subIndex++;
                        if (subIndex == j + 1)
                        {
                            subIndex = 0;
                        }
                    }
                    else
                    {
                        errorFlag = 1;
                        break;
                    }
                }
            }
            if (errorFlag == 0)
            {
                printf("%d\n", j + 1);
                break;
            }
            if (j == strlen(input) / 2 - 1)
            {
                printf("%ld\n", strlen(input));
            }
        }

        if(strlen(input)==1){
            printf("1\n");
        }
        
    }
    return 0;
}
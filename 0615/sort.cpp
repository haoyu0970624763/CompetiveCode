#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int inputNum;
    int divisor;

    while (true)
    {
        scanf("%d %d", &inputNum, &divisor);

        if (inputNum == 0 && divisor == 0)
        {
            printf("0 0\n");
            break;
        }
        else{
             printf("%d %d\n",inputNum,divisor);
        }

        int input[inputNum];
        int remainder[inputNum];
        int tmp[inputNum];

        
        int output[inputNum];
        int outputIndex1=0;
        int outputIndex2=0;

        for (int i = 0; i < inputNum; i++)
        {
            scanf("%d", &input[i]);
            remainder[i] = input[i] % divisor;
        }
        int count=0;

        while (1)
        {
            
            int min = divisor;
            int tmpIndex=0;
            for (int i = 0; i < inputNum; i++)
            {
                if (remainder[i] < min)
                {
                    min = remainder[i];
                }
            }

            for (int i = 0; i < inputNum; i++)
            {
                if ( remainder[i] == min && input[i]& 0x1)
                {
                    remainder[i]=divisor;
                    tmp[tmpIndex]=i ;
                    tmpIndex++;
                }
            }

            for (int  i = 0; i < tmpIndex ; i++)
            {
                output[outputIndex2]=input[tmp[i]];
                outputIndex2 ++ ;
            }
            sort(&output[outputIndex1],&output[outputIndex2]);

            reverse(&output[outputIndex1],&output[outputIndex2]);

            outputIndex1 = outputIndex2;
            tmpIndex=0;

            for (int i = 0; i < inputNum; i++)
            {
                if ( remainder[i] == min)
                {
                    remainder[i]=divisor;
                    tmp[tmpIndex]=i ;
                    tmpIndex++;
                }
            }
            for (int  i = 0; i < tmpIndex ; i++)
            {
                output[outputIndex2]=input[tmp[i]];
                outputIndex2 ++ ;
            }
            sort(&output[outputIndex1],&output[outputIndex2]);
            outputIndex1 = outputIndex2;
            if( outputIndex2 >= inputNum){
                break ;
            }
        }
        for (int i = 0; i < inputNum; i++)
        {
            printf("%d\n",output[i]);
        }
    }

    return 0;
}

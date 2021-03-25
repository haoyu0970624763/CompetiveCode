#include<stdio.h>
#include <stdlib.h>

#define Max 1000


int main(int argc, char *argv[]){

	int caseNum;
    int count =0;
    int inputNum;

    scanf("%d",&caseNum);
    
entry:
	while( count < caseNum)
	{
        count ++;
        scanf("%d",&inputNum);
        int in[inputNum] , out[inputNum];
        for (int i = 0; i < inputNum; i++)
        {
            scanf("%d",&in[i]);   
        }
        int calculateNum = 0;
        while(calculateNum < Max)
        {
            int zeroNum=0;
            for (int i = 0; i < inputNum-1; i++)
            {
               out[i]=abs(in[i+1]-in[i]);
            }
            out[inputNum-1]=abs(in[inputNum-1]-in[0]);

            for (int i = 0; i < inputNum; i++)
            {
                in[i]=out[i];
                if(in[i]==0){
                    zeroNum++;
                }
            }
            if(zeroNum==inputNum){
                printf("ZERO\n");
                goto entry;
            }
            calculateNum++;
        }
        printf("LOOP\n");
	}
	return 0;
}

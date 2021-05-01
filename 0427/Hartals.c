#include<stdio.h>
#include <stdbool.h>
int main(){

    int count = 0;
    int CaseNum , DayNum , PartyNum;
    int Hartals=0;
    int HartalArr[100];
    bool check[3650]={false};

    scanf("%d",&CaseNum);

    while (count < CaseNum)
    {
        scanf("%d",&DayNum);
        scanf("%d",&PartyNum);
        for(int i=0;i<PartyNum;i++){
            scanf("%d",&HartalArr[i]);
        }
        
        for(int i=0;i<PartyNum;i++){
            int interval=HartalArr[i];
            for (int j = HartalArr[i]-1; j < DayNum; j+= interval)
            {
                check[j]=true;
            }
        }

        for (int i = 0; i < DayNum; i++)
        {  
            if( (i+1) % 7 ==0){
                continue;
            }
            else if ((i+2) % 7 ==0)
            {
                continue;
            }
            if(check[i]){
                
                Hartals++;
            }
            check[i]=false;
        }
        printf("%d\n",Hartals);

        count++;
        for(int i=0;i<PartyNum;i++){
            HartalArr[i]=0;
        }
        Hartals=0;
    }
    return 0;
}
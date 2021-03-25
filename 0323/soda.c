#include<stdio.h>
#define TRUE 1

int main(int argc, char *argv[]){

	int caseNum;
    int count = 0;
    int e , f , c ;

    scanf("%d",&caseNum);
	while( count < caseNum)
	{
        int drinkNum=0;
        int sodaNum;
		scanf("%d",&e) ;
        scanf("%d",&f) ;
        scanf("%d",&c) ;
        sodaNum= e+f;

        while (sodaNum >= c)
        {
            drinkNum =drinkNum +(sodaNum/c) ;
            sodaNum = sodaNum/c + sodaNum % c;
        }
        printf("%d\n",drinkNum);
        count++;
	}
	return 0;
}

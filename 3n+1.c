#include<stdio.h>
#define TRUE 1

int main(int argc, char *argv[]){

	int begin , end;

	while (scanf("%d",&begin)!= EOF)
	{
		int max=1;

		scanf("%d",&end) ;

		int tmp;
        int flag=0;
		if(begin > end ){
			tmp = end;
			end =begin;
			begin =tmp;
            flag=1;
		}

		for (int i= begin; i <= end; i++)
		{
			int number = i;
			int count =0;
			while (TRUE)
			{
				if(number==1){
					count ++;
					if(count > max){
						max=count;
					}
					break;
				}
				else{
					if(number & 0x1){
						number= 3*number +1;
					}
					else{
						number = number >> 1;
					}
                    count++;
				}
			}
		}
        if(flag==0)
		    printf("%d %d %d\n",begin,end,max);
        else
            printf("%d %d %d\n",end,begin,max);

	}
	return 0;
}

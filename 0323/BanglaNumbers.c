#include<stdio.h>

void recur(long long int n){
	if(n >= 10000000){
		recur(n/10000000);
		printf(" kuti");
		n %= 10000000;
	}
	if(n >= 100000){
		recur(n/100000);
		printf(" lakh");
		n%=100000;
	}
	if(n >= 1000){
		recur(n/1000);
		printf(" hajar");
		n%=1000;
	}
	if(n >= 100){
		recur(n/100);
		printf(" shata");
		n %=100;
	}
	if(n != 0)
		printf(" %lld",n);
};


int main(int argc, char *argv[]){

	long long int input;
	int count=1;

	while (scanf("%lld",&input)!= EOF)
	{   
		if(count == 1){
			printf("%4d.",count);
		}
		else{
			printf("\n%4d.",count);
		}
        if(input ==0){
            printf(" 0");
        }
        else{
            recur(input);
        }
		count++;
	}
	return 0;
}

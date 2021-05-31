#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char table[] = "abcdefghijklmnopqrstuvwxyz";
    char common[1000];

    int commonIndex = 0;
    char str1[1000], str2[1000];

    while (cin.getline(str1, 1000))
    {
        cin.getline(str2, 1000);

        commonIndex=0;
        for (int i = 0; i < strlen(str1); i++)
        {
            for (int j = 0; j < strlen(str2); j++)
            {
                if(str1[i] == str2[j]){
                    common[commonIndex]=str1[i];
                    str2[j]=' ';
                    commonIndex++;
                    break;
                }
            }
        }
        for(int i=0; i<strlen(table) ;i++){
            for(int j=0 ; j<commonIndex;j++){
                if(common[j]==table[i]){
                    printf("%c",common[j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
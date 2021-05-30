#include <iostream>
using namespace std;
int main()
{
    
    char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char input[100];

    // getline read one line discard \n
    while (cin.getline(input,100))
    {
        for (int i = 0; input[i]; i++)
        {
            if (input[i] == ' ')
            {
                printf("%c",input[i]);
            }
            else
            {
                int j = 0;
                while (input[i] != keyboard[j + 1])
                    j++;
                printf("%c", keyboard[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
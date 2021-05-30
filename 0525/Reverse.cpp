#include <iostream>
#include <string>
using namespace std;


string output;

void Reverse(string input, int GroupNum, int ReverseNum)
{
    int i;
    for (int i = 0; i < GroupNum; i= i+1 )
    {
        for (int j = i * ReverseNum; j < (i + 1) * ReverseNum; j++)
        {   
            output[j] = input[(2*i + 1) * ReverseNum -1-j];
        }
    }
    for ( int i = 0; i < input.length(); i++ )
    {
        printf("%c",output[i]);
    }
    printf("\n");
}

int main()
{
    int GroupNum;

    int ReverseNum;

    while (cin >> GroupNum)
    {

        if (GroupNum == 0)
        {
            break;
        }
        int index;
        string input;
        cin >> input;

        ReverseNum = input.length() / GroupNum;
        Reverse(input, GroupNum, ReverseNum);
    }
    return 0;
}
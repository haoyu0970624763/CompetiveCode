#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    long long int intArr[10000];
    long long int input;
    int intIndex = 0;

    while (cin >> input)
    {
        int tmpIndex = intIndex;
        int tmp;
        for (int i = 0; i < intIndex; i++)
        {
            if (intArr[i] > input)
            {
                tmpIndex = i ;
                break;
            }
        }
        if (tmpIndex == intIndex)
        {
            intArr[intIndex] = input;
        }
        else
        {
            int tmp2;

            for (int i = tmpIndex; i < intIndex; i++)
            {
                if (i == tmpIndex)
                {
                    tmp = intArr[tmpIndex];
                    intArr[tmpIndex] = input;
                }
                else
                {
                    tmp2 = intArr[i];
                    intArr[i] = tmp;
                    tmp = tmp2;
                }
            }
            intArr[intIndex] = tmp;
        }

        if ((intIndex + 1) & 0x01)
        {
            cout << intArr[(intIndex + 1) / 2] << endl;
        }
        else{
            int value = (intArr[(intIndex + 1) / 2] + intArr[(intIndex + 1) / 2 - 1]) / 2;
            cout << value << endl;
        }
        intIndex++;
    }
}
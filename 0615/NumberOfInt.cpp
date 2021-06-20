#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    int numberList[1000];
    int timesList[1000] = {0};

    int ListIndex = 0;
    int inputNum;
    while (cin >> inputNum)
    {
        int FindFlag = 0;
        if (ListIndex == 0)
        {
            numberList[ListIndex] = inputNum;
            timesList[ListIndex]++;
            ListIndex++;
        }
        else
        {
            for (int i = 0; i < ListIndex; i++)
            {
                if (numberList[i] == inputNum)
                {
                    timesList[i]++;
                    FindFlag = 1;
                    break;
                }
            }
            if (!FindFlag)
            {
                numberList[ListIndex] = inputNum;
                timesList[ListIndex]++;
                ListIndex++;
            }
        }
    }

    for (int i = 0; i < ListIndex; i++)
    {
        cout << numberList[i] << " " << timesList[i] << endl;
    }
    
}
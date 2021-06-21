#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int intArr[500];

    int CaseNum;
    int shoeNum;

    cin >> CaseNum;
    while (CaseNum > 0)
    {
        cin >> shoeNum;

        int day[shoeNum];
        int fine[shoeNum];
        int flag[shoeNum];

        for (int i = 0; i < shoeNum; i++)
        {
            cin >> day[i];
            cin >> fine[i];
            flag[i] = 0;
        }

        int count = 0;
        while (count < shoeNum)
        {
            float max = 0;
            int maxIndex = -1;
            for (int i = 0; i < shoeNum; i++)
            {
                float value = fine[i] / (float)day[i];
                if (value > max  && flag[i]==0 )
                {
                    max = value;
                    maxIndex = i;
                }
            }
            if(count != shoeNum-1){
                cout << maxIndex+1 << " ";
            }
            else{
                cout << maxIndex+1 << endl;
            }
            flag[maxIndex]=1;
            count++;
        }

        CaseNum--;
        if(CaseNum > 0){
            cout << endl;
        }
    }
}
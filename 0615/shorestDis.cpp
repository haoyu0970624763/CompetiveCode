#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int intArr[500];
    int CaseNum;

    cin >> CaseNum;
    while ( CaseNum > 0)
    {
        int relativeNum;
        int median;
        int distance=0;
        cin >> relativeNum;
        for (int i = 0; i < relativeNum; i++)
        {
            cin >> intArr[i];
        }
        sort(intArr,intArr+relativeNum);

        median=intArr[relativeNum/2];
        for (int i = 0; i < relativeNum; i++)
        {
            distance += abs(intArr[i]-median); 
        }
        cout << distance << endl;
        CaseNum--;
    }
}
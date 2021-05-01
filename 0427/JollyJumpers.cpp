#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int sequenceNum;
    int num;
    int diff;
    bool flag;

    vector<int> sequence;

    while (cin >> sequenceNum)
    {
        bool Table[3001] = {false};
        flag = true;
        cin >> num;
        sequence.push_back(num);
        for (int i = 1; i < sequenceNum; i++)
        {

            cin >> num;
            sequence.push_back(num);

            diff = num - sequence[i - 1];
            if (diff == 0)
            {
                flag = false;
            }
            else if (diff < 0)
            {
                diff = diff * (-1);
            }

            if (diff >= sequenceNum)
            {
                flag = false;
            }
            Table[diff] = true;
        }
        if (flag)
        {
            for (int i = 1; i < sequenceNum; i++)
            {
                if (Table[i] == false)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "Jolly" << endl;
        }
        else
        {
            cout << "Not jolly" << endl;
        }
        sequence.clear();
    }
}
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int trainNum;

    stack<int> Stack;
    queue<int> OutQueue;

    int FirstNum, num;

    while (cin >> trainNum)
    {
        if (trainNum == 0)
        {
            break;
        }
        else
        {
            while (true)
            {
                cin >> FirstNum;
                if (FirstNum == 0)
                {
                    cout << endl;
                    break;
                }
                else
                {
                    OutQueue.push(FirstNum);
                    for (int i = 1; i < trainNum; i++)
                    {
                        cin >> num;
                        OutQueue.push(num);
                    }

                    for (int i = 1; i <= trainNum; i++)
                    {
                        Stack.push(i);
                        while (!Stack.empty())
                        {
                            if (OutQueue.front() == Stack.top())
                            {
                                OutQueue.pop();
                                Stack.pop();
                            }
                            else{
                                break;
                            }
                        }
                    }
                    if (Stack.empty())
                    {
                        cout << "Yes" << endl;
                    }
                    else
                    {
                        cout << "No" << endl;
                    }
                    while (!Stack.empty())
                        Stack.pop();
                    while (!OutQueue.empty())
                        OutQueue.pop();
                }
            }
        }
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main()
{

    stack<int> Stack;
    queue<int> Queue;
    priority_queue<int> P_Queue;

    bool DS[3];
    int possibility;
    int line_num, commandType, num;

    while (scanf("%d", &line_num) != EOF)
    {
        for (int i = 0; i < 3; i++)
        {
            DS[i] = true;
        }
        possibility = 0;
        for (int i = 0; i < line_num; i++)
        {
            scanf("%d%d", &commandType, &num);
            if (commandType == 1)
            {
                Stack.push(num);
                Queue.push(num);
                P_Queue.push(num);
            }
            else
            {
                if (DS[0])
                {
                    if (!Stack.empty() && Stack.top() == num)
                        Stack.pop();
                    else
                        DS[0] = false;
                }
                if (DS[1])
                {
                    // front() 返回第一个元素
                    if (!Queue.empty() && Queue.front() == num)
                        Queue.pop();
                    else
                        DS[1] = false;
                }
                if (DS[2])
                {
                    if (!P_Queue.empty() && P_Queue.top() == num)
                        P_Queue.pop();
                    else
                        DS[2] = false;
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (DS[i])
            {
                possibility++;
            }
        }

        if (possibility == 0)
        {
            printf("impossible\n");
        }
        else if (possibility == 1)
        {
            if (DS[0])
            {
                printf("stack\n");
            }
            else if (DS[1])
            {
                printf("queue\n");
            }
            else if (DS[2])
            {
                printf("priority queue\n");
            }
        }
        else
        {
            printf("not sure\n");
        }
        // pop all the number in data structure
        while (!Stack.empty())
            Stack.pop();
        while (!Queue.empty())
            Queue.pop();
        while (!P_Queue.empty())
            P_Queue.pop();
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int checkTail(string str)
{
    if (str[str.length() - 1] == 'o' || str[str.length() - 1] == 'x' || str[str.length() - 1] == 's')
    {
        return 1;
    }
    else if (str.length() >= 2)
    {
        if (str[str.length() - 1] == 'h' && str[str.length() - 2] == 'c')
        {
            return 1;
        }
        else if (str[str.length() - 1] == 'h' && str[str.length() - 2] == 's')
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int PluralNum;
    int ObjectNum;

    cin >> PluralNum;
    cin >> ObjectNum;

    string errorName[PluralNum];
    string PluralName[PluralNum];

    for (int i = 0; i < PluralNum; i++)
    {
        cin >> errorName[i];
        cin >> PluralName[i];
    }

    for (int i = 0; i < ObjectNum; i++)
    {

        string input;
        string output;
        cin >> input;

        int inList = 0;
        int yflag = 0;
        int tailFlag = 0;
        for (int j = 0; j < PluralNum; j++)
        {
            if (input.compare(errorName[j]) == 0)
            {
                cout << PluralName[j] << endl;
                inList = 1;
                break;
            }
        }
        if (!inList)
        {
            if (input[input.length() - 1] == 'y')
            {
                if (input[input.length() - 2] == 'a' || input[input.length() - 2] == 'e' || input[input.length() - 2] == 'i' || input[input.length() - 2] == 'o' || input[input.length() - 2] == 'u')
                {
                }
                else
                {
                    output = input.substr(0, input.length() - 1);
                    yflag = 1;
                }
            }
            else if (checkTail(input))
            {
                tailFlag = 1;
            }

            if (yflag)
            {
                cout << output << "ies" << endl;
            }
            else if (tailFlag)
            {
                cout << input << "es" << endl;
            }
            else
            {
                cout << input << "s" << endl;
            }
        }
    }

    return 0;
}
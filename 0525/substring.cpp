#include <iostream>
#include <string>
using namespace std;


int main()
{
    int taskNum;
    cin >> taskNum;
    
    for (int i = 0; i < taskNum; i++)
    {
        string input;
        int queryNum;

        cin >> input;
        cin >> queryNum;

        for (int j = 0; j < queryNum; j++)
        {
            string queryStr;
            cin >> queryStr;

            if( input.find(queryStr) != -1){
                cout << "y" << endl;
            }
            else{
                cout << "n" << endl;
            }
        }
    }
    return 0;
}
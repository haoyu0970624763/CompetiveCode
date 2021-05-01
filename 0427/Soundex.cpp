#include <iostream>
using namespace std;
int main()
{
    string str;
    const int CodingTable[] = { 0,1,2,3,0,1,2,0,0,2,2,4,5,
                                5,0,1,2,6,2,3,0,1,0,2,0,2 };
    int preCode ;
    while (cin >> str)
    {
        preCode = -1;
        for (size_t i = 0; i < str.length(); i++)
        {
            int tmp=CodingTable[str[i]-'A'];
            if(tmp!= 0){
                if(tmp != preCode)
                cout << tmp;
            }
            preCode = tmp;
        }
        cout << endl;
    }
    return 0;
}
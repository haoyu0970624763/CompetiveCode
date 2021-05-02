#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char flower[4][10] = {"Clubs", "Diamonds", "Hearts", "Spades"};
char value[13][10] = {"2", "3", "4", "5", "6", "7", "8", "9", "10",
                      "Jack", "Queen", "King", "Ace"};
int shuffleTable[101][53];
int card[53];
int ans[53];

void doShuffle(int shuffleNum)
{

    for (int i = 1; i <= 52; ++i)
    {
        ans[i] = card[shuffleTable[shuffleNum][i]];
    }
    for (int i = 1; i <= 52; ++i)
    {
        card[i] = ans[i];
    }
}

int main()
{
    char input[100];
    int CaseNum;
    int shuffleIndex;
    int shuffleNum;
    char shuffleID[10];

    scanf("%d", &CaseNum);
    while (CaseNum--)
    {
        scanf("%d", &shuffleNum);

        for (int i = 1; i <= shuffleNum; i++)
        {
            for (int j = 1; j <= 52; j++)
            {
                scanf("%d", &shuffleTable[i][j]);
            }
        }

        for (int i = 1; i <= 52; i++)
        {
            card[i] = i;
        }

        // read the '\n' after number
        gets(input);

        // read k'th shuffle
        while (gets(input))
        {
            // input equal to blank line
            if (input[0] == '\0')
            {
                break;
            }
            else
            {
                shuffleIndex=atoi(input);
                doShuffle(shuffleIndex);
            }
        }
        for (int i = 1; i <= 52; i++)
        {
            int cardIndex = card[i] - 1;
            printf("%s of %s\n", value[cardIndex % 13], flower[cardIndex / 13]);
        }

        if (CaseNum> 0)
        {
            printf("\n");
        }
    }
    return 0;
}
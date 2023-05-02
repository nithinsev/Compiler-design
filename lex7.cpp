#include<stdio.h>
#include<string.h>
#include<ctype.h>

char grammar[100][100];
char first[100][100];
int n;

void First(char symbol)
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        if(grammar[i][0] == symbol)
        {
            if(islower(grammar[i][2]))
            {
                first[symbol-'A'][grammar[i][2]-'a'] = 1;
            }
            else
            {
                j = 2;
                while(grammar[i][j] != '\0')
                {
                    if(isupper(grammar[i][j]))
                    {
                        First(grammar[i][j]);
                        for(k = 0; k < 26; k++)
                        {
                            if(first[grammar[i][j]-'A'][k])
                            {
                                first[symbol-'A'][k] = 1;
                            }
                        }
                        if(!first[grammar[i][j]-'A']['e'-'a'])
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                    j++;
                }
                if(grammar[i][j] == '\0')
                {
                    first[symbol-'A']['e'-'a'] = 1;
                }
                else if(islower(grammar[i][j]))
                {
                    first[symbol-'A'][grammar[i][j]-'a'] = 1;
                }
            }
        }
    }
}

int main()
{
    int i, j;
    char symbol;
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%s", grammar[i]);
    }
    for(i = 0; i < n; i++)
    {
        symbol = grammar[i][0];
        if(isupper(symbol))
        {
            First(symbol);
        }
    }
    printf("FIRST( ) - predictive parser:\n");
    for(i = 0; i < 26; i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(first[i][j])
            {
                printf("FIRST(%c) = {%c}\n", i+'A', j+'a');
            }
        }
        if(first[i]['e'-'a'])
        {
            printf("FIRST(%c) = {e}\n", i+'A');
        }
    }
    return 0;
} 

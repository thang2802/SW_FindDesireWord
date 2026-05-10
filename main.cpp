#include <stdio.h>
#include <string.h>
#include <math.h>


int MaxTimePressed(char* A, char* B, int len);
char* SubStringFromB(char* source, int start, int end, char* target);

char* SubStringFromB(char* source, int start, int end, char* target)
{
    strncpy(target, source+start, end);
    target[end] = '\0';
    return target;
}

int MaxTimePressed(char* A, char* B, int len)
{
    int ans, i = 0;
    char subString[len];
    int lenA = strlen(A);
    while (i < lenA)
    {
        SubStringFromB(A, i, len, subString);
        if(strcmp(subString,B) == 0)
        {
            i+= len;
        }
        else
        {
            i++;
        }
        ans++;
    }

    return ans;
}

int main(void)
{
    int test_case;
    int T;
    char stringA[10001];
    char stringB[101];
    int lenOfB = 0;
    int result = 0;

    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%s", &stringA);
        scanf("%s", &stringB);
        lenOfB = strlen(stringB);
        result = MaxTimePressed(stringA, stringB, lenOfB);
        printf("#%d %d\n", test_case, result);
    }
}
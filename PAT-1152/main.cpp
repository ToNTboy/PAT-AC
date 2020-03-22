#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 1002

int L, K, t;
char digit[MAXN];

bool isprime(int d)
{
    if (d < 2) return false;
    int i = 2;
    while (i * i <= d)
    {
        if (d % i == 0)
            return false;
        i++;
    }
    return true;
}

bool judge(char *d, int idx, int k)
{
    int td;
    char tmp[11];
    strncpy(tmp, d + idx, k);
    tmp[k] = '\0';
    sscanf(tmp, "%d", &td);
    return isprime(td);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &L, &K);
    scanf("%s", digit);
    REP(i, 0, L-K+1)
    {
        if (judge(digit, i, K))
        {
            REP(j, 0, K)
                printf("%c", digit[i+j]);
            printf("\n");
            return 0;
        }
    }
    printf("404\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

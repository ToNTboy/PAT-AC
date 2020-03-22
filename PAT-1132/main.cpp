#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 12

int n, t;
char digit[MAXN], t1[MAXN], t2[MAXN];

bool test(char *a, char *b, char *c, int s)
{
    int m = s / 2, x, y, z;
    strncpy(b, a, m);
    b[m] = '\0';
    strncpy(c, a+m, m);
    c[m] = '\0';
    sscanf(a, "%d", &z);
    sscanf(b, "%d", &x);
    sscanf(c, "%d", &y);
    if (x * y == 0) return false;
    return z % (x * y) == 0;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%s", digit);
        int k = strlen(digit);
        if (test(digit, t1, t2, k))
            printf("Yes\n");
        else
            printf("No\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

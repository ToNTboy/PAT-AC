#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define LOCAL

int n, m, l, maxlen;
int exist[201], favor[201], stripe[10001];
int dp[201][10001];

int mxlen(int f, int s)
{
    if (f >= m || s >= l)
        return 0;
    if (dp[f][s] != -1)
        return dp[f][s];
    if (favor[f] == stripe[s])
        return (dp[f][s] = mxlen(f, s + 1) + 1);
    else
        return (dp[f][s] = max(mxlen(f + 1, s), mxlen(f, s + 1)));
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int t;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i=0; i<m; i++)
    {
        scanf("%d", &favor[i]);
        exist[favor[i]] = 1;
    }
    scanf("%d", &l);
    for (int i=0; i<l;)
    {
        scanf("%d", &t);
        if (!exist[t])
            l--;
        else
            stripe[i++] = t;
    }
    printf("%d\n", mxlen(0, 0));

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

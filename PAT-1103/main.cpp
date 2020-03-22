#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 401

int n, k, p;
int dp[MAXN][MAXN], sum[MAXN][MAXN], pw[MAXN];

int mypow(int n, int p)
{
    if (pw[n] != 0)
        return pw[n];
    if (n == 1)
        return 1;
    int res = 1;
    while (p--)
        res *= n;
    pw[n] = res;
    return res;
}

bool solve(int n, int k, int p)
{
    if (dp[n][k] != -1)
        return dp[n][k];
    if (n < 1)
        return false;
    if (k == 1)
    {
        int i = 1, res;
        while ((res = mypow(i, p)) < n)
            i++;
        if (res == n)
            sum[n][k] = i;
        return (dp[n][k] = (res == n? i : 0));
    }
    int i = 1, t;
    while (mypow(i, p) < n)
        i++;
    i--;
    while ((t = mypow(i, p)) < n && i > 0)
    {
        if (solve(n - t, k - 1, p))
        {
            if (sum[n][k] < sum[n-t][k-1] + i)
            {
                sum[n][k] = sum[n-t][k-1] + i;
                dp[n][k] = i;
            }
        }
        i--;
    }
    if (dp[n][k] == -1)
        dp[n][k] = 0;
    return dp[n][k];
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    memset(dp, -1, sizeof(dp));
    memset(sum, -1, sizeof(sum));
    scanf("%d %d %d", &n, &k, &p);
    bool res = solve(n, k, p);
    if (res)
    {
        printf("%d = ", n);
        while (dp[n][k] > 0)
        {
            printf(k==1?"%d^%d\n":"%d^%d + ", dp[n][k], p);
            n = n - mypow(dp[n][k], p);
            k--;
        }
    }
    else
        printf("Impossible\n");


#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

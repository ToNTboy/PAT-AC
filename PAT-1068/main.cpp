#include <bits/stdc++.h>

using namespace std;

#define LOCAL

int n, m;
int c[10001];
int dp[10001][101];
/*
vector<int> sel;

bool dp1(int idx, int pay)
{
    // cause time-out for calculating too much duplicate instance
    if (idx >= n || pay < 0)
        return false;
    if (c[idx] == pay)
    {
        sel.push_back(c[idx]);
        return true;
    }
    sel.push_back(c[idx]);
    if (dp(idx+1, pay-c[idx]))
        return true;
    sel.pop_back();
    if (dp(idx+1, pay))
        return true;
    return false;
}
*/
int dp2()
{
    for (int i=n-1; i>=0; i--)
    {
        for (int j=0; j<=m; j++)
        {
            dp[i][j] = (i==n-1?(c[i]<=j?c[i]:0):dp[i+1][j]);
            if (j >= c[i] && i<n-1)
            {
                if (dp[i][j]<dp[i+1][j-c[i]]+c[i])
                    dp[i][j] = dp[i+1][j-c[i]]+c[i];
            }
        }
    }
    return dp[0][m];
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &c[i]);
    }
    sort(c, c+n);

    if (dp2() == m)
    {
        int i=0, j=m;
        int pay = m;
        while(i<n-1 && j>=c[i] && dp[i][j] != 0)
        {
            if (dp[i+1][j-c[i]] == j-c[i])
            {
                printf(j-c[i]==0?"%d\n":"%d ", c[i]);
                j -= c[i];
            }
            i++;
        }
        if (j!=0)
        {
            printf("%d\n", c[n-1]);
        }
    }
    else
        printf("No Solution\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

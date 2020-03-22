#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 100001

typedef struct seller
{
    int vis;
    vector<int> nxt;
} seller;

int n, k, t, dep = INT_MAX, dn;
double p, r;
seller s[MAXN];

void dfs(int r, int d)
{
    s[r].vis = 1;
    for (int i=0; i<s[r].nxt.size(); i++)
    {
        if (!s[s[r].nxt[i]].vis)
            dfs(s[r].nxt[i], d+1);
    }
    if (s[r].nxt.size() == 0)
    {
        if (d < dep)
        {
            dep = d;
            dn = 1;
        }
        else if (d == dep)
        {
            dn++;
        }
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %lf %lf\n", &n, &p, &r);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &k);
        for (int j=0; j<k; j++)
        {
            scanf("%d", &t);
            s[i].nxt.push_back(t);
        }
    }
    dfs(0, 0);
    double lp = p;
    while (dep--)
        lp *= (1+r/100);
    printf("%.4lf %d\n", lp, dn);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

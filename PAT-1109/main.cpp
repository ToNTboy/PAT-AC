#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10001

typedef struct people
{
    char name[9];
    int height;
} people;

int n, k, t, cap;
people g[MAXN];

bool cmp(const people& a, const people& b)
{
    if (a.height == b.height)
        return strcmp(a.name, b.name) > 0;
    return a.height < b.height;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &n, &k);
    cap = n / k;
    REP(i, 0, n)
        scanf("%s %d", g[i].name, &g[i].height);
    sort(g, g+n, cmp);
    vector<vector<int> > f(k);
    REP(i, 0, k)
    {
        int tsize = (i==k-1? cap+n%cap : cap), lw = i * cap, hi = lw + tsize, mid = tsize / 2;
        f[i].resize(tsize);
        f[i][mid] = --hi;
        int j = 1;
        while (hi > lw)
        {
            if (hi > lw) f[i][mid-j] = --hi;
            if (hi > lw) f[i][mid+j] = --hi;
            j++;
        }
    }
    REP(i, 0, k)
    {
        vector<int>& r = f[k-1-i];
        REP(j, 0, r.size())
            printf(j==0?"%s":" %s", g[r[j]].name);
        printf("\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

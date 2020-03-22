#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10001

int n, m, k, t;
int color[MAXN];
vector<pair<int, int> > es;
set<int> cols;

bool solve()
{
    REP(i, 0, es.size())
    {
        int v1 = es[i].first, v2 = es[i].second;
        if (color[v1] == color[v2])
            return false;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int v1, v2;
    scanf("%d %d", &n, &m);
    REP(i, 0, m)
    {
        scanf("%d %d", &v1, &v2);
        es.push_back(make_pair(v1, v2));
    }
    scanf("%d", &k);
    REP(i, 0, k)
    {
        cols.clear();
        REP(j, 0, n)
        {
            scanf("%d", &color[j]);
            cols.insert(color[j]);
        }
        if (solve())
            printf("%d-coloring\n", cols.size());
        else
            printf("No\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

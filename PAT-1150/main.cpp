#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 201

typedef struct city
{
    vector<int> adj;
    vector<int> adt;
} city;

int n, m, k, t;
city g[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int c1, c2, td, tc;
    scanf("%d %d", &n, &m);
    REP(i, 0, m)
    {
        scanf("%d %d %d", &c1, &c2, &td);
        g[c1].adj.push_back(c2);
        g[c1].adt.push_back(td);
        g[c2].adj.push_back(c1);
        g[c2].adt.push_back(td);
    }
    scanf("%d", &k);
    vector<vector<int> > paths(k);
    vector<int> pdist(k, 0), ptype(k, 0);
    REP(i, 0, k)
    {
        scanf("%d", &t);
        REP(j, 0, t)
        {
            scanf("%d", &tc);
            paths[i].push_back(tc);
        }
    }
    REP(i, 0, k)
    {
        vector<int>& p = paths[i];
        set<int> vis;
        bool simple = true;
        bool cycle = false;
        int s = -1, e = -1, totald = 0;
        REP(v, 0, p.size())
        {
            int pd = -1;
            if (v != p.size() - 1 && vis.count(p[v]) != 0)
                simple = false;
            vis.insert(p[v]);
            if (v == 0) s = p[v];
            if (v == p.size() - 1)
            {
                e = p[v];
                if (vis.size() < n)
                    ptype[i] = -1;
                else if (s == e)
                    ptype[i] = simple? 1 : 0;
                else
                    ptype[i] = -1;
                break;
            }
            REP(j, 0, g[p[v]].adj.size())
            {
                if (g[p[v]].adj[j] == p[v+1])
                    pd = g[p[v]].adt[j];
            }
            if (pd == -1)
            {
                totald = -1;
                pdist[i] = -1;
                ptype[i] = -1;
                break;
            }
            pdist[i] += pd;
        }
        if (ptype[i] == -1)
            pdist[i] == -1? printf("Path %d: NA (Not a TS cycle)\n", i+1) : printf("Path %d: %d (Not a TS cycle)\n", i+1, pdist[i]);
        else if (ptype[i] == 0)
            printf("Path %d: %d (TS cycle)\n", i+1, pdist[i]);
        else
            printf("Path %d: %d (TS simple cycle)\n", i+1, pdist[i]);
    }
    int sd = INT_MAX, x = -1;
    REP(i, 0, k)
    {
        if (ptype[i] == -1)
            continue;
        if (pdist[i] < sd)
        {
            sd = pdist[i];
            x = i+1;
        }
    }
    printf("Shortest Dist(%d) = %d\n", x, sd);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

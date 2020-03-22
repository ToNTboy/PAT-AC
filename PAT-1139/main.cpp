#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000

typedef struct vertex
{
    int gender;
    set<int> adj;
} vtx;

int n, m, k;
vtx g[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int p1, p2;
    char t1[6], t2[6];
    scanf("%d %d", &n, &m);
    REP(i, 0, m)
    {
        scanf("%s %s", t1, t2);
        sscanf(t1, "%d", &p1);
        sscanf(t2, "%d", &p2);
        g[abs(p1)].gender = t1[0] == '-'? -1 : 1;
        g[abs(p2)].gender = t2[0] == '-'? -1 : 1;
        g[abs(p1)].adj.insert(abs(p2));
        g[abs(p2)].adj.insert(abs(p1));
    }
    scanf("%d", &k);
    REP(i, 0, k)
    {
        vector<pair<int, int> > res;
        scanf("%d %d", &p1, &p2);
        p1 = abs(p1);
        p2 = abs(p2);
        set<int>::iterator it1 = g[p1].adj.begin(), it2;
        for (it1; it1 != g[p1].adj.end(); it1++)
        {
            if (g[*it1].gender != g[p1].gender || *it1 == p2)
                continue;
            it2 = g[*it1].adj.begin();
            for (it2; it2 != g[*it1].adj.end(); it2++)
            {
                if (g[*it2].gender != g[p2].gender || *it2 == p2 || *it2 == p1)
                    continue;
                if (g[p2].adj.count(*it2) > 0)
                    res.push_back(make_pair(*it1, *it2));
            }
        }
        printf("%d\n", res.size());
        REP(j, 0, res.size())
        {
            printf("%04d %04d\n", res[j].first, res[j].second);
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

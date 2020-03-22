#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 201

int n, m, k, tn, tv, vis[MAXN];
vector<int> adj[MAXN], path;
set<int> vs;

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
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    scanf("%d", &k);
    REP(i, 0, k)
    {
        bool hami = true;
        path.clear();
        vs.clear();
        scanf("%d", &tn);
        REP(j, 0, tn)
        {
            scanf("%d", &tv);
            path.push_back(tv);
        }
        REP(j, 0, tn)
        {
            bool adjc = false;
            tv = path[j];
            if (j == tn-1)
            {
                if (tv == path[0] && vs.size() == n)
                    break;
                else
                {
                    hami = false;
                    break;
                }
            }
            REP(u, 0, adj[tv].size())
            {
                if (adj[tv][u] == path[j+1])
                {
                    adjc = true;
                    break;
                }
            }
            if (!adjc)
            {
                hami = false;
                break;
            }
            if (vs.count(tv) > 0)
            {
                hami = false;
                break;
            }
            vs.insert(tv);
        }
        if (hami)
            printf("YES\n");
        else
            printf("NO\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

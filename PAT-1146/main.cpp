#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 1001

typedef struct node
{
    int rindgr, cindgr;
    vector<int> adj;
} node;

int n, m, k, t;
node g[MAXN];
vector<int> res;

void reset()
{
    for (int i=1; i<=n; i++)
    {
        g[i].cindgr = g[i].rindgr;
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int v1, v2;
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++)
    {
        scanf("%d %d", &v1, &v2);
        g[v1].adj.push_back(v2);
        g[v2].rindgr++;
    }
    scanf("%d", &k);
    for (int i=0; i<k; i++)
    {
        reset();
        bool ok = true;
        for (int j=0; j<n; j++)
        {
            scanf("%d", &t);
            if (!ok) continue;
            if (g[t].cindgr > 0)
            {
                res.push_back(i);
                ok = false;
            }
            else
            {
                for (int u=0; u<g[t].adj.size(); u++)
                    g[g[t].adj[u]].cindgr--;
            }
        }
    }
    for (int i=0; i<res.size(); i++)
        printf(i==0? "%d": " %d", res[i]);
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

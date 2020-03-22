#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10001

typedef struct node
{
    vector<int> adj;
} node;

int n, m, k, t, v;
set<int> qv;
node g[MAXN];

bool check()
{
    REP(i, 0, n)
    {
        REP(j, 0, g[i].adj.size())
        {
            int v1 = i, v2 = g[i].adj[j];
            if (qv.count(v1) == 0 && qv.count(v2) == 0)
                return false;
        }
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
        g[v1].adj.push_back(v2);
        g[v2].adj.push_back(v1);
    }
    scanf("%d", &k);
    REP(i, 0, k)
    {
        qv.clear();
        scanf("%d", &t);
        REP(j, 0, t)
        {
            scanf("%d", &v);
            qv.insert(v);
        }
        printf(check()?"Yes\n":"No\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

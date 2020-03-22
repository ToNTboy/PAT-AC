#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 501

int n, m, c, vis[MAXN];
int degree[MAXN];
vector<int> adj[MAXN];

void dfs(int v)
{
    vis[v] = 1;
    c++;
    REP(i, 0, adj[v].size())
    {
        if (!vis[adj[v][i]])
            dfs(adj[v][i]);
    }
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
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        degree[v1]++;
        degree[v2]++;
    }
    int even = 0, odd = 0;
    REP(i, 1, n+1)
    {
        printf(i==1?"%d":" %d", degree[i]);
        if (degree[i]&1)
            odd++;
        else
            even++;
    }
    printf("\n");
    dfs(1);
    if (c == n && even == n)
        printf("Eulerian\n");
    else if (c == n && odd == 2)
        printf("Semi-Eulerian\n");
    else
        printf("Non-Eulerian\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

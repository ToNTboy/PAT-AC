#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000

typedef struct vertex
{
    int pre, eline;
    set<int> line;
    vector<int> adj;
    vector<int> adjline;
} vtx;

typedef struct cmp
{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

int n, m, k, t, s, d, ls[101], vis[MAXN], dist[MAXN], tran[MAXN];
vtx g[MAXN];

void dijkstra(int src)
{
    memset(dist, 0x7F, sizeof(dist));
    memset(tran, 0, sizeof(tran));
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    dist[src] = 0;
    tran[src] = g[src].line.size() > 1? 1 : 0;
    q.push(make_pair(src, 0));
    while (!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        int tv = p.first;
        int td = p.second;
        if (vis[tv])
            continue;
        vis[tv] = 1;
        REP(i, 0, g[tv].adj.size())
        {
            int a = g[tv].adj[i];
            if (vis[a])
                continue;
            if (td + 1 < dist[a])
            {
                dist[a] = td + 1;
                tran[a] = tran[tv] + (g[tv].eline == g[tv].adjline[i]? 0 : 1);
                g[a].pre = tv;
                g[a].eline = g[tv].adjline[i];
            }
            else if (td + 1 == dist[a])
            {
                if (tran[tv] + (g[tv].eline == g[tv].adjline[i]? 0 : 1) < tran[a])
                {
                    tran[a] = tran[tv] + (g[tv].eline == g[tv].adjline[i]? 0 : 1);
                    g[a].pre = tv;
                    g[a].eline = g[tv].adjline[i];
                }
                else
                    continue;
            }
            else
                continue;
            q.push(make_pair(a, td+1));
        }
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &m);
        REP(j, 0, m)
            scanf("%d", &ls[j]);
        REP(j, 0, m)
        {
            g[ls[j]].line.insert(i+1);
            if (j > 0)
            {
                g[ls[j]].adj.push_back(ls[j-1]);
                g[ls[j]].adjline.push_back(i+1);
            }
            if (j < m-1)
            {
                g[ls[j]].adj.push_back(ls[j+1]);
                g[ls[j]].adjline.push_back(i+1);
            }
        }
    }
    scanf("%d", &k);
    REP(i, 0, k)
    {
        scanf("%d %d", &s, &d);
        dijkstra(s);
        printf("%d\n", dist[d]);
        vector<pair<int, int> > path;
        int c = d;
        int pline = -1;
        while (c != s)
        {
            if (g[c].eline != pline)
                path.push_back(make_pair(g[c].eline, c));
            pline = g[c].eline;
            c = g[c].pre;
        }
        path.push_back(make_pair(-1, s));
        REP(j, 1, path.size())
        {
            pair<int, int>& p2 = path[path.size()-1-j];
            pair<int, int>& p1 = path[path.size()-j];
            printf("Take Line#%d from %04d to %04d.\n", p2.first, p1.second, p2.second);
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

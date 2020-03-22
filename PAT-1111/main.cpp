#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 510

typedef struct edge
{
    int to, dist, tme;
} edge;

typedef struct cmp
{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
} cmp;

int n, m, src, des;
int dist[MAXN], tme[MAXN], vis[MAXN], lv[MAXN], pre[MAXN], dpc[MAXN], tpc[MAXN];
int mind, mint, minlv;
vector<edge> g[MAXN];
vector<int> spath, tpath;

void dijkstra1(int s)
{
    memset(dist, 0x7F, sizeof(dist));
    memset(tme, 0x7F, sizeof(tme));
    memset(vis, 0, sizeof(vis));
    memset(lv, 0x7F, sizeof(lv));
    memset(pre, -1, sizeof(pre));
    memset(dpc, 0x7F, sizeof(dpc));
    memset(tpc, 0x7F, sizeof(tpc));
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    dist[s] = 0;
    tme[s] = 0;
    lv[s] = 1;
    q.push(make_pair(s, 0));
    while (!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        int tv = p.first;
        int tc = p.second;
        if (vis[tv])
            continue;
        vis[tv] = 1;
        REP(i, 0, g[tv].size())
        {
            int adj = g[tv][i].to;
            int cdist = g[tv][i].dist;
            int ctme = g[tv][i].tme;
            if (vis[adj])
                continue;
            if (tc + cdist < dist[adj])
            {
                pre[adj] = tv;
                dist[adj] = tc + cdist;
                tme[adj] = tme[tv] + ctme;
                dpc[adj] = cdist;
                tpc[adj] = ctme;
                lv[adj] = lv[tv] + 1;
                q.push(make_pair(adj, dist[adj]));
            }
            else if (tc + cdist == dist[adj])
            {
                if (tme[tv] + ctme < tme[adj])
                {
                    pre[adj] = tv;
                    tme[adj] = tme[tv] + ctme;
                    dpc[adj] = cdist;
                    tpc[adj] = ctme;
                    lv[adj] = lv[tv] + 1;
                }
            }
        }
    }
}

void dijkstra2(int s)
{
    memset(dist, 0x7F, sizeof(dist));
    memset(tme, 0x7F, sizeof(tme));
    memset(vis, 0, sizeof(vis));
    memset(lv, 0x7F, sizeof(lv));
    memset(pre, -1, sizeof(pre));
    memset(dpc, 0x7F, sizeof(dpc));
    memset(tpc, 0x7F, sizeof(tpc));
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    dist[s] = 0;
    tme[s] = 0;
    lv[s] = 1;
    q.push(make_pair(s, 0));
    while (!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        int tv = p.first;
        int tc = p.second;
        if (vis[tv])
            continue;
        vis[tv] = 1;
        REP(i, 0, g[tv].size())
        {
            int adj = g[tv][i].to;
            int cdist = g[tv][i].dist;
            int ctme = g[tv][i].tme;
            if (vis[adj])
                continue;
            if (tc + ctme < tme[adj])
            {
                pre[adj] = tv;
                dist[adj] = dist[tv] + cdist;
                tme[adj] = tc + ctme;
                dpc[adj] = cdist;
                tpc[adj] = ctme;
                lv[adj] = lv[tv] + 1;
                q.push(make_pair(adj, tme[adj]));
            }
            else if (tc + ctme == tme[adj])
            {
                if (lv[tv] + 1 < lv[adj])
                {
                    pre[adj] = tv;
                    dist[adj] = dist[tv] + cdist;
                    dpc[adj] = cdist;
                    tpc[adj] = ctme;
                    lv[adj] = lv[tv] + 1;
                }
            }
        }
    }
}

void dumpPath(int des, vector<int>& p)
{
    p.push_back(des);
    while (pre[des] != -1)
    {
        des = pre[des];
        p.push_back(des);
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int v1, v2, single, d, t;
    scanf("%d %d", &n, &m);
    REP(i, 0, m)
    {
        scanf("%d %d %d %d %d", &v1, &v2, &single, &d, &t);
        edge te1 = {v2, d, t};
        g[v1].push_back(te1);
        if (!single)
        {
            edge te2 = {v1, d, t};
            g[v2].push_back(te2);
        }
    }
    scanf("%d %d", &src, &des);
    dijkstra1(src);
    dumpPath(des, spath);
    mind = dist[des];
    dijkstra2(src);
    dumpPath(des, tpath);
    mint = tme[des];
    if (spath == tpath)
    {
        printf("Distance = %d; Time = %d: ", mind, mint);
        REP(i, 0, spath.size())
            printf(i==0?"%d":" -> %d", spath[spath.size()-1-i]);
        printf("\n");
    }
    else
    {
        printf("Distance = %d: ", mind);
        REP(i, 0, spath.size())
            printf(i==0?"%d":" -> %d", spath[spath.size()-1-i]);
        printf("\n");
        printf("Time = %d: ", mint);
        REP(i, 0, tpath.size())
            printf(i==0?"%d":" -> %d", tpath[tpath.size()-1-i]);
        printf("\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

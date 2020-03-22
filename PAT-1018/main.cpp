#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;

#define LOCAL
#define MAXN 501

typedef struct vertex
{
    int cur;
    int vis;
} vtx;

typedef struct edge
{
    int d, v;
} edge;

struct cmp
{
    bool operator() (const edge& a, const edge& b)
    {
        return a.d > b.d;
    }
};

int cap, hfc, n, s, m;
int e[MAXN][MAXN];
int bk[MAXN], vis[MAXN], d[MAXN], mincar = INT_MAX, minrem = INT_MAX;
vector<int> pre[MAXN], path;

void dijkstra()
{
    priority_queue<edge, vector<edge>, cmp> q;
    edge root = {0, 0};
    q.push(root);
    while (!q.empty())
    {
        int v = q.top().v;
        q.pop();
        if (vis[v])
            continue;
        for (int i=1; i<=n; i++)
        {
            if (e[v][i])
            {
                if (d[i] > d[v] + e[v][i])
                {
                    d[i] = d[v] + e[v][i];
                    pre[i].clear();
                    pre[i].push_back(v);
                    edge e = {d[i], i};
                    q.push(e);
                }
                else if (d[i] == d[v] + e[v][i])
                {
                    pre[i].push_back(v);
                }
            }
        }
        vis[v] = 1;
    }
}

void dfs(int s, vector<int>& p)
{
    if (pre[s].empty())
    {
        int carry = 0, remain = 0;
        for (int i=p.size()-1; i>=0; i--)
        {
            int t = bk[p[i]];
            if (t < hfc)
            {
                if (remain < hfc - t)
                {
                    carry += (hfc - t - remain);
                    remain = 0;
                }
                else
                {
                    remain -= (hfc - t);
                }
            }
            else
            {
                remain += (t - hfc);
            }
        }
        if (carry < mincar)
        {
            mincar = carry;
            minrem = remain;
            path.assign(p.begin(), p.end());
        }
        else if (carry == mincar && remain < minrem)
        {
            mincar = carry;
            minrem = remain;
            path.assign(p.begin(), p.end());
        }
        return;
    }
    p.push_back(s);
    for (int i=0; i<pre[s].size(); i++)
    {
        dfs(pre[s][i], p);
    }
    p.pop_back();
}

void print_path()
{
    printf("0");
    for (int i=path.size()-1; i>=0; i--)
    {
        printf("->%d", path[i]);
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    memset(d, 0x7F, sizeof(d));
    d[0] = 0;
    int fr, to, time;
    scanf("%d %d %d %d", &cap, &n, &s, &m);
    hfc = cap >> 1;
    for (int i=1; i<=n; i++)
        scanf("%d", &bk[i]);
    for (int i=1; i<=m; i++)
    {
        scanf("%d %d %d", &fr, &to, &time);
        e[fr][to] = time;
        e[to][fr] = time;
    }

    dijkstra();
    vector<int> p;
    int c = 0;
    dfs(s, p);
    printf("%d ", mincar);
    print_path();
    printf(" %d\n", minrem);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

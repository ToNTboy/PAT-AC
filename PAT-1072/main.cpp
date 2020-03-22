#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define lli long long int

typedef struct node
{
    int id;
    lli far;
    vector<int> next;
    vector<lli> dist;
} node;

typedef struct item
{
    int id;
    lli far;
} item;

typedef struct cmp
{
    bool operator() (const item& a, const item& b)
    {
        return a.far > b.far;
    }
} cmp;

char t1[5], t2[5];
int n, m, k;
lli ds;
lli mdist=0, mtd=LLONG_MAX;
int midx, vis[1011];
node v[1011];

int ID(char *s)
{
    int id = 0;
    if (s[0] == 'G')
    {
        sscanf(s+1, "%d", &id);
        return id + n;
    }
    sscanf(s, "%d", &id);
    return id;
}

void reset()
{
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n+m; i++)
        v[i].far = LLONG_MAX;
}

void dijkstra(int id)
{
    reset();
    priority_queue<item, vector<item>, cmp> q;
    v[id].far = 0;
    item start = {id, 0};
    q.push(start);
    while (!q.empty())
    {
        item it = q.top();
        q.pop();
        if (vis[it.id])
            continue;
        vis[it.id] = 1;
        for (int i=0; i<v[it.id].next.size(); i++)
        {
            if (vis[v[it.id].next[i]])
                continue;
            lli cfar = v[it.id].far;
            lli cdist = v[it.id].dist[i];
            lli nfar = v[v[it.id].next[i]].far;
            if (cfar + cdist < nfar)
            {
                v[v[it.id].next[i]].far = cfar + cdist;
                item nit = {v[it.id].next[i], cfar + cdist};
                q.push(nit);
            }
        }
    }

}

void prt()
{
    for (int i=1; i<=n+m; i++)
    {
        printf("idx:%d far:%lld\n", i, v[i].far);
    }
    printf("---------\n");
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int fr, to;
    lli td;
    scanf("%d %d %d %lld", &n, &m, &k, &ds);
    for (int i=0; i<k; i++)
    {
        scanf("%s %s %lld", t1, t2, &td);
        fr = ID(t1);
        to = ID(t2);
        v[fr].next.push_back(to);
        v[fr].dist.push_back(td);
        v[to].next.push_back(fr);
        v[to].dist.push_back(td);
    }
    for (int i=n+1; i<=n+m; i++)
    {
        dijkstra(i);
        lli sum = 0, md = LLONG_MAX;
        bool ok = true;
        for (int j=1; j<=n; j++)
        {
            if (v[j].far > ds)
            {
                ok = false;
                break;
            }
            if (v[j].far < md)
                md = v[j].far;
            sum += v[j].far;
        }
        if (ok)
        {
            if (md > mdist)
            {
                mdist = md;
                mtd = sum;
                midx = i;
            }
            else if (md == mdist && sum < mtd)
            {
                mtd = sum;
                midx = i;
            }
        }
    }
    if (midx == 0)
        printf("No Solution\n");
    else
    {
        printf("G%d\n", midx - n);
        printf("%lld.0 %.1lf\n", mdist, (double)mtd / (double)n);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

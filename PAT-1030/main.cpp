#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

#define LOCAL
#define MAXN 500
#define UNDIS 0
#define DISCO 1
#define POPED 2

typedef struct way
{
    int to;
    int d;
    int c;
} way;

typedef struct city
{
    int d = INT_MAX;
    int c = 0;
    int pre = -1;
    int state = UNDIS;
    vector<way> next;
} city;

typedef struct node
{
    int id;
    int d;
    node() {}
    node(int id, int d): id(id), d(d) {}
} node;

int n, m, s, d;
city ct[MAXN];

struct cmp
{
    bool operator() (const node& a, const node& b)
    {
        return a.d > b.d;
    }
};

priority_queue<node, vector<node>, cmp > pq;

void dj()
{
    node v;
    way w;
    while (!pq.empty())
    {
        v = pq.top();
        pq.pop();
        if (ct[v.id].state == POPED)
        {
            continue;
        }

        ct[v.id].state = POPED;
        for (int i=0; i<ct[v.id].next.size(); i++)
        {
            w = ct[v.id].next[i];
            if (ct[w.to].state == POPED)
                continue;
            if (ct[w.to].d > w.d + ct[v.id].d)
            {
                ct[w.to].d = w.d + ct[v.id].d;
                ct[w.to].pre = v.id;
                ct[w.to].c = w.c + ct[v.id].c;
                pq.push(node(w.to, ct[w.to].d));
            }
            else if (ct[w.to].d == w.d + ct[v.id].d)
            {
                if (ct[w.to].c > w.c + ct[v.id].c)
                {
                    ct[w.to].pre = v.id;
                    ct[w.to].c = w.c + ct[v.id].c;
                }
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int fr, to, dist, cost;
    scanf("%d %d %d %d\n", &n, &m, &s, &d);
    for (int i=0; i<m; i++)
    {
        scanf("%d %d %d %d\n", &fr, &to, &dist, &cost);
        way w1 = {to, dist, cost};
        way w2 = {fr, dist, cost};
        ct[fr].next.push_back(w1);
        ct[to].next.push_back(w2);
    }

    ct[s].d = 0;
    pq.push(node(s, 0));
    dj();

    int p = d;
    stack<int> path;
    while (p != -1)
    {
        path.push(p);
        p = ct[p].pre;
    }
    while (!path.empty())
    {
        printf("%d ", path.top());
        path.pop();
    }
    printf("%d %d\n", ct[d].d, ct[d].c);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

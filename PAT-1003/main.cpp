#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

//#define LOCAL

typedef struct vertex
{
    int teams = 0;
    int dist = INT_MAX;
    int callon = 0;
    int pathnum = 0;
    bool poped = false;
    vector<int> next;
    vector<int> nextlen;
    vector<int> pre;
} vertex;

vertex g[500];
vector<int> max_teams;
int n, m, c1, c2;

void addCity(int no, int teams)
{
    g[no].teams = teams;
}

void addRoad(int fr, int to, int len)
{
    g[fr].next.push_back(to);
    g[fr].nextlen.push_back(len);
    g[to].next.push_back(fr);
    g[to].nextlen.push_back(len);
}

struct cmp
{
    bool operator() (const int a, const int b)
    {
        return g[a].dist > g[b].dist;
    }
};

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // input
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    int tmp_teams, tmp_fr, tmp_to, tmp_len;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp_teams);
        addCity(i, tmp_teams);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &tmp_fr, &tmp_to, &tmp_len);
        addRoad(tmp_fr, tmp_to, tmp_len);
    }
    g[c1].dist = 0;
    g[c1].pathnum = 1;
    g[c1].callon = g[c1].teams;

    // code
    priority_queue<int, vector<int>, cmp> heap;
    heap.push(c1);
    while(!heap.empty())
    {
        int pno = heap.top();
        heap.pop();
        if (g[pno].poped)
        {
            continue;
        }
        g[pno].poped = true;
        int cno, plen, clen;
        for (size_t j = 0; j < g[pno].next.size(); j++)
        {
            cno = g[pno].next[j];
            plen = g[pno].nextlen[j] + g[pno].dist;
            clen = g[cno].dist;
            if (plen < clen)
            {
                g[cno].dist = plen;
                g[cno].pathnum = g[pno].pathnum;
                g[cno].callon = g[pno].callon + g[cno].teams;
                g[cno].pre.clear();
                g[cno].pre.push_back(pno);
            }
            else if (plen == clen)
            {
                if (g[cno].callon < g[pno].callon + g[cno].teams)
                {
                    g[cno].callon = g[pno].callon + g[cno].teams;
                }
                g[cno].pathnum += g[pno].pathnum;
                g[cno].pre.push_back(pno);
            }
            heap.push(cno);
        }
    }

    // output
    printf("%d %d\n", g[c2].pathnum, g[c2].callon);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

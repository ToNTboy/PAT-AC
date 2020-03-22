#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define LOCAL
#define MAXN 26*26*26
#define ROM 11868

typedef struct node
{
    int dist;
    int happy;
    int pre;
    int prenum;
    int cnum;
    vector<int> next;
    vector<int> cost;
} node;

typedef struct vert
{
    int id, dist;
} vert;

typedef struct cmp
{
    bool operator() (const vert& a, const vert& b)
    {
        return a.dist > b.dist;
    }
} cmp;

int n, k, s, hp[MAXN];
char tmp1[4], tmp2[4], vis[MAXN];
node ct[MAXN];
priority_queue<vert, vector<vert>, cmp> q;

int ID(char *s)
{
    int a = s[0]-'A', b = s[1]-'A', c=s[2]-'A';
    return a*26*26+b*26+c;
}

char * toname(int id, char * name)
{
    name[0] = id/26/26 + 'A';
    name[1] = id/26%26 + 'A';
    name[2] = id%26 + 'A';
    name[3] = '\0';
    return name;
}

void dijkstra(int s)
{
    ct[s].dist = 0;
    ct[s].prenum = 1;
    vert start = {s, 0};
    q.push(start);
    while (!q.empty())
    {
        vert t = q.top();
        q.pop();
        if (vis[t.id] == 1)
            continue;
        for (int i=0; i<ct[t.id].next.size(); i++)
        {
            int id = ct[t.id].next[i];
            if (vis[id] == 0)
            {
                int ndist = ct[t.id].dist + ct[t.id].cost[i];
                if (ndist < ct[id].dist)
                {
                    ct[id].dist = ndist;
                    ct[id].happy = ct[t.id].happy + hp[id];
                    ct[id].cnum = ct[t.id].cnum + 1;
                    ct[id].prenum = ct[t.id].prenum;
                    ct[id].pre = t.id;
                    vert tv = {id, ndist};
                    q.push(tv);
                }
                else if (ndist == ct[id].dist)
                {
                    int nhp = ct[t.id].happy + hp[id];
                    ct[id].prenum += ct[t.id].prenum;
                    if (ct[id].happy < nhp)
                    {
                        ct[id].happy = nhp;
                        ct[id].pre = t.id;
                    }
                    else if (ct[id].happy == nhp)
                    {
                        int ncnum = ct[t.id].cnum + 1;
                        if (ct[id].cnum > ncnum)
                        {
                            ct[id].cnum = ncnum;
                            ct[id].pre = t.id;
                        }
                    }
                }
            }
        }
        vis[t.id] = 1;
    }
}

void dfs()
{

}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int thp, c1, c2, tc, id;
    scanf("%d %d %s", &n, &k, tmp1);
    s = ID(tmp1);
    ct[s].pre = -1;
    for (int i=1; i<n; i++)
    {
        scanf("%s %d", tmp1, &thp);
        id = ID(tmp1);
        hp[id] = thp;
        ct[id].dist = 0x7FFFFFFF;
    }
    for (int i=0; i<k; i++)
    {
        scanf("%s %s %d", tmp1, tmp2, &tc);
        c1 = ID(tmp1);
        c2 = ID(tmp2);
        ct[c1].next.push_back(c2);
        ct[c1].cost.push_back(tc);
        ct[c2].next.push_back(c1);
        ct[c2].cost.push_back(tc);
    }
    dijkstra(s);
    printf("%d %d %d %d\n", ct[ROM].prenum, ct[ROM].dist, ct[ROM].happy, ct[ROM].happy/ct[ROM].cnum);
    stack<int> fpath;
    fpath.push(ROM);
    int cur = ROM;
    while(ct[cur].pre != -1)
    {
        cur = ct[cur].pre;
        fpath.push(cur);
    }
    while (!fpath.empty())
    {
        printf(fpath.size()==1? "%s\n" : "%s->", toname(fpath.top(), tmp1));
        fpath.pop();
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

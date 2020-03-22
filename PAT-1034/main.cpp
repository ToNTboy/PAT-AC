#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 26*26*26

typedef struct gang
{
    int head;
    int sum;
} gang;

char tmp[4], pvis[MAXN], evis[MAXN][MAXN], p[MAXN];
int n, k;
int e[MAXN][MAXN], w[MAXN];
vector<gang> g;

bool cmp(const gang& a, const gang& b)
{
    return a.head < b.head;
}

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

void dfs(int id, int& sum, int& time, int &head, int &maxw)
{
    sum++;
    pvis[id] = 1;
    for (int i=0; i<id; i++)
    {
        if (e[i][id] > 0 && evis[i][id] == 0)
        {
            evis[i][id] = 1;
            w[i] += e[i][id];
            w[id] += e[i][id];
            time += e[i][id];
            if (w[i] > maxw)
            {
                maxw = w[i];
                head = i;
            }
            if (w[id] > maxw)
            {
                maxw = w[id];
                head = id;
            }
            if (pvis[i] == 0)
                dfs(i, sum, time, head, maxw);
        }
    }
    for (int i=id+1; i<MAXN; i++)
    {
        if (e[id][i] > 0 && evis[id][i] == 0)
        {
            evis[id][i] = 1;
            w[i] += e[id][i];
            w[id] += e[id][i];
            time += e[id][i];
            if (w[i] > maxw)
            {
                maxw = w[i];
                head = i;
            }
            if (w[id] > maxw)
            {
                maxw = w[id];
                head = id;
            }
            if (pvis[i] == 0)
                dfs(i, sum, time, head, maxw);
        }
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    char name1[4], name2[4];
    int sum, time, head, maxw;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++)
    {
        scanf("%s %s %d", name1, name2, &time);
        int id1 = ID(name1), id2 = ID(name2);
        p[id1] = p[id2] = 1;
        if (strcmp(name1, name2) > 0)
            e[id2][id1] += time;
        else
            e[id1][id2] += time;
    }
    for (int i=0; i<MAXN; i++)
    {
        if (p[i] && pvis[i] == 0)
        {
            sum=0, time =0, head=-1, maxw=0;
            dfs(i, sum, time, head, maxw);
            if (sum > 2 && time > k)
            {
                gang tg = {head, sum};
                g.push_back(tg);
            }
        }
    }
    sort(g.begin(), g.end(), cmp);
    printf("%d\n", g.size());
    for (int i=0; i<g.size(); i++)
    {
        printf("%s %d\n", toname(g[i].head, tmp), g[i].sum);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

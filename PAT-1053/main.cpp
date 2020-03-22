#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define LOCAL
#define MAXN 1000

typedef struct node
{
    int w;
    int pw;
    int state;
    vector<int> childs;
} node;

int n, m, s;
deque<int> path;
node v[MAXN];

bool cmp(const int& a, const int& b)
{
    return v[a].w > v[b].w;
}

void printpath()
{
    int id;
    deque<int>::iterator it = path.begin();
    while (it != path.end())
    {
        printf(it == path.begin()? "%d": " %d", v[*it].w);
        it++;
    }
    printf("\n");
}

void dfs(int id, int prew)
{
    sort(v[id].childs.begin(), v[id].childs.end(), cmp);
    path.push_back(id);
    v[id].pw = prew + v[id].w;
    if (v[id].pw >= s)
    {
        if (v[id].pw == s && v[id].childs.empty())
        {
            printpath();
        }
        path.pop_back();
        return;
    }
    int c;
    for (int i=0; i<v[id].childs.size(); i++)
    {
        c = v[id].childs[i];
        dfs(c, v[id].pw);
    }
    path.pop_back();
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int id, t, c;
    scanf("%d %d %d\n", &n, &m, &s);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &v[i].w);
    }
    for (int i=0; i<m; i++)
    {
        scanf("%d %d", &id, &t);
        for (int j=0; j<t; j++)
        {
            scanf("%d", &c);
            v[id].childs.push_back(c);
        }
    }
    dfs(0, 0);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

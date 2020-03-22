#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 201

typedef struct vertex
{
    set<int> adj;
} vtx;

int nv, ne, m, k, tmp[MAXN];
vtx g[MAXN];

vector<int> intersection(vector<int>& a, set<int>& b)
{
    vector<int> res(a.size()<b.size()?b.size():a.size());
    vector<int>::iterator it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), res.begin());
    res.resize(it-res.begin());
    return res;
}

int set_equal(vector<int>& a, int *b, int k)
{
    sort(b, b+k);
    vector<int>::iterator ait = a.begin();
    int bit = 0, same = 0;
    while (ait != a.end() && bit < k)
    {
        if (*ait < b[bit])
        {
            ait++;
            continue;
        }
        if (b[bit] < *ait)
        {
            bit++;
            continue;
        }
        ait++;
        bit++;
        same++;
    }
    if (same < k)
        return -1;
    if (same == k && same == a.size())
        return 1;
    return 0;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int v1, v2;
    scanf("%d %d", &nv, &ne);
    for (int i=0; i<ne; i++)
    {
        scanf("%d %d", &v1, &v2);
        g[v1].adj.insert(v2);
        g[v2].adj.insert(v1);
    }
    for (int i=1; i<=nv; i++)
        g[i].adj.insert(i);
    scanf("%d", &m);
    for (int i=0; i<m; i++)
    {
        scanf("%d", &k);
        for (int j=0; j<k; j++)
            scanf("%d", &tmp[j]);
        vector<int> s(g[tmp[0]].adj.begin(), g[tmp[0]].adj.end());
        for (int j=1; j<k; j++)
            s = intersection(s, g[tmp[j]].adj);
        int res = set_equal(s, tmp, k);
        if (res == 1)
            printf("Yes\n");
        if (res == 0)
            printf("Not Maximal\n");
        if (res == -1)
            printf("Not a Clique\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

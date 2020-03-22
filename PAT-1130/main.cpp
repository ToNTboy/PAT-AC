#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000
#define leaf(x) (tree[x].lc == -1 && tree[x].rc == -1)

typedef struct node
{
    int lc, rc, pa;
    char data[11];
} node;

int n, m, t;
char tmp[11];
set<char> oprt;
node tree[MAXN];

void init()
{
    oprt.insert('+');
    oprt.insert('-');
    oprt.insert('*');
    oprt.insert('/');
    oprt.insert('%');
    oprt.insert('!');
}

string postorder(int r)
{
    string res;
    if (oprt.count(tree[r].data[0]) == 0 && tree[r].lc == -1 && tree[r].rc == -1)
    {
        res.append(tree[r].data);
        return res;
    }
    if (tree[r].lc != -1)
    {
        if (!leaf(tree[r].lc))
            res.append("(");
        res.append(postorder(tree[r].lc));
        if (!leaf(tree[r].lc))
            res.append(")");
    }
    res.append(tree[r].data);
    if (tree[r].rc != -1)
    {
        if (!leaf(tree[r].rc))
            res.append("(");
        res.append(postorder(tree[r].rc));
        if (!leaf(tree[r].rc))
            res.append(")");
    }
    return res;
}

int root()
{
    REP(i, 1, n+1)
    {
        if (tree[i].pa == 0)
            return i;
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d\n", &n);
    REP(i, 1, n+1)
    {
        scanf("%s %d %d\n", tree[i].data, &tree[i].lc, &tree[i].rc);
        if (tree[i].lc != -1) tree[tree[i].lc].pa = i;
        if (tree[i].rc != -1) tree[tree[i].rc].pa = i;
    }
    printf("%s\n", postorder(root()).c_str());

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

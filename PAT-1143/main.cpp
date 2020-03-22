#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10001

typedef struct node
{
    int key, flag;
    node *lc, *rc, *pa;
    node(int k) : key(k), flag(0), lc(NULL), rc(NULL), pa(NULL) {}
} node;

int n, m, u, v, pseq[MAXN];
map<int, node*> tmap;

node* build(int *ps, int lw, int hi)
{
    if (hi - lw < 1)
        return NULL;
    if (hi - lw == 1)
        return tmap[ps[lw]] = new node(ps[lw]);
    int m = lw + 1;
    while (m < hi && ps[m] < ps[lw])
        m++;
    node *r = new node(ps[lw]);
    r->lc = build(ps, lw + 1, m);
    r->rc = build(ps, m, hi);
    if (r->lc) r->lc->pa = r;
    if (r->rc) r->rc->pa = r;
    return tmap[ps[lw]] = r;
}

node * LCA(node *tree, int u, int v)
{
    node *nu = tmap[u];
    node *nv = tmap[v];
    if (nu == NULL || nv == NULL)
    {
        if (nu == NULL && nv == NULL)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (nu == NULL)
            printf("ERROR: %d is not found.\n", u);
        else
            printf("ERROR: %d is not found.\n", v);
        return NULL;
    }
    while (nu != NULL)
    {
        nu->flag = u;
        nu = nu->pa;
    }
    while (nv != NULL && nv->flag != u)
    {
        nv->flag = v;
        nv = nv->pa;
    }
    if (nv->key == u)
        printf("%d is an ancestor of %d.\n", u, v);
    else if (nv->key == v)
        printf("%d is an ancestor of %d.\n", v, u);
    else
        printf("LCA of %d and %d is %d.\n", u, v, nv->key);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &m, &n);
    REP(i, 0, n)
        scanf("%d", &pseq[i]);
    node *tree = build(pseq, 0, n);
    REP(i, 0, m)
    {
        scanf("%d %d", &u, &v);
        LCA(tree, u, v);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

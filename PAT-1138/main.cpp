#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 50001

typedef struct node
{
    int key;
    node *lc, *rc;
} node;

int n, pseq[MAXN], iseq[MAXN];

node * build(int *ps, int plw, int phi, int *is, int ilw, int ihi)
{
    if (phi-plw <= 0) return NULL;
    int m;
    for (m=ilw; m<ihi; m++)
    {
        if (ps[plw] == is[m])
            break;
    }
    node *lc = build(ps, plw+1, plw+1+m-ilw, is, ilw, m);
    node *rc = build(ps, plw+1+m-ilw, phi, is, m+1, ihi);
    node *r = new node();
    r->key = ps[plw];
    r->lc = lc;
    r->rc = rc;
    return r;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &pseq[i]);
    for (int i=0; i<n; i++)
        scanf("%d", &iseq[i]);

    node *tree = build(pseq, 0, n, iseq, 0, n);
    while (tree->lc != NULL || tree->rc != NULL)
        tree = tree->lc == NULL? tree->rc : tree->lc;
    printf("%d\n", tree->key);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

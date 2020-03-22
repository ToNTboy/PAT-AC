#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000

typedef struct node
{
    int key;
    node *lc, *rc;
} node;

int n, m, t;
int iseq[MAXN], pseq[MAXN];
node *tree;
bool flag;

node * build(int *ps, int plw, int phi, int *is, int ilw, int ihi)
{
    if (phi - plw < 1) return NULL;
    int m = -1;
    REP(i, ilw, ihi)
    {
        if (is[i] == ps[phi-1])
        {
            m = i;
            break;
        }
    }
    node *r = new node();
    r->key = ps[phi-1];
    r->lc = build(ps, plw, plw+m-ilw, is, ilw, m);
    r->rc = build(ps, plw+m-ilw, phi-1, is, m+1, ihi);
    return r;
}

stack<node*> prtlevel(stack<node*>& p, bool l2r)
{
    stack<node*> s;
    while (!p.empty())
    {
        node *t = p.top();
        p.pop();
        printf(flag?" %d":"%d", t->key);
        flag = true;
        if (l2r)
        {
            if (t->lc != NULL) s.push(t->lc);
            if (t->rc != NULL) s.push(t->rc);
        }
        else
        {
            if (t->rc != NULL) s.push(t->rc);
            if (t->lc != NULL) s.push(t->lc);
        }
    }
    return s;
}

void zigzagorder(node *r)
{
    stack<node*> s;
    s.push(r);
    bool l2r = false;
    while (!(s = prtlevel(s, l2r)).empty()) l2r = !l2r;
    printf("\n");
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 0, n)
        scanf("%d", &iseq[i]);
    REP(i, 0, n)
        scanf("%d", &pseq[i]);
    tree = build(pseq, 0, n, iseq, 0, n);
    zigzagorder(tree);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 4096

typedef struct node
{
    int key, he;
    node *pa, *lc, *rc;
    int bal()
    {
        return (lc?lc->he:-1) - (rc?rc->he:-1);
    }
} node;

int n, m, tk;
node* root;

void lv_order(node *tree)
{
    if (!tree)
        return;
    deque<node*> q;
    q.push_back(tree);
    while (!q.empty())
    {
        node *t = q.front();
        q.pop_front();
        printf(t->pa? " %d": "%d", t->key);
        if (t->lc)
            q.push_back(t->lc);
        if (t->rc)
            q.push_back(t->rc);
    }
    printf("\n");
}

void updateHeight(node *t)
{
    int lch = (t->lc?t->lc->he:-1);
    int rch = (t->rc?t->rc->he:-1);
    int the = max(lch, rch);
    t->he = the + 1;
}

node * connect34(node *p, node *g, node *v, node *a, node *b, node *c, node *d)
{
    p->lc = a; if (a) a->pa = p;
    p->rc = b; if (b) b->pa = p; updateHeight(p);
    v->lc = c; if (c) c->pa = v;
    v->rc = d; if (d) d->pa = v; updateHeight(v);
    g->lc = p; p->pa = g;
    g->rc = v; v->pa = g; updateHeight(g);
    return g;
}

void rotateAt(node *r)
{
    node *p = r->pa, *g = p->pa, *gg = g->pa;
    bool left;
    if (gg) left = (gg->lc == g);
    if (r == p->lc)
    {
        if (p == g->lc)
            g = connect34(r, p, g, r->lc, r->rc, p->rc, g->rc);
        else
            g = connect34(g, r, p, g->lc, r->lc, r->rc, p->rc);
    }
    else
    {
        if (p == g->lc)
            g = connect34(p, r, g, p->lc, r->lc, r->rc, g->rc);
        else
            g = connect34(g, p, r, g->lc, p->lc, r->lc, r->rc);
    }
    g->pa = gg;
    if (gg)
    {
        if (left)
            gg->lc = g;
        else
            gg->rc = g;
    }
    else
    {
        root = g;
    }
}

void avl_insert(node *r, int k)
{
    node *t = r, *p = NULL;
    while (t != NULL)
    {
        p = t;
        if (t->key < k)
            t = t->rc;
        else
            t = t->lc;
    }
    node *tn = new node();
    tn->key = k;
    tn->pa = p;
    tn->lc = tn->rc = NULL;
    tn->he = 0;
    if (r == NULL)
    {
        root = tn;
        return;
    }
    if (p->key < k)
        p->rc = tn;
    else
        p->lc = tn;
    t = tn;
    while (t && -1 <= t->bal() && t->bal() <=1)
    {
        updateHeight(t);
        t = t->pa;
    }
    if (t)
        rotateAt(t->bal()<0? (t->rc->bal()<0? t->rc->rc: t->rc->lc): (t->lc->bal()<0? t->lc->rc: t->lc->lc));
}

bool check_cbt(node *tree)
{
    if (!tree)
        return false;
    int num = 0;
    deque<node*> q;
    q.push_back(tree);
    while (!q.empty() && num < n)
    {
        node *t = q.front();
        q.pop_front();
        if (t==NULL)
            return false;
        num++;
        q.push_back(t->lc);
        q.push_back(t->rc);
    }
    return true;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 1, n+1)
    {
        scanf("%d", &tk);
        avl_insert(root, tk);
    }
    lv_order(root);
    printf(check_cbt(root)?"YES\n":"NO\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 21
#define tallerchild(x) (balance(x)>=0?x->lc:x->rc)
#define islc(x) (x->pa->lc==x)
#define isrc(x) (x->pa->rc==x)

typedef struct node
{
    int val;
    int h;
    node *pa;
    node *lc;
    node *rc;
    node(int v, node *p = NULL): val(v), h(0), pa(p), lc(NULL), rc(NULL) {}
} node;

int n;
node *tree = NULL;

bool updateHeight(node *n)
{
    int newHeight = max(n->lc==NULL?-1:n->lc->h, n->rc==NULL?-1:n->rc->h) + 1;
    if (n->h == newHeight)
        return false;
    n->h = newHeight;
    return true;
}

int balance(node *n)
{
    int lch = (n->lc == NULL? -1: n->lc->h);
    int rch = (n->rc == NULL? -1: n->rc->h);
    return lch - rch;
}

node * connect34(node *p, node *q, node *r, node *a, node *b, node *c, node *d)
{
    q->lc = p;
    q->rc = r;
    q->pa = NULL;
    p->lc = a;
    p->rc = b;
    p->pa = q;
    r->lc = c;
    r->rc = d;
    r->pa = q;
    if (a != NULL)
        a->pa = p;
    if (b != NULL)
        b->pa = p;
    if (c != NULL)
        c->pa = r;
    if (d != NULL)
        d->pa = r;
    updateHeight(p);
    updateHeight(r);
    updateHeight(q);
    return q;
}

void rotateAt(node *v)
{
    node *p = v->pa;
    node *g = p->pa;
    node *gg = g->pa;
    bool LCHILD;
    if (gg != NULL)
        LCHILD = islc(g);
    if (islc(v))
    {
        if (islc(p))
        {
            g = connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
        }
        else
        {
            g = connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
        }
    }
    else
    {
        if (islc(p))
        {
            g = connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
        }
        else
        {
            g = connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
        }
    }
    if (gg != NULL)
    {
        if (LCHILD)
            gg->lc = g;
        else
            gg->rc = g;
        g->pa = gg;
    }
    else
    {
        tree = g;
    }
}

void tryInsert(node *r, node *n)
{
    if (r->val < n->val)
    {
        if (r->rc == NULL)
        {
            r->rc = n;
            n->pa = r;
        }
        else
        {
            tryInsert(r->rc, n);
        }
    }
    else
    {
        if (r->lc == NULL)
        {
            r->lc = n;
            n->pa = r;
        }
        else
        {
            tryInsert(r->lc, n);
        }
    }
}

void insert(int val)
{
    if (tree == NULL)
    {
        tree = new node(val, NULL);
        return;
    }
    node *n = new node(val);
    tryInsert(tree, n);
    node *v = n->pa;
    while (v != NULL)
    {
        updateHeight(v);
        if (balance(v) < -1 || 1 < balance(v))
        {
            rotateAt(tallerchild(tallerchild(v)));
        }
        v = v->pa;
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int val;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &val);
        insert(val);
    }
    printf("%d\n", tree->val);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

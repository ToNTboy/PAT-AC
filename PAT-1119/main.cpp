#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 31

typedef struct node
{
    int key;
    node *lc, *rc;
    node(int k):key(k), lc(NULL), rc(NULL) {}
} node;

int n, m, t;
int pre[MAXN], post[MAXN], ino[MAXN];
bool uq = true, flag = true;

node* build(int *pre, int lw1, int hi1, int *post, int lw2, int hi2)
{
    if (hi1 - lw1 < 1) return NULL;
    node *r = new node(pre[lw1]);
    if (hi1 - lw1 == 1) return r;
    if (pre[lw1+1] == post[hi2-2]) uq = false;
    int m = -1;
    REP(i, 0, hi2-lw2)
    {
        if (pre[lw1+1] == post[lw2+i])
        {
            m = lw2+i;
            break;
        }
    }
    r->lc = build(pre, lw1+1, m-lw2+lw1+2, post, lw2, m+1);
    r->rc = build(pre, m-lw2+lw1+2, hi1, post, m+1, hi2-1);
    return r;
}

void inorder(node *r)
{
    if (r==NULL) return;
    inorder(r->lc);
    printf(flag?"%d":" %d", r->key);
    flag = false;
    inorder(r->rc);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 0, n)
        scanf("%d", &pre[i]);
    REP(i, 0, n)
        scanf("%d", &post[i]);
    node *root = build(pre, 0, n, post, 0, n);
    printf(uq?"Yes\n":"No\n");
    inorder(root);
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

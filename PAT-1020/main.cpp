#include <cstdio>
#include <queue>

using namespace std;

#define LOCAL

#define MAXN 31

typedef struct tree
{
    int plw, phi, ilw, ihi;
    tree(int a, int b, int c, int d): plw(a), phi(b), ilw(c), ihi(d){}
} tree;

queue<tree> q;
int post[MAXN];
int inord[MAXN];
int n=0, c=0;

void build()
{
    tree t = q.front();
    q.pop();
    if ((t.phi - t.plw) < 1)
        return;

    c++;
    printf(c==n? "%d\n":"%d ", post[t.phi-1]);
    if ((t.phi - t.plw) == 1)
        return;
    int ltn=0, rtn=0, piv=0;
    while (inord[t.ilw+ltn] != post[t.phi-1])
    {
        ltn++;
    }
    piv = t.ilw + ltn;
    rtn = t.ihi - piv - 1;
    if (ltn>0)
    {
        tree lt(t.plw, t.plw+ltn, t.ilw, piv);
        q.push(lt);
    }
    if (rtn>0)
    {
        tree rt(t.plw+ltn, t.phi-1, piv+1, t.ihi);
        q.push(rt);
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &post[i]);
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &inord[i]);
    }

    tree root(1, 1+n, 1, 1+n);
    q.push(root);
    while (!q.empty())
    {
        build();
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

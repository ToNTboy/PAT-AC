#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10001

int n, k, q, t, b1, b2;
int mxb, mxt, pa[MAXN], pic[MAXN];
set<int> trees;

int findroot(int x)
{
    int a = x;
    while (pa[x] != x)
        x = pa[x];
    while (pa[a] != a)
    {
        int z = a;
        a = pa[a];
        pa[z] = x;
    }
    return x;
}

void unionset(int a, int b)
{
    int ra = findroot(a);
    int rb = findroot(b);
    if (ra != rb) pa[ra] = rb;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    memset(pic, -1, sizeof(pic));
    scanf("%d", &n);
    REP(i, 0, n)
        pa[i] = i;
    REP(i, 0, n)
    {
        scanf("%d", &k);
        REP(j, 0, k)
        {
            scanf("%d", &t);
            mxb = max(t, mxb);
            if (pic[t] == -1)
                pic[t] = i;
            unionset(i, findroot(pic[t]));
        }
    }
    REP(i, 0, n)
        trees.insert(findroot(i));
    mxt = trees.size();
    printf("%d %d\n", mxt, mxb);
    scanf("%d", &q);
    REP(i, 0, q)
    {
        scanf("%d %d", &b1, &b2);
        if (findroot(pic[b1]) == findroot(pic[b2]))
            printf("Yes\n");
        else
            printf("No\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

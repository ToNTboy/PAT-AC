#include <cstdio>
#include <cstring>

using namespace std;

#define LOCAL
#define MAXN 1001

int n, total;
bool error = false;
int key[MAXN], lc[MAXN], rc[MAXN];

int trv1(int lw, int hi)
{
    if (hi - lw == 1)
    {
        lc[lw] = rc[lw] = -1;
        return lw;
    }
    if (hi - lw < 1)
        return -1;

    int lb = lw+1, le, rb, re;
    int i=lb;
    while (i < hi)
    {
        if (key[i] >= key[lw])
            break;
        i++;
    }
    le = i;
    rb = i;
    while (i < hi)
    {
        if (key[i] < key[lw])
            break;
        i++;
    }
    re = i;

    lc[lw] = trv1(lb, le);
    rc[lw] = trv1(rb, re);
    return lw;
}

int trv2(int lw, int hi)
{
    if (hi - lw == 1)
    {
        lc[lw] = rc[lw] = -1;
        return lw;
    }
    if (hi - lw < 1)
        return -1;

    int lb = lw+1, le, rb, re;
    int i=lb;
    while (i < hi)
    {
        if (key[i] < key[lw])
            break;
        i++;
    }
    le = i;
    rb = i;
    while (i < hi)
    {
        if (key[i] >= key[lw])
            break;
        i++;
    }
    re = i;

    lc[lw] = trv2(lb, le);
    rc[lw] = trv2(rb, re);
    return lw;
}

int getnum(int r)
{
    if (r == -1)
        return 0;
    return getnum(lc[r]) + getnum(rc[r]) + 1;
}

void postorder(int r)
{
    if (r==-1)
        return;
    postorder(lc[r]);
    postorder(rc[r]);
    printf(total==0?"%d":" %d", key[r]);
    total++;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &key[i]);
    }
    trv1(0, n);
    if (getnum(0) != n)
    {
        trv2(0, n);
        if (getnum(0) != n)
            error = true;
    }
    if (error)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        postorder(0);
        printf("\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

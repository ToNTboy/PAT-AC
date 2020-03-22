#include <cstdio>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 100001

int c, p;
int nc[MAXN], ncn[MAXN], np[MAXN], npn[MAXN];

bool cmp(const int& a, const int& b)
{
    return a>b;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int t, ci=0, cj=0;
    scanf("%d", &c);
    for (;ci+cj<c;)
    {
        scanf("%d", &t);
        if (t>0)
            nc[ci++]=t;
        else
            ncn[cj++]=t;
    }
    int pi=0, pj=0;
    scanf("%d", &p);
    for (;pi+pj<p;)
    {
        scanf("%d", &t);
        if (t>0)
            np[pi++]=t;
        else
            npn[pj++]=t;
    }
    sort(nc, nc+ci, cmp);
    sort(ncn, ncn+cj);
    sort(np, np+pi, cmp);
    sort(npn, npn+pj);

    int i=0, j=0, sum=0;
    while (i<ci && i<pi)
    {
        sum+=(nc[i]*np[i]);
        i++;
    }
    while (j<cj && j<pj)
    {
        sum+=(ncn[j]*npn[j]);
        j++;
    }
    printf("%d\n", sum);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

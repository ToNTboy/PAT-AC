#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 1001
#define UNSURE 0
#define MAXH 1
#define MINH 2
#define NOTH 3

int n, m, type;
int h[MAXN];
char res[3][11] = {"Max Heap\n", "Min Heap\n", "Not Heap\n"};

void check(int r)
{
    int lc = r<<1, rc = lc+1, pa = r>>1;
    if (rc <= n)
        check(rc);
    if (lc <= n)
        check(lc);
    if (pa > 0)
    {
        if (type == UNSURE && h[r] < h[pa])
            type = MAXH;
        else if (type == UNSURE && h[r] > h[pa])
            type = MINH;
        else if (type == MINH && h[r] < h[pa])
            type = NOTH;
        else if (type == MAXH && h[r] > h[pa])
            type = NOTH;
    }
}

void prtpost(int r)
{
    int lc = r<<1, rc = lc+1;
    if (lc <= n)
        prtpost(lc);
    if (rc <= n)
        prtpost(rc);
    printf(r==1?"%d\n":"%d ", h[r]);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &m, &n);
    REP(i, 0, m)
    {
        type = UNSURE;
        REP(j, 1, n+1)
            scanf("%d", &h[j]);
        check(1);
        printf(res[type-1]);
        prtpost(1);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

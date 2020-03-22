#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 1001
#define UNSURE 0
#define MAXH 1
#define MINH 2
#define NOTH 3

int h[MAXN], n, type;
char res[3][11] = {"Max Heap\n", "Min Heap\n", "Not Heap\n"};
vector<int> p;

void prt(vector<int>& a)
{
    for (int i=0; i<a.size(); i++)
        printf(i==0?"%d":" %d", a[i]);
    printf("\n");
}

void check(int r)
{
    p.push_back(h[r]);
    int lc = r<<1, rc = lc+1, pa = r>>1;
    if (lc > n)
        prt(p);
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
    p.pop_back();
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &h[i]);
    check(1);
    printf(res[type-1]);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 500

typedef struct station
{
    double price;
    double dist;
} station;

bool cmp(const station& a, const station& b)
{
    if (a.dist == b.dist)
        return a.price < b.price;
    return a.dist < b.dist;
}

int n;
double cmax, d, davg, mxd, mic, next[MAXN];
station s[MAXN];

int nextstat(int p)
{
    int t = -1, i = 1;
    for (int i=1; p+i<n && s[p+i].dist-s[p].dist<=cmax*davg; i++)
    {
        if (s[p+i].dist == s[p].dist)
            continue;
        if (d - s[p].dist <= cmax*davg && s[p].price < s[p+i].price)
            continue;
        if (s[p+i].price < s[p].price)
            return p+i;
        if (t == -1)
            t = p+i;
        else
            t = (s[p+i].price < s[t].price? p+i : t);
    }
    return t;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
    for (int i=0; i<n; i++)
    {
        scanf("%lf %lf", &s[i].price, &s[i].dist);
        if (s[i].dist == d)
        {
            i--;
            n--;
        }
    }
    sort(s, s+n, cmp);
    if (s[0].dist != 0)
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    int cur = 0, ns;
    double cap = 0, add, cost;
    while ((ns = nextstat(cur))!=-1)
    {
        add = 0;
        cost = (s[ns].dist - s[cur].dist) / davg;
        if (s[cur].price < s[ns].price)
            add = cmax - cap;
        else if (cost > cap)
            add = cost - cap;
        cap = cap + add - cost;
        mic += s[cur].price * add;
        mxd = s[ns].dist;
        cur = ns;
    }

    if (d - s[cur].dist <= cmax * davg)
    {
        add = 0;
        cost = (d - s[cur].dist) / davg;
        if (cost > cap)
            add = cost - cap;
        mic += s[cur].price * add;
        mxd = d;
        printf("%.2lf\n", mic);
    }
    else
    {
        printf("The maximum travel distance = %.2lf\n", s[cur].dist + cmax * davg);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

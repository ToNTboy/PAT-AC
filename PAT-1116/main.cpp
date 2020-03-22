#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000

int n, k, t, r;
map<int, int> m;
set<int> chk;

bool prime(int rk)
{
    if (rk<2) return false;
    int i = 2;
    while (i*i<=rk)
    {
        if (rk%i==0)
            return false;
        i++;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &t);
        m[t] = i;
    }
    scanf("%d", &k);
    for (int i=1; i<=k; i++)
    {
        scanf("%d", &t);
        r = m[t];
        if (r<1)
            printf("%04d: Are you kidding?\n", t);
        else if (chk.count(r))
            printf("%04d: Checked\n", t);
        else if (r==1)
            printf("%04d: Mystery Award\n", t);
        else if (prime(r))
            printf("%04d: Minion\n", t);
        else
            printf("%04d: Chocolate\n", t);
        chk.insert(r);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

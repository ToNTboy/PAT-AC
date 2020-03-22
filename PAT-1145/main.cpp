#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000

int n, m, msize, t;
double st;

bool isprime(int d)
{
    if (d<2) return false;
    int i=2;
    while (i*i<=d)
    {
        if (d%i==0)
            return false;
        i++;
    }
    return true;
}

int nextprime(int d)
{
    while (!isprime(d))
        d++;
    return d;
}

int search(vector<int>& table, int key, bool cal)
{
    int off = 0, d = 1, c = 0, tsize = table.size();
    REP(i, 0, tsize+1)
    {
        if (cal) st++;
        c = (key + off) % tsize;
        if (table[c] == key || table[c] == -1)
            return c;
        off += d;
        d += 2;
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d %d", &msize, &n, &m);
    msize = nextprime(msize);
    vector<int> table(msize, -1);
    int pos;
    REP(i, 0, n)
    {
        scanf("%d", &t);
        if ((pos = search(table, t, false)) == -1)
            printf("%d cannot be inserted.\n", t);
        else
            table[pos] = t;
    }
    REP(i, 0, m)
    {
        scanf("%d", &t);
        search(table, t, true);
    }
    printf("%.1lf\n", st / m);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

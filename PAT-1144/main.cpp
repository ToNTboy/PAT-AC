#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 100001

int n, m, t;
set<int> l;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &t);
        l.insert(t);
    }
    int i = 0, j = 1;
    set<int>::iterator it = l.begin();
    while (*it < 1)
        it++;
    while (it != l.end() && *it == j)
    {
        it++; j++;
    }
    printf("%d\n", j);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

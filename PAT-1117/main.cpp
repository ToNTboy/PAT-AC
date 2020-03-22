#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 100001

int n, d[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 0, n)
        scanf("%d", &d[i]);
    sort(d, d+n);
    int x = n;
    while (x > -1 && d[n-x] <= x)
        x--;
    printf("%d\n", x>-1?x:0);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

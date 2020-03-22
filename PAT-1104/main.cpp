#include <bits/stdc++.h>

using namespace std;

#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 100001

int n;
double sum = 0, dig[MAXN];

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
        scanf("%lf", &dig[i]);
    REP(i, 0, n)
    {
        long long k = (long long)(i + 1) * (long long)(n - i);
        sum += (k * dig[i]);
    }
    printf("%.2lf\n", sum);
    return 0;
}

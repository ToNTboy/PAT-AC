#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

#define LOCAL
#define lli long long int

lli N, n;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    map<lli, int> p;
    scanf("%lld", &n);
    N = n;
    lli up = sqrt((double)n);
    for (lli i=2; i<=up; i++)
    {
        while (n%i == 0)
        {
            p[i] = p[i]+1;
            n /= i;
            up = sqrt((double)n);
        }
    }
    if (n>1)
        p[n] = p[n]+1;
    if (N==1)
        p[1] = 1;
    printf("%lld=", N);
    for (map<lli, int>::iterator it = p.begin(); it != p.end(); it++)
    {
        if (it!=p.begin())
            printf("*");
        printf("%lld", it->first);
        if (it->second > 1)
            printf("^%d", it->second);
    }
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

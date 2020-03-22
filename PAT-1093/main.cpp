#include <cstdio>
#include <cstring>

using namespace std;

#define LOCAL
#define MAXN 100002
#define lli long long int

int len;
lli dp[MAXN];
char s[MAXN];

lli trySearch()
{
    lli spat=0, sat=0, st=0;
    for (int i=len-1; i>=0; i--)
    {
        if (s[i] == 'T')
            ++st;
        if (s[i] == 'A')
        {
            sat += st;
            dp[i] = sat;
        }
        if (s[i] == 'P')
        {
            spat += sat;
            dp[i] = spat;
        }
    }
    return spat % 1000000007;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%s", s);
    len = strlen(s);
    printf("%lld\n", trySearch());

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

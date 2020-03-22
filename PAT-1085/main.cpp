#include <cstdio>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 100001
#define lli long long int

int n, mxlen;
lli p, s[MAXN];

int binsearch(int lw, int hi, lli val)
{
    if (hi- lw < 1) return -1;
    if (hi - lw == 1) return (s[lw] <= val? lw : lw-1);
    int mi = (hi + lw) / 2;
    if (s[mi] > val)
        return binsearch(lw, mi, val);
    else
        return binsearch(mi, hi, val);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %lld", &n, &p);
    for (int i=0; i<n; i++)
    {
        scanf("%lld", &s[i]);
    }
    sort(s, s+n);

    lli m, M;
    for (int i=0; i<n; i++)
    {
        m = s[i];
        int j = binsearch(i, n, m*p);
        if (j-i+1 > mxlen)
            mxlen = j-i+1;
    }
    printf("%d", mxlen);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

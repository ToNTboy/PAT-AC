#include <cstdio>

using namespace std;

#define LOCAL

#define lli long long int

lli t[]={0LL, 1LL, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL, 10000000LL, 100000000LL, 1000000000LL, 10000000000LL, 100000000000LL};
lli n;

lli allone(int d)
{
    if (d==0) return 0;
    if (d==1) return 1;
    return allone(d-1)*10+t[d];
}

int getdig(lli n)
{
    if (n<10) return 1;
    int i=1;
    while ((n/t[i])!=0)
    {
        i++;
    }
    return (i-1);
}

lli query(lli n, int d)
{
    //printf("query n=%lld d=%d\n", n, d);
    if (n<10) return n==0?0:1;
    lli top=n/t[d];
    if (top>1)
    {
        return allone(d-1)*top + t[d] + query(n%t[d], getdig(n%t[d]));
    }
    else
    {
        return allone(d-1) + n - t[d] + 1 + query(n%t[d], getdig(n%t[d]));
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%lld", &n);
    printf("%lld\n", query(n, getdig(n)));

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

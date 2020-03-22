#include <cstdio>
#include <cstring>
#include <math.h>

using namespace std;

#define LOCAL

char t[21];

bool isprime(int p)
{
    if (p == 2)
        return true;
    if (p < 2)
        return false;
    int up = (int)sqrt(p);
    for (int i=2; i<=up; i++)
    {
        if (p%i==0)
            return false;
    }
    return true;
}

int rdx10(char n[], int lw, int hi, int r)
{
    int sum=0;
    int i=lw;
    while (i<hi)
    {
        sum = sum * r + n[i];
        i++;
    }
    return sum;
}

int rev(int p, int r)
{
    int b=0, i=0;
    while (p)
    {
        t[i] = p % r;
        p = p / r;
        i++;
    }
    while (t[b]==0)
    {
        b++;
    }
    return rdx10(t, b, i, r);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int n, d;
    scanf("%d", &n);
    while (n > -1)
    {
        scanf("%d", &d);
        if (n > 1 && isprime(n) && isprime((rev(n, d))))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        scanf("%d", &n);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

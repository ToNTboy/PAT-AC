#include <cstdio>
#include <cstring>

using namespace std;

#define LOCAL

#define lli long long int

char n1[11], n2[11];
int k, r, l1, l2;
lli ten1;

void init(char n[], int l)
{
    int i=0;
    while (i<l)
    {
        n[i] = n[i]<'a'? n[i]-'0': n[i]-'a'+10;
        i++;
    }
}

int minrdx(char n[], int l)
{
    int i=0, mr=1;
    while (i<l)
    {
        if (n[i] > mr)
        {
            mr = n[i];
        }
        i++;
    }
    return mr+1;
}

lli rdx10(char n[], int l, lli r)
{
    lli sum=0;
    int i=0;
    while (i<l)
    {
        sum = sum * r + n[i];
        i++;
    }
    return sum;
}

bool binsearch(lli lw, lli hi, lli &radix)
{
    lli mi = (lw + hi) / 2;
    if (mi==lw || mi==hi)
    {
        return false;
    }
    lli ten2 = rdx10(n2, l2, mi);
    if (ten2 == ten1)
    {
        radix = mi;
        return true;
    }
    if (ten2 < ten1)
    {
        return binsearch(mi, hi, radix);
    }
    if (ten2 > ten1)
    {
        return binsearch(lw, mi, radix);
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%s %s %d %d", n1, n2, &k, &r);
    if (k==2)
    {
        char t[11];
        strcpy(t, n1);
        strcpy(n1, n2);
        strcpy(n2, t);
    }
    l1 = strlen(n1);
    l2 = strlen(n2);
    init(n1, l1);
    init(n2, l2);

    lli r2 = minrdx(n2, l2);

    ten1 = rdx10(n1, l1, r);
    lli ten2 = rdx10(n2, l2, r2);
    lli lowr = r2, upr;
    while (ten2 >= r2 && ten2 < ten1)
    {
        lowr = r2;
        r2 += r2;
        if (lowr > r2)
        {
            printf("overflow\n");
            return 0;
        }
        ten2 = rdx10(n2, l2, r2);
    }
    upr = r2;
    if (ten1 == ten2)
    {
        printf("%lld\n", r2);
    }
    else
    {
        if (binsearch(lowr, upr, r2))
        {
            printf("%lld\n", r2);
        }
        else
        {
            printf("Impossible\n");
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

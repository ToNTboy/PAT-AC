#include <cstdio>
#include <cstring>

using namespace std;

#define LOCAL
#define MAXN 120

int up;
char dig[MAXN], tmp[MAXN];

void strrev(char *s, int n)
{
    int lw=0, hi=n-1;
    char t;
    while (lw < hi)
    {
        t = s[lw];
        s[lw++] = s[hi];
        s[hi--] = t;
    }
}

bool ispair(char *d, int n)
{
    int lw = 0, hi = n-1;
    while (lw < hi)
    {
        if (d[lw] != d[hi])
            return false;
        lw++;
        hi--;
    }
    return true;
}

void tryadd(char *a, char *b, int n)
{
    //printf("%s + %s = ", a, b);
    int add = 0, i, sum;
    for (i=0; i<n; i++)
    {
        sum = a[i] - '0' + b[i] - '0' + add;
        add = sum / 10;
        a[i] = sum % 10 + '0';
    }
    if (add)
    {
        a[i++] = add + '0';
    }
    a[i] = '\0';
    //printf("%s\n", a);
}

void add(char *d, char *t, int n)
{
    strcpy(t, d);
    strrev(t, n);
    tryadd(d, t, n);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%s %d", dig, &up);
    strrev(dig, strlen(dig));
    int i = 0;
    for (i; i<up; i++)
    {
        if (ispair(dig, strlen(dig)))
            break;
        add(dig, tmp, strlen(dig));
    }
    strrev(dig, strlen(dig));
    printf("%s\n", dig);
    printf("%d\n", i);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

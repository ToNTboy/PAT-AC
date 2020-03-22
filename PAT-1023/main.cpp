#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define LOCAL

char dc1[22], dc2[22];

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

void doubleit(char *src, char *dest)
{
    int len1 = strlen(src), len2;
    int i = len1 - 1, j = 0, add = 0;
    for (; i>=0; i--)
    {
        int t = (src[i] - '0') * 2 + add;
        add = t / 10;
        dest[j++] = t % 10 + '0';
    }
    if (add)
    {
        dest[j++] = '1';
        dest[j] = '\0';
    }
    else
    {
        dest[j] = '\0';
    }
    len2 = j;
    strrev(dest, len2);
}

bool isfun(char *d1, char *d2)
{
    char t1[22], t2[22];
    strcpy(t1, d1);
    strcpy(t2, d2);
    sort(t1, t1+strlen(t1));
    sort(t2, t2+strlen(t2));
    if (strcmp(t1, t2) == 0)
        return true;
    else
        return false;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    char t;
    scanf("%s", dc1);
    doubleit(dc1, dc2);
    if (isfun(dc1, dc2))
    {
        printf("Yes\n");
        printf("%s\n", dc2);
    }
    else
    {
        printf("No\n");
        printf("%s\n", dc2);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

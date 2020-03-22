#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 2003

char str[MAXN];
int p[MAXN], maxlen = 0, len;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    str[0] = '#';
    char t;
    int cur = 1, mx = 0, id;
    while (scanf("%c", &t) && t!='\n')
    {
        str[cur++] = t;
        str[cur++] = '#';
    }
    str[cur] = '\0';
    len = strlen(str);
    for (int i=0; i<len; i++)
    {
        if (mx > i)
            p[i] = min(p[2*id-i], mx-i);
        else
            p[i] = 1;
        while (i+p[i]<len && i-p[i]>-1 && str[i+p[i]] == str[i-p[i]])
        {
            p[i]++;
        }
        if (i+p[i]>mx)
        {
            mx = i+p[i];
            id = i;
        }
    }
    for (int i=0; i<len; i++)
    {
        if (p[i]-1 > maxlen)
            maxlen = p[i]-1;
    }
    printf("%d\n", maxlen);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

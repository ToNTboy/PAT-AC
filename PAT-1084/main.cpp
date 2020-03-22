#include <cstdio>

using namespace std;

#define LOCAL
#define MAXN 256
#define upper(x) (('a' <= x && x <= 'z')? x + 'A' - 'a': x)

char s1[MAXN], s2[MAXN];
int e1[MAXN], e2[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    char tmp;
    int i=0, j=0;
    while (1)
    {
        scanf("%c", &s1[i]);
        s1[i] = upper(s1[i]);
        if (s1[i] == '\n')
        {
            s1[i] = '\0';
            break;
        }
        if (e1[s1[i]])
            continue;
        e1[s1[i]] = 1;
        i++;
    }
    i=0;
    while (1)
    {
        scanf("%c", &s2[i]);
        s2[i] = upper(s2[i]);
        if (s2[i] == '\n')
        {
            s2[i] = '\0';
            break;
        }
        if (e2[s2[i]])
            continue;
        e2[s2[i]] = 1;
        i++;
    }
    i=0;
    while (s1[i]!='\0')
    {
        if (!e2[s1[i]])
        {
            printf("%c", upper(s1[i]));
        }
        i++;
    }
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 110000

int limit, cnt, s1, s2, e1, e2;
bool isequal = true;
char n1[MAXN], n2[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int d1=-1, d2=-1, p1=-1, p2=-1, l1, l2, t;
    scanf("%d %s %s", &limit, n1, n2);
    l1 = strlen(n1);
    l2 = strlen(n2);

    t=0;
    while (n1[t] != '\0')
    {
        if (n1[t] == '.')
            p1 = t;
        else if (n1[t] != '0' && d1==-1)
            d1 = t;
        t++;
    }
    if (p1==-1)
        p1 = l1;
    t=0;
    while (n2[t] != '\0')
    {
        if (n2[t] == '.')
            p2 = t;
        else if (n2[t] != '0' && d2==-1)
            d2 = t;
        t++;
    }
    if (p2==-1)
        p2 = l2;
    if (p1>d1)
        e1 = p1-d1;
    else
        e1 = p1-d1+1;
    if (p2>d2)
        e2 = p2-d2;
    else
        e2 = p2-d2+1;

    cnt = 0;
    //printf("%d %d %d %d %d %d\n", d1, p1, d2, p2, e1, e2);
    for (int i1=0, i2=0; cnt<limit;)
    {
        if (n1[d1+i1] == '.')
            i1++;
        if (n2[d2+i2] == '.')
            i2++;
        char a=(d1+i1<l1?n1[d1+i1]:'0'), b=(d2+i2<l2?n2[d2+i2]:'0');
        if (a != b)
        {
            isequal = false;
            break;
        }
        cnt++;
        i1++;
        i2++;
    }

    if ((isequal && e1 == e2) || (d1 == -1 && d2 == -1))
    {
        printf("YES 0.");
        if (d1==-1)
        {
            for (int i=0; i<limit; i++)
                printf("0");
            printf("*10^0\n");
        }
        else
        {
            cnt = 0;
            for (int i=d1; cnt<limit; i++)
            {
                char c = i<l1? n1[i]: '0';
                if (c == '.')
                    continue;
                printf("%c", c);
                cnt++;
            }
            printf("*10^%d\n", e1);
        }
    }
    else
    {
        printf("NO");
        if (d1==-1)
        {
            printf(" 0.");
            for (int i=0; i<limit; i++)
                printf("0");
            printf("*10^0");
        }
        else
        {
            cnt = 0;
            printf(" 0.");
            for (int i=d1; cnt<limit; i++)
            {
                char c = i<l1? n1[i]: '0';
                if (c == '.')
                    continue;
                printf("%c", c);
                cnt++;
            }
            printf("*10^%d", e1);
        }
        if (d2==-1)
        {
            printf(" 0.");
            for (int i=0; i<limit; i++)
                printf("0");
            printf("*10^0\n");
        }
        else
        {
            cnt = 0;
            printf(" 0.");
            for (int i=d2; cnt<limit; i++)
            {
                char c = i<l2? n2[i]: '0';
                if (c == '.')
                    continue;
                printf("%c", c);
                cnt++;
            }
            printf("*10^%d\n", e2);
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10001

int len;
char d[MAXN], rd[MAXN];

void prtRevNum(char *a, int s)
{
    int i = s - 1;
    while (i >= 0)
        printf("%c", a[i--]);
}

void rev(char *a, char *b, int s)
{
    int i = 0, j = s - 1;
    while (i <= j)
    {
        char t = a[i];
        b[i] = a[j];
        b[j] = t;
        i++;
        j--;
    }
    b[s] = '\0';
}

int add(char *a, char *b, int s)
{
    int inc = 0, sum = 0;
    REP(i, 0, s)
    {
        sum = a[i] - '0' + b[i] - '0' + inc;
        inc = sum / 10;
        a[i] = sum % 10 + '0';
    }
    if (inc)
    {
        a[s++] = inc + '0';
        a[s] = '\0';
    }
    return s;
}

bool judge(char *a, int s)
{
    int i = 0, j = s - 1;
    while (i < j)
    {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool step(int& s)
{
    rev(d, rd, s);
    prtRevNum(d, s);
    printf(" + ");
    prtRevNum(rd, s);
    printf(" = ");
    s = add(d, rd, s);
    prtRevNum(d, s);
    printf("\n");
    return judge(d, s);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    bool res = false;
    scanf("%s", d);
    len = strlen(d);
    rev(d, d, len);
    if (judge(d, len))
    {
        res = true;
    }
    else
    {
        REP(i, 0, 10)
        {
            if (step(len))
            {
                res = true;
                break;
            }
        }
    }
    if (res)
    {
        prtRevNum(d, len);
        printf(" is a palindromic number.\n");
    }
    else
        printf("Not found in 10 iterations.\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

#define LOCAL
#define UNIT 5

int n;
char num[10];
map<int, int> m;
char mcl[13][UNIT] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char mch[13][UNIT] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int getkey(char *mdig)
{
    return (mdig[0]-'a')*26*26 + (mdig[1]-'a')*26 + (mdig[2]-'a');
}

void init()
{
    for (int i=0; i<13; i++)
    {
        m[getkey(mcl[i])] = i;
    }
    for (int i=0; i<13; i++)
    {
        m[getkey(mch[i])] = i*13;
    }
}

void m2e(char *num)
{
    char t[UNIT];
    sscanf(num, "%s", t);
    int a = m[getkey(t)];
    if (num[strlen(t)] == ' ')
    {
        sscanf(num, "%*s %s", t);
        a += m[getkey(t)];
    }
    printf("%d\n", a);
}

void e2m(char *num)
{
    int ed;
    sscanf(num, "%d", &ed);
    int add, rem;
    if ((add = ed / 13) > 0)
    {
        rem = ed % 13;
        if (rem == 0)
            printf("%s\n", mch[add]);
        else
            printf("%s %s\n", mch[add], mcl[rem]);
    }
    else
    {
        printf("%s\n", mcl[ed]);
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    init();
    scanf("%d\n", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%[^\n]\n", num);
        if (num[0] < 'a')
            e2m(num);
        else
            m2e(num);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

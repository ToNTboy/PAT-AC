#include <bits/stdc++.h>

using namespace std;

#define LOCAL

const char digit[10][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
const char unit[4][6] = {"", " Shi", " Bai", " Qian"};
const char highunit[3][6] = {"", " Wan", " Yi"};
char tmp[11];
char *num;
bool fu = false;

void prt(char *b, char *e, int hu, bool first)  // [b, e) && (0 < e-b <= 4)
{
    // hu: high level unit == 2, 1, 0 --> Yi, Wan, NoUnit
    int i = 0;
    bool allzero = true;
    if (first)
    {
        allzero = false;
        printf("%s%s", digit[b[0]-'0'], unit[e-b-1]);
        i++;
    }
    for (i; i<e-b; i++)
    {
        if (b[i] != '0')
        {
            allzero = false;
            printf(" %s%s", digit[b[i]-'0'], unit[e-b-i-1]);
        }
        else
        {
            if (i+1<e-b && b[i+1] != '0')
                printf(" %s", digit[0]);
        }
    }
    if (hu != 0 && !allzero)
        printf("%s", highunit[hu]);
    if (hu == 1 && allzero)
    {
        int t;
        sscanf(e, "%d", &t);
        if (t != 0 && t > 999)
        {
            printf(" %s", digit[0]);
        }
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%s", tmp);
    num = tmp;
    if (tmp[0] == '-')
    {
        fu = true;
        num = &tmp[1];
    }
    int t;
    sscanf(num, "%d", &t);
    if (t != 0 && fu)
    {
        printf("Fu ");
    }
    sprintf(num, "%d", t);

    int len = strlen(num);
    bool first = true;
    for (int i=0; i<len;)
    {
        if (((len - i) % 4) == 0)
        {
            prt(num + i, num + i + 4, (len - i - 1) / 4, first);
            i += 4;
        }
        else
        {
            prt(num + i, num + i + ((len - i) % 4), (len - i - 1) / 4, first);
            i += ((len - i) % 4);
        }
        first = false;
    }
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

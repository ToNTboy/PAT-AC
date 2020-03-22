#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 61

char s1[MAXN], s2[MAXN], s3[MAXN], s4[MAXN];
char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int day, hh, mm;
    bool d=false, h=false;
    scanf("%s%s%s%s", s1, s2, s3, s4);
    for (int i=0; i<min(strlen(s1), strlen(s2)); i++)
    {
        if (s1[i] == s2[i])
        {
            if (!d)
            {
                if ('A' <= s1[i] && s1[i] <= 'G')
                {
                    day = s1[i] - 'A';
                    d = true;
                }
            }
            else if (!h)
            {
                if ('A' <= s1[i] && s1[i] <= 'N')
                {
                    hh = s1[i] - 'A' + 10;
                    h = true;
                }
                else if ('0' <= s1[i] && s1[i] <= '9')
                {
                    hh = s1[i] - '0';
                    h = true;
                }
            }
        }
    }
    int i=0;
    for (i=0; i<min(strlen(s3), strlen(s4)); i++)
    {
        if (s3[i] == s4[i] && ('a' <= s3[i] && s3[i] <= 'z') || ('A' <= s3[i] && s3[i] <= 'Z'))
            break;
    }
    mm = i;
    printf("%s %02d:%02d\n", week[day], hh, mm);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000

int n, m, s;
char tname[21];
set<string> winners;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d %d", &m, &n, &s);
    REP(i, 1, m+1)
    {
        scanf("%s", tname);
        if ((i-s)>-1 && (i-s)%n==0)
        {
            string t(tname);
            if (winners.count(t) == 0)
            {
                winners.insert(t);
                printf("%s\n", tname);
            }
            else
            {
                s++;
            }
        }
    }
    if (winners.size()==0)
        printf("Keep going...\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

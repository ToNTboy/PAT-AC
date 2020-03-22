#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 100000

int n, m, t, tg;
int g[1000];
char ava[MAXN];
map<int, vector<int> > uncpt;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int g1, g2;
    scanf("%d %d", &n, &m);
    REP(i, 0, n)
    {
        scanf("%d %d", &g1, &g2);
        uncpt[g1].push_back(g2);
        uncpt[g2].push_back(g1);
    }
    REP(i, 0, m)
    {
        bool yes = true;
        memset(ava, 0, sizeof(ava));
        scanf("%d", &t);
        REP(j, 0, t)
        {
            scanf("%d", &tg);
            if (!yes || ava[tg] == 1)
            {
                yes = false;
                continue;
            }
            ava[tg] = 1;
            if (uncpt[tg].size()>0)
            {
                REP(k, 0, uncpt[tg].size())
                    ava[uncpt[tg][k]] = 1;
            }
        }
        printf(yes?"Yes\n":"No\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

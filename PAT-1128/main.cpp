#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 1002

int n, m, k, q;
int seq[MAXN];
char row[MAXN], lb[2*MAXN], lt[2*MAXN];

void reset()
{
    memset(row, 0, sizeof(row));
    memset(lb, 0, sizeof(lb));
    memset(lt, 0, sizeof(lt));
}

bool check()
{
    REP(i, 1, n+1)
    {
        int x = i, y = seq[i];
        if (row[seq[i]] != 0)
            return false;
        else
            row[seq[i]] = 1;

        if (lb[y-x+n] != 0)
            return false;
        else
            lb[y-x+n] = 1;

        if (lt[x+y] != 0)
            return false;
        else
            lt[x+y] = 1;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &k);
    REP(i, 0, k)
    {
        scanf("%d", &n);
        reset();
        REP(j, 1, n+1)
            scanf("%d", &seq[j]);
        printf(check()?"YES\n":"NO\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

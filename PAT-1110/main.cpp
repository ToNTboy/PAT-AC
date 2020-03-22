#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 20

int n, r, last;
int lc[MAXN], rc[MAXN], pa[MAXN];

bool lv_order(int r, int s)
{
    int nums = 0, t;
    deque<int> q;
    q.push_back(r);
    while (!q.empty() && nums < s)
    {
        t = q.front();
        q.pop_front();
        nums++;
        if (t == -1)
            return false;
        q.push_back(lc[t]);
        q.push_back(rc[t]);
    }
    last = t;
    return true;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    memset(pa, -1, sizeof(pa));
    memset(lc, -1, sizeof(lc));
    memset(rc, -1, sizeof(rc));
    char t1[3], t2[3];
    int tlc, trc;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%s %s", &t1, &t2);
        if (t1[0]=='-')
            tlc = -1;
        else
            sscanf(t1, "%d", &tlc);
        if (t2[0]=='-')
            trc = -1;
        else
            sscanf(t2, "%d", &trc);
        lc[i] = tlc;
        rc[i] = trc;
        pa[tlc] = i;
        pa[trc] = i;
    }
    REP(i, 0, n)
    {
        if (pa[i] == -1)
        {
            r = i;
            break;
        }
    }
    if (lv_order(r, n))
        printf("YES %d\n", last);
    else
        printf("NO %d\n", r);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

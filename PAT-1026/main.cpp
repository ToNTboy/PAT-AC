#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 101
#define OPEN 3600*8
#define CLOSE 3600*21
#define round2mins(s) (s/60+(s%60>29?1:0))  // s >= 0
#define EMPTY 0

typedef struct player
{
    int ct; // come time
    int st; // serve time
    int pt; // play time
    int ft; // finish time
    int wt; // wait time
    int lv;
    int tb;
} player;

int n, k, m, t, et, evt, ntime, mtime, nct, tb[MAXN], tbsv[MAXN], vip[MAXN];   // [1, k]
deque<player> ordq, vipq;
vector<player> res;

int occupy(int t, bool v)
{
    REP(i, 1, k+1)
    {
        if (tb[i] == EMPTY)
        {
            if (v)
            {
                if (!vip[i])
                    continue;
            }
            tb[i] = t;
            et--;
            if (vip[i])
                evt--;
            tbsv[i]++;
            return i;
        }
    }
}
bool cmp(const player& a, const player& b)
{
    return a.ct < b.ct;
}
bool cmp1(const player& a, const player& b)
{
    return a.st < b.st;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    memset(tb, EMPTY, sizeof(tb));
    int hh, mm, ss, tpt, tlv;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &tpt, &tlv);
        if (tpt > 120)
            tpt = 120;
        int ctime = hh*3600+mm*60+ss;
        player p = {ctime, -1, tpt*60, -1, -1, tlv, -1};
        if (tlv)
            vipq.push_back(p);
        else
            ordq.push_back(p);
    }
    sort(ordq.begin(), ordq.end(), cmp);
    sort(vipq.begin(), vipq.end(), cmp);

    scanf("%d %d", &k, &m);
    et = k;
    evt = m;
    REP(i, 0, m)
    {
        scanf("%d", &t);
        vip[t] = 1;
    }
    ntime = OPEN;
    while (ntime < CLOSE)
    {
        if (ordq.empty() && vipq.empty())
            break;
        mtime = INT_MAX;
        nct = min(ordq.empty()?INT_MAX:ordq.front().ct, vipq.empty()?INT_MAX:vipq.front().ct);
        REP(i, 1, k+1)
        {
            if (tb[i] == EMPTY)
                continue;
            if (tb[i] == ntime)
            {
                tb[i] = EMPTY;
                et++;
                if (vip[i])
                    evt++;
            }
            else if (tb[i] < mtime)
                mtime = tb[i];
        }
        while (evt > 0 && !vipq.empty() && vipq.front().ct <= ntime)
        {
            res.push_back(vipq.front());
            vipq.pop_front();
            res.back().st = ntime;
            res.back().wt = ntime - res.back().ct;
            res.back().ft = ntime + res.back().pt;
            t = occupy(res.back().ft, true);
            res.back().tb = t;
            mtime = min(mtime, res.back().ft);
            nct = min(ordq.empty()?INT_MAX:ordq.front().ct, vipq.empty()?INT_MAX:vipq.front().ct);
        }
        while (et > 0 && nct != INT_MAX && nct <= ntime)
        {
            int oct = ordq.empty()?INT_MAX:ordq.front().ct;
            int vct = vipq.empty()?INT_MAX:vipq.front().ct;
            if (oct < vct)
            {
                res.push_back(ordq.front());
                ordq.pop_front();
            }
            else
            {
                res.push_back(vipq.front());
                vipq.pop_front();
            }
            res.back().st = ntime;
            res.back().wt = res.back().st - res.back().ct;
            res.back().ft = res.back().st + res.back().pt;
            t = occupy(res.back().ft, false);
            res.back().tb = t;
            mtime = min(mtime, res.back().ft);
            nct = min(ordq.empty()?INT_MAX:ordq.front().ct, vipq.empty()?INT_MAX:vipq.front().ct);
        }
        if (et)
            ntime = min(mtime, nct);
        else
            ntime = mtime;
    }
    sort(res.begin(), res.end(), cmp1);
    REP(i, 0, res.size())
    {
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", res[i].ct/3600, res[i].ct%3600/60, res[i].ct%60,
                res[i].st/3600, res[i].st%3600/60, res[i].st%60, round2mins(res[i].wt));
    }
    REP(i, 1, k+1)
        printf(i==1?"%d":" %d", tbsv[i]);
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000

typedef struct site
{
    int num, score;
} site;

int n, m, s, t;
vector<pair<string, int> > T, A, B;
char tmp[15];
int qdata;
site sites[MAXN];
map<int, set<int> > dmap;
map<int, int> dandt;

bool cmp1(const pair<string, int>& a, const pair<string, int>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

bool cmp3(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void prtquery1(vector<pair<string, int> >& res)
{
    if (res.empty())
    {
        printf("NA\n");
        return;
    }
    REP(i, 0, res.size())
        printf("%s %d\n", res[i].first.c_str(), res[i].second);
}

void query1(char *param)
{
    if (param[0] == 'T')
        prtquery1(T);
    else if (param[0] == 'A')
        prtquery1(A);
    else if (param[0] == 'B')
        prtquery1(B);
}

void query2(char *param)
{
    int snum;
    sscanf(param, "%d", &snum);
    if (sites[snum].num == 0)
        printf("NA\n");
    else
        printf("%d %d\n", sites[snum].num, sites[snum].score);
}

void query3(char *param)
{
    int tdate;
    sscanf(param, "%d", &tdate);
    qdata = tdate;
    set<int>& ss = dmap[tdate];
    if (ss.empty())
    {
        printf("NA\n");
        return;
    }
    vector<pair<int, int> > res;
    for (set<int>::iterator it = ss.begin(); it != ss.end(); it++)
        res.push_back(make_pair(*it, dandt[tdate*100+(*it)]));
    sort(res.begin(), res.end(), cmp3);
    REP(i, 0, res.size())
        printf("%d %d\n", res[i].first, res[i].second);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int level, snum, tdate, tnum;
    scanf("%d %d", &n, &m);
    REP(i, 0, n)
    {
        scanf("%s %d", tmp, &s);
        string card(tmp);
        char tmpc[7];
        strncpy(tmpc, tmp+1, 3);
        tmpc[3] = '\0';
        sscanf(tmpc, "%d", &snum);
        strncpy(tmpc, tmp+4, 6);
        tmpc[6] = '\0';
        sscanf(tmpc, "%d", &tdate);
        strncpy(tmpc, tmp+10, 3);
        tmpc[3] = '\0';
        sscanf(tmpc, "%d", &tnum);
        if (tmp[0] == 'T')
            T.push_back(make_pair(card, s));
        else if (tmp[0] == 'A')
            A.push_back(make_pair(card, s));
        else if (tmp[0] == 'B')
            B.push_back(make_pair(card, s));
        sites[snum].num++;
        sites[snum].score += s;
        dmap[tdate].insert(snum);
        dandt[tdate*100+snum]++;
    }
    sort(T.begin(), T.end(), cmp1);
    sort(A.begin(), A.end(), cmp1);
    sort(B.begin(), B.end(), cmp1);
    REP(i, 0, m)
    {
        scanf("%d %s", &t, tmp);
        printf("Case %d: %d %s\n", i+1, t, tmp);
        switch (t)
        {
        case 1: query1(tmp);
            break;
        case 2: query2(tmp);
            break;
        case 3: query3(tmp);
            break;
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

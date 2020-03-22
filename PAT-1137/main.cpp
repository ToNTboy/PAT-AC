#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000

typedef struct student
{
    string name;
    int ps, ms, fs, g;
    student(): ps(-1), ms(-1), fs(-1) {}
} stu;

bool cmp(const stu& a, const stu& b)
{
    if (a.g == b.g)
        return a.name < b.name;
    return a.g > b.g;
}

int p, m, n;
int ts;
char tid[21];
map<string, stu> sheet;
vector<stu> res;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d %d", &p, &m, &n);
    REP(i, 0, p)
    {
        scanf("%s %d", tid, &ts);
        string id(tid);
        sheet[id].name = id;
        sheet[id].ps = ts;
    }
    REP(i, 0, m)
    {
        scanf("%s %d", tid, &ts);
        string id(tid);
        sheet[id].name = id;
        sheet[id].ms = ts;
    }
    REP(i, 0, n)
    {
        scanf("%s %d", tid, &ts);
        string id(tid);
        sheet[id].name = id;
        sheet[id].fs = ts;
    }
    map<string, stu>::iterator it = sheet.begin();
    for (it; it!=sheet.end(); it++)
    {
        stu& s = it->second;
        if (s.ps < 200 || s.fs == -1)
            continue;
        s.g = s.ms > s.fs? round(s.ms * 0.4 + s.fs * 0.6) : s.fs;
        if (s.g < 60)
            continue;
        res.push_back(s);
    }
    sort(res.begin(), res.end(), cmp);
    REP(i, 0, res.size())
    {
        stu& s = res[i];
        printf("%s %d %d %d %d\n", s.name.c_str(), s.ps, s.ms, s.fs, s.g);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

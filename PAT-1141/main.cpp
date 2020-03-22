#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10000

typedef struct school
{
    string sname;
    float tws;
    int ns;
} school;

bool cmp(const school& a, const school& b)
{
    int atws = a.tws, btws = b.tws;
    if (atws == btws)
    {
        if (a.ns == b.ns)
            return a.sname < b.sname;
        return a.ns < b.ns;
    }
    return atws > btws;
}

int n, m, s;
char tid[7], sch[7];
map<string, school> msch;
vector<school> res;

void tolower(char *t)
{
    int i=0;
    while (t[i] != '\0')
    {
        if ('A' <= t[i] && t[i] <= 'Z')
            t[i] = 'a' - 'A' + t[i];
        i++;
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%s %d %s", tid, &s, sch);
        tolower(sch);
        string t(sch);
        float ws = 0;
        if (tid[0] == 'A') ws = s;
        if (tid[0] == 'B') ws = s / 1.5;
        if (tid[0] == 'T') ws = s * 1.5;
        school& ts = msch[t];
        ts.sname = t;
        ts.tws += ws;
        ts.ns += 1;
    }
    map<string, school>::iterator it = msch.begin();
    for (it; it != msch.end(); it++)
        res.push_back(it->second);
    sort(res.begin(), res.end(), cmp);
    printf("%d\n", res.size());
    int pres = -1, prer = 0, cr = 0;
    REP(i, 0, res.size())
    {
        if (pres == (int)res[i].tws)
            cr = prer;
        else
        {
            cr = i + 1;
            prer = cr;
            pres = (int)res[i].tws;
        }
        printf("%d %s %d %d\n", cr, res[i].sname.c_str(), (int)res[i].tws, res[i].ns);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

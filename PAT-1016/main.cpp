#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define LOCAL

typedef struct record
{
    char name[21];
    int mon, day, hh, mm;
    bool on;
} rec;

typedef struct call
{
    int sday, eday, shh, ehh, smm, emm, last, pay;
} call;

typedef struct bill
{
    char name[21];
    int mon, sum;
    vector<call> calls;
} bill;

bool cmp(const rec& a, const rec& b)
{
    int t = strcmp(a.name, b.name);
    if (t < 0)
    {
        return true;
    }
    if (0 < t)
    {
        return false;
    }
    if (a.day < b.day)
    {
        return true;
    }
    if (a.day > b.day)
    {
        return false;
    }
    if (a.hh < b.hh)
    {
        return true;
    }
    if (a.hh > b.hh)
    {
        return false;
    }
    return a.mm < b.mm;
}

int n, cost[24];
rec recs[1000];
vector<bill> bills;

void calc(const rec& s, const rec& e, call& c)
{
    int sum = 0, last = 0;
    int sh = s.hh;
    int eh = (e.day-s.day)*24 + e.hh;
    while (sh != eh)
    {
        sum += (cost[sh%24]*60);
        last += 60;
        sh++;
    }
    sum -= (s.mm*cost[s.hh]);
    sum += (e.mm*cost[e.hh]);
    last -= s.mm;
    last += e.mm;
    c.sday = s.day;
    c.shh = s.hh;
    c.smm = s.mm;
    c.eday = e.day;
    c.ehh = e.hh;
    c.emm = e.mm;
    c.pay = sum;
    c.last = last;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    char state[] = "on-line";
    char tmp[9];
    for (int i=0; i<24; i++)
        scanf("%d", &cost[i]);
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%s %d:%d:%d:%d %s", recs[i].name, &recs[i].mon, &recs[i].day, &recs[i].hh, &recs[i].mm, tmp);
        if (strcmp(state, tmp) == 0)
            recs[i].on = true;
        else
            recs[i].on = false;
    }
    sort(recs, recs+n, cmp);

    int i=0;
    bill first;
    first.sum = 0;
    first.mon = recs[0].mon;
    strcpy(first.name, recs[0].name);
    bills.push_back(first);
    while (i < n-1)
    {
        int samecus = strcmp(recs[i].name, recs[i+1].name);
        if (samecus != 0)
        {
            bill newcus;
            newcus.sum = 0;
            newcus.mon = recs[i+1].mon;
            strcpy(newcus.name, recs[i+1].name);
            bills.push_back(newcus);
            i++;
            continue;
        }
        if (recs[i].on && !recs[i+1].on)
        {
            call c;
            calc(recs[i], recs[i+1], c);
            bills.back().calls.push_back(c);
            bills.back().sum += c.pay;
            i++;
        }
        else
        {
            i++;
        }
    }

    for (int i=0; i<bills.size(); i++)
    {
        if (bills[i].sum==0)
            continue;
        printf("%s %02d\n", bills[i].name, bills[i].mon);
        for (int j=0; j<bills[i].calls.size(); j++)
        {
            call c = bills[i].calls[j];
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%d.%02d\n", c.sday, c.shh, c.smm, c.eday, c.ehh, c.emm, c.last, c.pay/100, c.pay%100);
        }
        printf("Total amount: $%d.%02d\n", bills[i].sum/100, bills[i].sum%100);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

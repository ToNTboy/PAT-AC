#include <bits/stdc++.h>
using namespace std;

#define LOCAL

typedef struct rec
{
    string name;
    int time;
    int type;
    int num;
} rec;

bool cmp1(const rec& a, const rec& b)
{
    if (a.name == b.name)
        return a.time < b.time;
    return a.name < b.name;
}

bool cmp2(const rec& a, const rec& b)
{
    return a.time < b.time;
}

int n, k;
char tmp[8], status[4];
rec rs[10001];
vector<rec> valid;
map<string, int> park;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int hh, mm, ss, time;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++)
    {
        scanf("%s %d:%d:%d %s", tmp, &hh, &mm, &ss, status);
        rs[i].name = tmp;
        rs[i].time = hh*3600+mm*60+ss;
        rs[i].type = strcmp(status, "in") == 0? 0:1;
    }
    sort(rs, rs+n, cmp1);

    for (int i=0; i<n-1; i++)
    {
        if (rs[i].name == rs[i+1].name)
        {
            if (rs[i].type == 0 && rs[i+1].type == 1)
            {
                valid.push_back(rs[i]);
                valid.push_back(rs[i+1]);
                park[rs[i].name] += (rs[i+1].time-rs[i].time);
            }
        }
    }
    sort(valid.begin(), valid.end(), cmp2);

    int cpark = 0;
    for (int i=0; i<valid.size(); i++)
    {
        if (valid[i].type == 0)
            cpark++;
        else
            cpark--;
        valid[i].num = cpark;
    }

    int pos = -1;
    for (int i=0; i<k; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        time = hh*3600+mm*60+ss;
        if (pos < (int)valid.size() - 1)
            pos++;
        for (; pos<valid.size(); pos++)
        {
            if (valid[pos].time > time)
            {
                pos--;
                break;
            }
        }
        if (pos>=valid.size())
            pos = valid.size()-1;
        printf("%d\n", pos==-1?0:valid[pos].num);
    }

    int mpark = -1;
    vector<string> mpname;
    for (map<string, int>::iterator it = park.begin(); it!=park.end(); it++)
    {
        if (it->second > mpark)
        {
            mpark = it->second;
            mpname.clear();
            mpname.push_back(it->first);
        }
        else if (it->second == mpark)
        {
            mpname.push_back(it->first);
        }
    }
    for (int i=0; i<mpname.size(); i++)
    {
        printf("%s ", mpname[i].c_str());
    }
    printf("%02d:%02d:%02d\n", mpark/3600, mpark%3600/60, mpark%60);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

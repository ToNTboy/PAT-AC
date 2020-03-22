#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 10001
#define FATHER 1
#define MOTHER 2
#define CHILD 3

typedef struct person
{
    float estate, area;
    set<int> rel;
} person;

typedef struct family
{
    int sid, mount;
    float t_estate, t_area, a_estate, a_area;
} family;

bool cmp(const family& a, const family& b)
{
    if (a.a_area == b.a_area)
        return a.sid < b.sid;
    return a.a_area > b.a_area;
}

int n, vis[MAXN];
set<int> ids;
vector<family> families;
person ps[MAXN];

void dfs(int rid, family& fam)
{
    vis[rid] = 1;
    ids.erase(rid);
    fam.mount++;
    fam.t_estate += ps[rid].estate;
    fam.t_area += ps[rid].area;
    if (rid < fam.sid)
        fam.sid = rid;
    for (set<int>::iterator it=ps[rid].rel.begin(); it!=ps[rid].rel.end(); it++)
    {
        if (!vis[*it])
            dfs(*it, fam);
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int tid, cid, tfa, tmo, tk;
    float te, ta;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d %d", &tid, &tfa, &tmo, &tk);
        ids.insert(tid);
        if (tfa!=-1) ids.insert(tfa);
        if (tmo!=-1) ids.insert(tmo);
        if (tfa!=-1) {ps[tid].rel.insert(tfa);ps[tfa].rel.insert(tid);}
        if (tmo!=-1) {ps[tid].rel.insert(tmo);ps[tmo].rel.insert(tid);}
        for (int j=0; j<tk; j++)
        {
            scanf("%d", &cid);
            ps[tid].rel.insert(cid);
            ps[cid].rel.insert(tid);
            ids.insert(cid);
        }
        scanf("%f %f", &te, &ta);
        ps[tid].estate = te;
        ps[tid].area = ta;
    }
    while (!ids.empty())
    {
        family tfam = {0};
        tfam.sid = INT_MAX;
        dfs(*ids.begin(), tfam);
        tfam.a_estate = tfam.t_estate == 0? 0 : tfam.t_estate / tfam.mount;
        tfam.a_area = tfam.t_area == 0? 0 : tfam.t_area / tfam.mount;
        families.push_back(tfam);
    }
    sort(families.begin(), families.end(), cmp);
    printf("%d\n", families.size());
    for (int i=0; i<families.size(); i++)
    {
        printf("%04d %d %.3f %.3f\n", families[i].sid, families[i].mount, families[i].a_estate, families[i].a_area);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

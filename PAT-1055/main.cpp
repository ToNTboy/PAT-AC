#include <bits/stdc++.h>

using namespace std;

#define LOCAL

typedef struct person
{
    char name[11];
    int age, worth;
} person;

typedef struct pos
{
    int x, y;
} pos;

int n, k, m, minr, maxr;
vector<person> ps[201];

bool cmp1(const person& a, const person& b)
{
    if (a.worth == b.worth)
        return strcmp(a.name, b.name) < 0;
    return a.worth > b.worth;
}

struct cmp2
{
    bool operator() (const pos& a, const pos& b)
    {
        if (ps[a.x][a.y].worth == ps[b.x][b.y].worth)
        {
            if (ps[a.x][a.y].age == ps[b.x][b.y].age)
            {
                return strcmp(ps[a.x][a.y].name, ps[b.x][b.y].name) > 0;
            }
            return ps[a.x][a.y].age > ps[b.x][b.y].age;
        }
        return ps[a.x][a.y].worth < ps[b.x][b.y].worth;
    }
};

void query(int m, int minr, int maxr, int idx)
{
    printf("Case #%d:\n", idx);
    priority_queue<pos, vector<pos>, cmp2> q;
    while (minr <= maxr)
    {
        for (int i=0; i<ps[minr].size() && i<100; i++)
        {
            pos tp = {minr, i};
            q.push(tp);
        }
        minr++;
    }
    if (q.empty())
    {
        printf("None\n");
        return;
    }
    for (int i=0; i<m && !q.empty(); i++)
    {
        pos tp = q.top();
        q.pop();
        printf("%s %d %d\n", ps[tp.x][tp.y].name, ps[tp.x][tp.y].age, ps[tp.x][tp.y].worth);
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %d", &n, &k);
    for (int i=1; i<=n; i++)
    {
        person p;
        scanf("%s %d %d", p.name, &p.age, &p.worth);
        ps[p.age].push_back(p);
    }
    for (int i=1; i<=200; i++)
    {
        sort(ps[i].begin(), ps[i].end(), cmp1);
    }
    for (int i=1; i<=k; i++)
    {
        scanf("%d %d %d", &m, &minr, &maxr);
        query(m, minr, maxr, i);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

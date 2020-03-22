#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 50000

typedef struct cmp
{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
} cmp;

int n, k, t;
map<int, int> m;
set<int> rec;
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &n, &k);
    scanf("%d", &t);
    m[t]++;
    q.push(make_pair(t, m[t]));
    REP(i, 1, n)
    {
        scanf("%d", &t);
        printf("%d:", t);
        rec.clear();
        REP(j, 0, k)
        {
            while (!q.empty() && rec.count(q.top().first) > 0)
                q.pop();
            if (q.empty())
                break;
            rec.insert(q.top().first);
            printf(" %d", q.top().first);
            q.pop();
        }
        set<int>::iterator it = rec.begin();
        REP(j, 0, rec.size())
        {
            q.push(make_pair(*it, m[*it]));
            it++;
        }
        printf("\n");
        m[t]++;
        q.push(make_pair(t, m[t]));
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

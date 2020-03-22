#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 51

int n, k;
set<int> s[MAXN];

set<int> getIntersection(const set<int>& a, const set<int>& b)
{
    set<int> c;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
    return c;
}

void calc(int s1, int s2)
{
    set<int> in = getIntersection(s[s1], s[s2]);
    int c = in.size(), t = s[s1].size() + s[s2].size() - c;
    printf("%.1lf%%\n", (double)c/(double)t*100);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int m, t, s1, s2;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &m);
        for (int j=0; j<m; j++)
        {
            scanf("%d", &t);
            s[i].insert(t);
        }
    }
    scanf("%d", &k);
    for (int i=0; i<k; i++)
    {
        scanf("%d %d", &s1, &s2);
        calc(s1, s2);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

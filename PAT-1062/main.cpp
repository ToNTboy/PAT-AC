#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 100001

typedef struct people
{
    int id;
    int t;
    int v;
} people;

int n, l, h;
people ps[MAXN];
vector<people> sage;
vector<people> noble;
vector<people> fool;
vector<people> other;

bool cmp(const people& a, const people& b)
{

    if (a.t+a.v == b.t+b.v)
    {
        if (a.v == b.v)
        {
            return a.id < b.id;
        }
        return a.v > b.v;
    }
    return a.t+a.v > b.t+b.v;
}

void prt(vector<people>& ps)
{
    for (int i=0; i<ps.size(); i++)
    {
        printf("%08d %d %d\n", ps[i].id, ps[i].v, ps[i].t);
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %d %d", &n, &l, &h);
    int all=0;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d", &ps[all].id, &ps[all].v, &ps[all].t);
        if (ps[all].v < l || ps[all].t < l)
            continue;
        all++;
    }
    for (int i=0; i<all; i++)
    {
        if (ps[i].t >= h && ps[i].v >= h)
            sage.push_back(ps[i]);
        else if (ps[i].t < h && ps[i].v >= h)
            noble.push_back(ps[i]);
        else if (ps[i].t < h && ps[i].v < h && ps[i].v >= ps[i].t)
            fool.push_back(ps[i]);
        else
            other.push_back(ps[i]);
    }
    sort(sage.begin(), sage.end(), cmp);
    sort(noble.begin(), noble.end(), cmp);
    sort(fool.begin(), fool.end(), cmp);
    sort(other.begin(), other.end(), cmp);
    printf("%d\n", all);
    prt(sage);
    prt(noble);
    prt(fool);
    prt(other);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

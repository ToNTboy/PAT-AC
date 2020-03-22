#include <cstdio>
#include <vector>

using namespace std;

#define LOCAL
#define MAXN 100001

typedef struct interval
{
    int lw, hi;
} interval;

int n, m;
int chain[MAXN];
vector<interval> res;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &chain[i]);
    }
    int lw=0, hi=1, minv=0x7FFFFFFF, sum=chain[0];    // [lw, hi)
    while (lw < n && hi <= n)
    {
        if (sum < m)
        {
            if (hi == n)
                break;
            sum += chain[hi];
            hi++;
        }
        else
        {
            if (sum < minv)
            {
                minv = sum;
                interval t = {lw, hi};
                res.clear();
                res.push_back(t);
            }
            else if (sum == minv)
            {
                interval t = {lw, hi};
                res.push_back(t);
            }
            sum -= chain[lw];
            lw++;
        }
    }
    for (int i=0; i<res.size(); i++)
    {
        printf("%d-%d\n", res[i].lw+1, res[i].hi);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

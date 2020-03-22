#include <cstdio>
#include <algorithm>

using namespace std;

#define LOCAL

typedef struct record
{
    char name[11];
    char id[11];
    int grade;
} rec;

int n;
rec *recs;

int binsearch(int lo, int hi, int val)
{
    if (hi - lo < 2) return lo;
    int mi = (hi + lo) >> 1;
    if (recs[mi].grade <= val)
        return binsearch(mi, hi, val);
    else
        return binsearch(lo, mi, val);
}

bool cmp(const rec& a, const rec& b)
{
    return a.grade < b.grade;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int id, lo, hi;
    scanf("%d", &n);
    recs = new rec[n];
    for (int i=0; i<n; i++)
    {
        scanf("%s %s %d", recs[i].name, recs[i].id, &recs[i].grade);
    }
    scanf("%d %d", &lo, &hi);
    sort(recs, recs+n, cmp);
    int down = binsearch(0, n, lo);
    int up = binsearch(0, n, hi);
    if (recs[down].grade < lo)
        down++;
    if (recs[up].grade > hi)
        up--;
    if (up - down >= 0)
    {
        for (int i=up; i>=down; i--)
        {
            printf("%s %s\n", recs[i].name, recs[i].id);
        }
    }
    else
    {
        printf("NONE\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

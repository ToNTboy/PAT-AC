#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

#define LOCAL
#define MAXN 10000
#define open 8*60*60
#define close 17*60*60

typedef struct custom
{
    int begin;
    int end;
    int cost;
    int wait;
} custom;

bool cmp(custom& a, custom& b)
{
    return a.begin < b.begin;
}

custom cus[MAXN];
int n, k;
int proc=0;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int hh, mm, ss, cost;
    double sum=0;
    int num=0;

    memset(cus, 0, sizeof(cus));
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++)
    {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &cost);
        cus[i].begin = hh*3600 + mm*60 + ss;
        cus[i].cost = cost*60;
        if (cus[i].begin>close)
        {
            num++;
        }
    }
    sort(cus, cus+n, cmp);
    n = n - num;

    vector<int> w(k);
    while (proc < k && proc < n && cus[proc].begin < open)
    {
        cus[proc].wait += (open - cus[proc].begin);
        cus[proc].begin = open;
        proc++;
    }

    proc = 0;
    for (int i=0; i<k && i<n; i++)
    {
        cus[i].end = cus[i].begin + cus[i].cost;
        w[i] = cus[i].end;
        proc++;
    }
    while (proc < n)
    {
        int mtime = INT_MAX;
        int min = -1;
        for (int i=0; i<k; i++)
        {
            if (w[i] < mtime)
            {
                mtime = w[i];
                min = i;
            }
        }
        if (cus[proc].begin < mtime)
        {
            cus[proc].wait += (mtime - cus[proc].begin);
            cus[proc].end = mtime + cus[proc].cost;
        }
        else
        {
            cus[proc].end = cus[proc].begin + cus[proc].cost;
        }
        w[min] = cus[proc].end;
        proc++;
    }

    for (int i=0; i<n; i++)
    {
        sum += cus[i].wait;
    }
    printf("%.1lf\n", sum==0? 0 : sum/n/60);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

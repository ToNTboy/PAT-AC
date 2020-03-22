#include <cstdio>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 1000

typedef struct mooncake
{
    double amount;
    double price;
    double unit;
} cake;

bool cmp(const cake& a, const cake& b)
{
    return a.unit > b.unit;
}

int n;
double d;
cake ck[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %lf", &n, &d);
    for (int i=0; i<n; i++)
    {
        scanf("%lf", &ck[i].amount);
    }
    for (int i=0; i<n; i++)
    {
        scanf("%lf", &ck[i].price);
        ck[i].unit = ck[i].price / ck[i].amount;
    }
    sort(ck, ck+n, cmp);

    int c = 0;
    double profit = 0;
    while (d > 0 && c < n)
    {
        if (d >= ck[c].amount)
        {
            profit += ck[c].price;
            d -= ck[c].amount;
        }
        else
        {
            profit += (d * ck[c].unit);
            d = 0;
        }
        c++;
    }

    printf("%.2lf\n", profit);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

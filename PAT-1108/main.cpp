#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 1000

int n;
double t;
char a[MAXN], b[MAXN];
vector<double> rn;

bool legal(char *d, char *cmp)
{
    double td;
    sscanf(d, "%lf", &td);
    if (td > 1000 || td < -1000) return false;
    sprintf(cmp, "%.2lf", td);
    return strncmp(d, cmp, strlen(d)) == 0;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%s", a);
        if (!legal(a, b))
            printf("ERROR: %s is not a legal number\n", a);
        else
        {
            sscanf(a, "%lf", &t);
            rn.push_back(t);
        }
    }
    if (rn.size() == 0)
    {
        printf("The average of 0 numbers is Undefined\n");
        return 0;
    }
    else if (rn.size() == 1)
    {
        printf("The average of 1 number is %.2lf\n", rn[0]);
        return 0;
    }
    double sum = 0;
    REP(i, 0, rn.size())
        sum += rn[i];
    double res = sum / rn.size();
    printf("The average of %d numbers is %.2lf\n", rn.size(), res);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

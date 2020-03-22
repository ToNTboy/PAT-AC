#include <cstdio>

using namespace std;

#define LOCAL

int n, m, td;
int d[100001];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &d[i%n]);
        td += d[i%n];
        d[i%n] = td;
    }
    d[0] = 0;
    scanf("%d", &m);
    int a, b;
    for (int i = 0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        int t=(a<b?d[b]-d[a]:d[a]-d[b]);
        if (t<=(td/2))
            printf("%d\n", t);
        else
            printf("%d\n", td-t);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <cstdio>

using namespace std;

#define LOCAL

int g1, s1, k1, g2, s2, k2;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int add=0, rg, rs, rk;
    scanf("%d.%d.%d %d.%d.%d\n", &g1, &s1, &k1, &g2, &s2, &k2);
    rk=(k1+k2)%29;
    add=(k1+k2)/29;
    rs=(s1+s2+add)%17;
    add=(s1+s2+add)/17;
    rg=(g1+g2+add);
    printf("%d.%d.%d\n", rg, rs, rk);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

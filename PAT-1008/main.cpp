#include <cstdio>
#include <cmath>

using namespace std;

#define LOCAL

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int n, nfl = 0, sum = 0, cfl = 0, tmp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nfl);
        if (nfl == cfl)
        {
            sum += 5;
            continue;
        }
        tmp = nfl - cfl;
        sum += ((tmp < 0 ? abs(tmp) * 4 : abs(tmp) * 6) + 5);
        cfl = nfl;
    }
    printf("%d", sum);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

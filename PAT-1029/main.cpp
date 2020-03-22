#include <cstdio>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 200005

int na, nb;
int a[MAXN], b[MAXN];

int median(int *a, int na, int *b, int nb)
{
    int i=0, j=0, pi=0, p=0;
    int m=(na+nb-1)>>1;
    while (pi<=m)
    {
        if (na<=i)
        {
            p=b[m-pi+j];
            break;
        }
        if (nb<=j)
        {
            p=a[m-pi+i];
            break;
        }
        p=(a[i]<b[j]? a[i++]: b[j++]);
        pi++;
    }
    return p;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d", &na);
    for (int i=0; i<na; i++)
        scanf("%d", &a[i]);

    scanf("%d", &nb);
    for (int i=0; i<nb; i++)
        scanf("%d", &b[i]);

    sort(a, a+na);
    sort(b, b+nb);

    printf("%d\n", median(a, na, b, nb));

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

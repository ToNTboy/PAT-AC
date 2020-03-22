#include <cstdio>

using namespace std;

#define LOCAL

#define MAXN 10001

int n;
int num[MAXN];
int dup[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int tmp, win=0;
    scanf("%d", &n);
    for (int i=1, j=1; i<=n; i++)
    {
        scanf("%d", &tmp);
        if (dup[tmp] == 0)
            num[j++] = tmp;
        dup[tmp]++;
    }
    for (int i=1; i<=MAXN-1; i++)
    {
        if (dup[num[i]] == 1)
        {
            win = num[i];
            break;
        }
    }
    if (win)
    {
        printf("%d\n", win);
    }
    else
    {
        printf("None\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

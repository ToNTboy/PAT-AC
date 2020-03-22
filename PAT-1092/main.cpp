#include <cstdio>

using namespace std;

#define LOCAL

char shop[1001];
char seek[1001];
int shopnum[256];
int seeknum[256];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int i=0, extra=0, miss=0;
    scanf("%s\n", shop);
    scanf("%s\n", seek);

    i=0;
    while (shop[i]!='\0')
    {
        shopnum[shop[i]]++;
        i++;
    }
    i=0;
    while (seek[i]!='\0')
    {
        seeknum[seek[i]]++;
        i++;
    }

    for (int i=48; i<123; i++)
    {
        if (seeknum[i] > shopnum[i])
            miss+=(seeknum[i]-shopnum[i]);
        if (seeknum[i] < shopnum[i])
            extra+=(shopnum[i] - seeknum[i]);
    }

    if (miss)
        printf("No %d\n", miss);
    else
        printf("Yes %d\n", extra);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

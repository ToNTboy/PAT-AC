#include <cstdio>

using namespace std;

#define LOCAL
#define MAXN 54

char p[5] = {'S', 'H', 'C', 'D', 'J'};
int n, cards[MAXN+1], s[MAXN+1];

void shuffle()
{
    int tmp[55];
    for (int i=1; i<=MAXN; i++)
    {
        tmp[s[i]] = cards[i];
    }
    for (int i=1; i<=MAXN; i++)
    {
        cards[i] = tmp[i];
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int d1, d2;
    for (int i=1; i<=MAXN; i++)
    {
        cards[i] = i;
    }
    scanf("%d", &n);
    for (int i=1; i<=MAXN; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i=0; i<n; i++)
    {
        shuffle();
    }
    for (int i=1; i<=MAXN; i++)
    {
        d1 = (cards[i]-1)/13;
        d2 = (cards[i]-1)%13+1;
        printf(i==MAXN? "%c%d\n": "%c%d ", p[d1], d2);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

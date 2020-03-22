#include <cstdio>

using namespace std;

#define LOCAL

int n, r, p[32], k;

void radix(int num, int rad)
{
    if (!num)
    {
        p[0]=0;
        k=1;
        return;
    }
    k=0;
    while (num)
    {
        p[k++] = num % rad;
        num = num / rad;
    }
}

bool check()
{
    int up = k-1, low = 0;
    while(up >= low && p[up]==p[low])
    {
        low++;
        up--;
    }
    return up<low;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %d", &n, &r);
    radix(n, r);
    if (check())
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    for (int i=k-1; i>=0; i--)
        printf(i==0? "%d\n" : "%d ", p[i]);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

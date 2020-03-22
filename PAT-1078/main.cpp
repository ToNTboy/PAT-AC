#include <cstdio>
#include <cmath>

using namespace std;

#define LOCAL
#define MAXN 10007

int m, n;
int hashtable[MAXN];

bool isprime(int num)
{
    if (num < 2)
        return false;
    int up = sqrt(num);
    for (int i=2; i<=up; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int probe(int pos)
{
    int step = 1, times = 1;
    pos = (pos + step) % m;
    while(hashtable[pos] == 1)
    {
        if (times > m)
            return -1;
        step += 2;
        pos = (pos + step) % m;
        times++;
    }
    return pos;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int t;
    scanf("%d %d", &m, &n);
    while (!isprime(m))
        m++;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        t = t%m;
        if (hashtable[t] == 1 && (t = probe(t)) == -1)
        {
            printf(i==0? "-" : " -");
        }
        else
        {
            printf(i==0? "%d" : " %d", t);
            hashtable[t] = 1;
        }
    }
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

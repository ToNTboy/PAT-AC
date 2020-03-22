#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define LOCAL

int n, m, k, q, rem, all;
int now=0, cus=1, close=540;
int cost[1001];
int time[1001];
queue<int> line[21];
int last[21];

bool push(int l, int c)
{
    int tmp = last[l] + c;
    if (last[l] < close) time[cus] = tmp;
    last[l] = tmp;
    line[l].push(tmp);
    cus++;
    return true;
}

void pop(int l)
{
    line[l].pop();
    rem--;
}

void tick()
{
    now++;
    for (int i=1; i<=n; i++)
    {
        if (line[i].empty())
            continue;
        if (line[i].front() <= now)
        {
            pop(i);
            if (cus <= k)
                push(i, cost[cus]);
        }
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int tq;

    memset(time, 0, sizeof(time));
    memset(last, 0, sizeof(last));
    scanf("%d %d %d %d", &n, &m,&k,&q);
    rem = k;
    for (int i=1; i<=k; i++)
    {
        scanf("%d", &cost[i]);
    }
    all = n*m;

    while (cus <= k && cus <= all)
    {
        push((cus-1)%n+1, cost[cus]);
    }
    while (rem && now < close)
    {
        tick();
    }

    for (int i=1; i<=q; i++)
    {
        scanf("%d", &tq);
        if (time[tq]==0)
        {
            printf("Sorry\n");
        }
        else
        {
            printf("%02d:%02d\n", time[tq]/60+8, time[tq]%60);
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

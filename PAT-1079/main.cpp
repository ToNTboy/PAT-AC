#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

#define LOCAL
#define MAXN 100001

int n, m, t, num[MAXN], vis[MAXN];
double opri, rate, pri[MAXN];
vector<int> s[MAXN], retailers;

void level()
{
    deque<int> q;
    q.push_back(0);
    pri[0]=opri;
    vis[0]=1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop_front();
        for (int i=0; i<s[t].size(); i++)
        {
            if (vis[s[t][i]])
                continue;
            q.push_back(s[t][i]);
            vis[s[t][i]]=1;
            pri[s[t][i]]=pri[t]*rate;
        }
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %lf %lf", &n, &opri, &rate);
    rate=rate/100+1;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &m);
        if (m==0)
        {
            scanf("%d", &num[i]);
            retailers.push_back(i);
            continue;
        }
        for (int j=0; j<m; j++)
        {
            scanf("%d", &t);
            s[i].push_back(t);
        }
    }
    level();
    double sum=0;
    for (int i=0; i<retailers.size(); i++)
    {
        sum+=num[retailers[i]]*pri[retailers[i]];
    }
    printf("%.1lf\n", sum);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

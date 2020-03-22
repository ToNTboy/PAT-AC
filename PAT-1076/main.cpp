#include <cstdio>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

#define LOCAL
#define MAXN 1001

int n, l, k, vis[MAXN], lv[MAXN];
vector<int> users[MAXN];

void query(int u)
{
    memset(vis, 0, sizeof(vis));
    memset(lv, 0, sizeof(lv));
    int num = -1;
    deque<int> q;
    q.push_back(u);
    lv[u] = 0;
    vis[u] = 1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop_front();
        if (lv[f] > l)
            break;
        num++;
        for (int i=0; i<users[f].size(); i++)
        {
            if (vis[users[f][i]])
                continue;
            if (lv[users[f][i]] == 0)
                lv[users[f][i]] = lv[f] + 1;
            q.push_back(users[f][i]);
            vis[users[f][i]] = 1;
        }
    }
    printf("%d\n", num);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int f, u, q;
    scanf("%d %d", &n, &l);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &f);
        for (int j=0; j<f; j++)
        {
            scanf("%d", &u);
            users[u].push_back(i);
        }
    }
    scanf("%d", &k);
    for (int i=0; i<k; i++)
    {
        scanf("%d", &q);
        query(q);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define LOCAL

#define MAXN 1001
#define UNDIS 0
#define DISCO 1
#define VISED 2

vector<int> c[MAXN];
int vis[MAXN];
int n, m, k, lc;

void dfs(int pa)
{
    vis[pa] = DISCO;
    for (int i=0; i<c[pa].size(); i++)
    {
        if (vis[c[pa][i]] == UNDIS)
        {
            dfs(c[pa][i]);
        }
    }
    vis[pa] = VISED;
    return;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d %d", &n, &m, &k);
    int c1, c2, rep;
    for (int i=0; i<m; i++)
    {
        scanf("%d %d", &c1, &c2);
        c[c1].push_back(c2);
        c[c2].push_back(c1);
    }
    for (int i=0; i<k; i++)
    {
        memset(vis, UNDIS, sizeof(vis));
        rep = -1;
        scanf("%d", &lc);
        vis[lc] = DISCO;
        for (int j=0; j<c[lc].size(); j++)
        {
            if (vis[c[lc][j]] == UNDIS)
            {
                dfs(c[lc][j]);
                rep++;
            }
        }
        vis[lc] = VISED;
        for (int j=1; j<=n; j++)
        {
            if (vis[j] == UNDIS)
            {
                dfs(j);
                rep++;
            }
        }
        printf("%d\n", rep==-1? 0 : rep);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

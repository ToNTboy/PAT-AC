#include <cstdio>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 10001
#define UNDIS 0
#define DISCO 1
#define VISED 2

int n, k, vis[MAXN], dep[MAXN], pre[MAXN], depth = 0;
vector<int> nodes[MAXN], roots;
bool tree = true;

void bfs(int v)
{
    int d;
    dep[v] = 0;
    vis[v] = DISCO;
    depth = 0;
    roots.clear();
    roots.push_back(v);
    deque<int> q;
    q.push_back(v);
    while (!q.empty())
    {
        int c = q.front();
        q.pop_front();
        d = dep[c] + 1;
        for (int i=0; i<nodes[c].size(); i++)
        {
            if (vis[nodes[c][i]] == DISCO)
            {
                if (pre[c] != nodes[c][i])
                    tree = false;
                continue;
            }
            if (depth < d)
            {
                depth = d;
                roots.clear();
                roots.push_back(nodes[c][i]);
            }
            else if (depth == d)
            {
                roots.push_back(nodes[c][i]);
            }
            vis[nodes[c][i]] = DISCO;
            pre[nodes[c][i]] = c;
            dep[nodes[c][i]] = d;
            q.push_back(nodes[c][i]);
        }
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int fr, to;
    scanf("%d", &n);
    for (int i=1; i<n; i++)
    {
        scanf("%d %d", &fr, &to);
        nodes[fr].push_back(to);
        nodes[to].push_back(fr);
    }

    for (int i=1; i<=n; i++)
    {
        if (vis[i] == UNDIS)
        {
            bfs(i);
            k++;
        }
    }

    if (k != 1 || !tree)
    {
        printf("Error: %d components\n", k);
    }
    else
    {
        vector<int> r(roots);
        roots.clear();
        memset(vis, 0, sizeof(vis));
        memset(dep, 0, sizeof(dep));
        memset(pre, 0, sizeof(pre));
        bfs(r[0]);
        r.insert(r.end(), roots.begin(), roots.end());
        sort(r.begin(), r.end());
        vector<int>::iterator it = unique(r.begin(), r.end());
        r.resize(distance(r.begin(), it));
        for (int i=0; i<r.size(); i++)
        {
            printf("%d\n", r[i]);
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

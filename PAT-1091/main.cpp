#include <cstdio>
#include <deque>

using namespace std;

#define LOCAL
#define MAXM 1286
#define MAXN 128
#define MAXL 60

typedef struct point
{
    int x, y, z;
} point;

int m, n, l, t, v;
int brain[MAXM][MAXN][MAXL], vis[MAXM][MAXN][MAXL];

int bfs(int x, int y, int z)
{
    deque<point> q;
    int sum = 1;
    vis[x][y][z] = 1;
    point p= {x,y,z};
    q.push_back(p);
    while (!q.empty())
    {
        point p=q.front();
        q.pop_front();
        if (p.x-1>-1 && brain[p.x-1][p.y][p.z] && !vis[p.x-1][p.y][p.z])
        {
            point c= {p.x-1,p.y,p.z};
            q.push_back(c);
            vis[p.x-1][p.y][p.z] = 1;
            sum++;
        }
        if (p.x+1<m && brain[p.x+1][p.y][p.z] && !vis[p.x+1][p.y][p.z])
        {
            point c= {p.x+1,p.y,p.z};
            q.push_back(c);
            vis[p.x+1][p.y][p.z] = 1;
            sum++;
        }
        if (p.y-1>-1 && brain[p.x][p.y-1][p.z] && !vis[p.x][p.y-1][p.z])
        {
            point c= {p.x,p.y-1,p.z};
            q.push_back(c);
            vis[p.x][p.y-1][p.z] = 1;
            sum++;
        }
        if (p.y+1<n && brain[p.x][p.y+1][p.z] && !vis[p.x][p.y+1][p.z])
        {
            point c= {p.x,p.y+1,p.z};
            q.push_back(c);
            vis[p.x][p.y+1][p.z] = 1;
            sum++;
        }
        if (p.z-1>-1 && brain[p.x][p.y][p.z-1] && !vis[p.x][p.y][p.z-1])
        {
            point c= {p.x,p.y,p.z-1};
            q.push_back(c);
            vis[p.x][p.y][p.z-1] = 1;
            sum++;
        }
        if (p.z+1<l && brain[p.x][p.y][p.z+1] && !vis[p.x][p.y][p.z+1])
        {
            point c= {p.x,p.y,p.z+1};
            q.push_back(c);
            vis[p.x][p.y][p.z+1] = 1;
            sum++;
        }
    }
    return sum;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int i=0; i<l; i++)
    {
        for (int j=0; j<m; j++)
        {
            for (int k=0; k<n; k++)
            {
                scanf("%d", &brain[j][k][i]);
            }
        }
    }
    for (int i=0; i<l; i++)
    {
        for (int j=0; j<m; j++)
        {
            for (int k=0; k<n; k++)
            {
                if (brain[j][k][i]==1 && vis[j][k][i]==0)
                {
                    int sum = bfs(j, k, i);
                    if (sum < t)
                        continue;
                    v += sum;
                }
            }
        }
    }
    printf("%d\n", v);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

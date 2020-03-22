#include <cstdio>
#include <deque>

using namespace std;

#define LOCAL
#define MAXN 101

int n, m;
int e[MAXN][MAXN];
int p[MAXN], lv[MAXN], lvn[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int id, k, c;
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++)
    {
        scanf("%d %d", &id, &k);
        for (int j=0; j<k; j++)
        {
            scanf("%d", &c);
            e[id][c] = 1;
            p[c] = id;
        }
    }

    lv[1] = 1;
    deque<int> q;
    q.push_back(1);
    while (!q.empty())
    {
        int t = q.front();
        q.pop_front();
        lvn[lv[t]]++;
        for (int i=1; i<=n; i++)
        {
            if (e[t][i])
            {
                lv[i] = lv[t] + 1;
                q.push_back(i);
            }
        }
    }

    int mxn = 0, mxlv = 0;
    for (int i=1; i<=n && lvn[i]!=0; i++)
    {
        if (mxn < lvn[i])
        {
            mxn = lvn[i];
            mxlv = i;
        }
    }
    printf("%d %d\n", mxn, mxlv);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

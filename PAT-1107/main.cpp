#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 1001

int n, k, t;
int pa[MAXN], clu[MAXN];
map<int, int> res;

int findroot(int x)
{
    int a=x;
    while (x!=pa[x])
        x=pa[x];
    // compress path
    while (a!=pa[a])
    {
        int z=a;
        a=pa[a];
        pa[z]=x;
    }
    return x;
}

void unionset(int a, int b)
{
    int ra=findroot(a);
    int rb=findroot(b);
    if (ra!=rb) pa[ra]=rb;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 1, n+1)
        pa[i] = i;
    REP(i, 1, n+1)
    {
        scanf("%d: ", &k);
        REP(j, 0, k)
        {
            scanf("%d", &t);
            if (clu[t] == 0)
                clu[t] = i;
            unionset(i, findroot(clu[t]));
        }
    }
    REP(i, 1, n+1)
        res[findroot(i)]++;
    printf("%d\n", res.size());
    vector<int> output;
    for (map<int, int>::iterator it=res.begin(); it!=res.end(); it++)
        output.push_back(it->second);
    sort(output.begin(), output.end());
    for (int i=output.size()-1; i>=0; i--)
        printf(i==output.size()-1?"%d":" %d", output[i]);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 100000

int n, m, k, v, d, t;
int head, key[MAXN], nxt[MAXN];
vector<int> neg, z2k, k2mx;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d %d", &head, &n, &k);
    REP(i, 0, n)
    {
        scanf("%d %d %d", &v, &d, &t);
        key[v] = d;
        nxt[v] = t;
    }
    int c = head;
    while (c != -1)
    {
        if (key[c] < 0)
            neg.push_back(c);
        else if (key[c] > k)
            k2mx.push_back(c);
        else
            z2k.push_back(c);
        c = nxt[c];
    }
    vector<int> res;
    res.insert(res.end(), neg.begin(), neg.end());
    res.insert(res.end(), z2k.begin(), z2k.end());
    res.insert(res.end(), k2mx.begin(), k2mx.end());
    REP(i, 0, res.size())
    {
        if (i == res.size()-1)
            printf("%05d %d -1\n", res[i], key[res[i]]);
        else
            printf("%05d %d %05d\n", res[i], key[res[i]], res[i+1]);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

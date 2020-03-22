#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 100000

int n, m, t;
int cp[MAXN], state[MAXN];
vector<int> guests;
set<int> res;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    memset(cp, -1, sizeof(cp));
    int cp1, cp2;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d %d", &cp1, &cp2);
        cp[cp1] = cp2;
        cp[cp2] = cp1;
    }
    scanf("%d", &m);
    REP(i, 0, m)
    {
        scanf("%d", &t);
        state[t] = 1;
        guests.push_back(t);
    }
    REP(i, 0, m)
    {
        if (cp[guests[i]] == -1 || state[cp[guests[i]]] != 1)
            res.insert(guests[i]);
    }
    printf("%d\n", res.size());
    for (set<int>::iterator it=res.begin(); it!=res.end(); it++)
        printf(it==res.begin()?"%05d":" %05d", *it);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 1002

int n, k, t;
char s[MAXN];
set<int> can, cannot;
int idx[129], res[129];

bool cmp(const int& a, const int& b)
{
    return idx[a] < idx[b];
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %s", &k, s);
    char p = '\0';
    int r = 0, c = 0;
    while (1)
    {
        if (s[c] != p)
        {
            if (r > 0 && r % k == 0)
            {
                can.insert(p);
                if (idx[p] == 0 || idx[p] > c - r + 1)
                    idx[p] = c - r + 1;
            }
            else
                cannot.insert(p);
            p = s[c];
            r = 0;
        }
        if (s[c] == '\0') break;
        r++;
        c++;
    }
    vector<int> v(129);
    vector<int>::iterator it;
    it = set_difference(can.begin(), can.end(), cannot.begin(), cannot.end(), v.begin());
    v.resize(it - v.begin());
    sort(v.begin(), v.end(), cmp);
    REP(i, 0, v.size())
    {
        printf("%c", v[i]);
        res[v[i]] = 1;
    }
    printf("\n");
    c = 0;
    while (s[c] != '\0')
    {
        printf("%c", s[c]);
        if (res[s[c]])
            c += k;
        else
            c++;
    }
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

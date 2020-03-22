#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 10001

int n, t;
priority_queue<int, vector<int>, greater<int> > r;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        r.push(t);
    }
    while (!r.empty())
    {
        int r1 = r.top();
        r.pop();
        int r2 = r.top();
        r.pop();
        if (!r.empty())
            r.push((r1+r2)/2);
        else
            printf("%d\n", (r1+r2)/2);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

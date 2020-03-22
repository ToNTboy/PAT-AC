#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 100000

int n, m, t;
vector<int> c;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        c.push_back(t);
    }
    sort(c.begin(), c.end());

    int i, j;
    for (i=0, j=n-1; i<n && j-1>i;)
    {
        while (c[i] + c[j] > m && j - 1 > i)
        {
            j--;
        }
        if (c[i] + c[j] >= m)
            break;
        if (c[i] + c[j] < m)
            i++;
    }

    if (i < j && c[i] + c[j] == m)
        printf("%d %d\n", c[i], c[j]);
    else
        printf("No Solution\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

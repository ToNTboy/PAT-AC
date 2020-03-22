#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 100

int n, c=0;
int lc[MAXN], rc[MAXN], val[MAXN], seq[MAXN];

void inorder(int r)
{
    if (lc[r]!=-1)
        inorder(lc[r]);
    val[r] = seq[c];
    c++;
    if (rc[r]!=-1)
        inorder(rc[r]);
}

void lvorder(int r)
{
    int i=1;
    deque<int> q;
    q.push_back(r);
    while (!q.empty())
    {
        int t = q.front();
        q.pop_front();
        printf(i==n? "%d": "%d ", val[t]);
        if (lc[t]!=-1)
            q.push_back(lc[t]);
        if (rc[t]!=-1)
            q.push_back(rc[t]);
        i++;
    }
    printf("\n");
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &lc[i], &rc[i]);
    }
    for (int i=0; i<n; i++)
    {
        scanf("%d", &seq[i]);
    }
    sort(seq, seq+n);
    inorder(0);
    lvorder(0);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 10

int n, r, lc[MAXN], rc[MAXN], pa[MAXN];
stack<int> inseq;
deque<int> lvseq;

int root()
{
    int r = 0;
    while (pa[r] != -1)
        r = pa[r];
    return r;
}

void levelorder()
{
    int r = root();
    lvseq.push_back(r);
    while (!lvseq.empty())
    {
        int t = lvseq.front();
        lvseq.pop_front();
        printf(t==r?"%d":" %d", t);
        if (rc[t] != -1)
            lvseq.push_back(rc[t]);
        if (lc[t] != -1)
            lvseq.push_back(lc[t]);
    }
    printf("\n");
}

void inorder(int r)
{
    if (r == -1)
        return;
    inorder(lc[r]);
    inseq.push(r);
    inorder(rc[r]);
}

void inorder()
{
    int r = root();
    inorder(r);
    while (!inseq.empty())
    {
        printf(inseq.size() == 1? "%d\n" : "%d ", inseq.top());
        inseq.pop();
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    memset(lc, -1, sizeof(lc));
    memset(rc, -1, sizeof(rc));
    memset(pa, -1, sizeof(pa));
    char tlc, trc;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%c %c\n", &tlc, &trc);
        if (tlc != '-')
        {
            lc[i] = tlc-'0';
            pa[lc[i]] = i;
        }
        if (trc != '-')
        {
            rc[i] = trc-'0';
            pa[rc[i]] = i;
        }
    }
    levelorder();
    inorder();

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

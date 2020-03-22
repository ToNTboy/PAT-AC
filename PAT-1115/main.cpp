#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 1001

typedef struct node
{
    int key, lv;
    int lc, rc;
} node;

int n, mxlv, lvn[MAXN];
node bst[MAXN];

void bst_insert(int r, int k, int idx)
{
    int t = r, p = -1, lv = 0;
    while (t != -1)
    {
        lv++;
        p = t;
        t = (bst[t].key < k? bst[t].rc: bst[t].lc);
    }
    bst[idx].lv = lv;
    lvn[lv]++;
    if (mxlv < lv)
        mxlv = lv;
    if (bst[p].key < k)
        bst[p].rc = idx;
    else
        bst[p].lc = idx;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int t;
    scanf("%d", &n);
    scanf("%d", &bst[0].key);
    bst[0].lc = bst[0].rc = -1;
    lvn[0] = 1;
    for (int i=1; i<n; i++)
    {
        scanf("%d", &bst[i].key);
        bst[i].lc = bst[i].rc = -1;
        bst_insert(0, bst[i].key, i);
    }
    printf("%d + %d = %d\n", lvn[mxlv], lvn[mxlv-1], lvn[mxlv] + lvn[mxlv-1]);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

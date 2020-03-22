#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define MAXN 100001

typedef struct node
{
    int key;
    int next;
} node;

int head, n, k;
node l[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int id, key, nxt;
    scanf("%d %d %d", &head, &n, &k);
    l[MAXN-1].next = head;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d", &id, &key, &nxt);
        l[id].key = key;
        l[id].next = nxt;
    }

    int pres = MAXN-1, nxts = -1;
    int th, tc, tn, tnn;
    for (tc=l[pres].next; tc!=-1;)
    {
        th = tc;
        tn = l[tc].next;
        int j;
        for (j=1; j<k && tn!=-1; j++)
        {
            tnn = l[tn].next;
            l[tn].next = tc;
            tc = tn;
            tn = tnn;
        }
        if (j != k && j != 1)
        {
            // cancel reverse
            tn = l[tc].next;
            l[tc].next = -1;
            for (j; j>1 && tn!=-1; j--)
            {
                tnn = l[tn].next;
                l[tn].next = tc;
                tc = tn;
                tn = tnn;
            }
            break;
        }
        nxts = tn;
        l[pres].next = tc;
        l[th].next = nxts;
        pres = th;
        tc = l[pres].next;
    }

    tc = MAXN-1;
    while (l[tc].next!=-1)
    {
        printf("%05d ", l[tc].next);
        tc = l[tc].next;
        printf(l[tc].next==-1?"%d %d\n":"%d %05d\n", l[tc].key, l[tc].next);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

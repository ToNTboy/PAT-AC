#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 100000

typedef struct node
{
    int addr;
    int key;
    int next;
} node;

bool cmp(const node& a, const node& b)
{
    return a.key < b.key;
}

int n, head;
int keys[MAXN], nexts[MAXN];
vector<node> res;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int idx, cur;
    scanf("%d %d", &n, &head);
    if (head == -1)
    {
        printf("0 -1\n");
        return 0;
    }
    for (int i=0; i<n; i++)
    {
        scanf("%d", &idx);
        scanf("%d %d", &keys[idx], &nexts[idx]);
    }

    cur = head;
    node h = {head, keys[head], 0};
    res.push_back(h);
    while (nexts[cur] != -1)
    {
        cur = nexts[cur];
        node t = {cur, keys[cur], 0};
        res.push_back(t);
    }

    sort(res.begin(), res.end(), cmp);
    printf("%d %05d\n", res.size(), res[0].addr);
    for (int i=0; i<res.size(); i++)
    {
        res[i].next = (i+1 < res.size()? res[i+1].addr : -1);
        printf(res[i].next==-1? "%05d %d %d\n" : "%05d %d %05d\n", res[i].addr, res[i].key, res[i].next);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

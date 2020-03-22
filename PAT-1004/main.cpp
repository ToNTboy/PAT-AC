#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

//#define LOCAL

typedef struct node
{
    int level = 0;
    vector<int> children;
} node;

int n = 0, m = 0;
node tree[100];    // ignore tree[0]

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // input
    scanf("%d", &n);
    if (n == 0)
        return 0;
    scanf("%d", &m);

    int id, k, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &c);
            tree[id].children.push_back(c);
        }
    }

    // code
    tree[1].level = 1;
    int clv = 1, nums = 0;
    queue<int> wait;
    wait.push(1);
    while (!wait.empty())
    {
        int cid = wait.front();
        wait.pop();
        if (tree[cid].level > clv)
        {
            printf(clv == 1? "%d" : " %d", nums);
            nums = 0;
            clv++;
        }
        if (tree[cid].children.empty())
        {
            nums++;
            continue;
        }
        for (int i = 0; i < tree[cid].children.size(); i++)
        {
            int child = tree[cid].children[i];
            tree[child].level = tree[cid].level + 1;
            wait.push(child);
        }
    }
    printf(clv == 1? "%d" : " %d", nums);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

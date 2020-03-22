#include <cstdio>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 1001
#define lchild(x) (x<<1)
#define rchild(x) ((x<<1)+1)

int n, cur=0;
int data[MAXN];
int tree[MAXN];

void inorder(int p)
{
    if (p>n) return;
    inorder(lchild(p));
    tree[p]=data[cur];
    cur++;
    inorder(rchild(p));
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
        scanf("%d", &data[i]);
    }
    sort(data, data+n);
    inorder(1);
    for (int i=1; i<=n; i++)
    {
        printf(i==1? "%d": " %d", tree[i]);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

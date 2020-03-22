#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

#define LOCAL
#define MAXN 31
#define PUSH 1
#define POP 0

int n, r, i=1;
int lc[MAXN], rc[MAXN];
char push[] = "Push";

void postorder(int r)
{
    if (lc[r] != 0)
        postorder(lc[r]);
    if (rc[r] != 0)
        postorder(rc[r]);
    printf(i == n? "%d\n": "%d ", r);
    i++;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int id, preop = PUSH, prekey = 0;
    char oprt[5];
    stack<int> s;
    scanf("%d", &n);
    while (scanf("%s", oprt) > 0)
    {
        if (strcmp(push, oprt) == 0)
        {
            scanf("%d", &id);
            s.push(id);
            if (preop == PUSH)
            {
                lc[prekey] = id;
            }
            else
            {
                rc[prekey] = id;
            }
            preop = PUSH;
            prekey = id;
        }
        else
        {
            preop = POP;
            prekey = s.top();
            s.pop();
        }
    }
    postorder(lc[0]);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

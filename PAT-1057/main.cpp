#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

#define LOCAL

int n;
stack<int> s;
vector<int> e;
char POP[] = "Pop", PUSH[] = "Push", PEEK[] = "PeekMedian";

int bins(int lw, int hi, int val)
{
    if (hi - lw < 1) return -1;
    if (hi - lw == 1) return (e[lw] <= val? lw : lw-1);
    int mi = (hi + lw) / 2;
    if (e[mi] <= val)
        return bins(mi, hi, val);
    else
        return bins(lw, mi, val);
}

void push(int val)
{
    int pos = bins(0, e.size(), val);
    e.insert(e.begin()+pos+1, val);
    s.push(val);
}

void pop()
{
    if (s.empty())
    {
        printf("Invalid\n");
        return;
    }
    int v = s.top();
    printf("%d\n", v);
    s.pop();
    int pos = bins(0, e.size(), v);
    e.erase(e.begin()+pos);
}

void peek()
{
    if (s.empty())
    {
        printf("Invalid\n");
        return;
    }
    printf("%d\n", e[(e.size()+1)/2-1]);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    char oprt[10];
    int t;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%s", oprt);
        if (strcmp(PUSH, oprt) == 0)
        {
            scanf("%d", &t);
            push(t);
        }
        else if (strcmp(POP, oprt) == 0)
            pop();
        else if (strcmp(PEEK, oprt) == 0)
            peek();
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

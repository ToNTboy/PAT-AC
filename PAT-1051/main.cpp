#include <cstdio>
#include <stack>

using namespace std;

#define LOCAL

int m, n, k, p=1;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int t;
    bool error;
    scanf("%d %d %d\n", &m, &n, &k);
    for (int i=0; i<k; i++)
    {
        p=1;
        error = false;
        stack<int> s;
        for (int j=0; j<n; j++)
        {
            scanf("%d", &t);
            if (error)
                continue;
            if (p<=t)
            {
                if (t-p+1+s.size()>m)
                {
                    error = true;
                    continue;
                }
                while (p<=t)
                {
                    s.push(p);
                    p++;
                }
                s.pop();
            }
            else
            {
                if (s.top()!=t)
                {
                    error = true;
                    continue;
                }
                s.pop();
            }
        }

        if (error)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

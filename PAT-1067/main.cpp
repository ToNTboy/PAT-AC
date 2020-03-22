#include <bits/stdc++.h>

using namespace std;

#define LOCAL

int n, t, pos[100000];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        pos[t] = i;
    }
    int c=0;
    for (int i=1; i<n; i++)
    {
        if (pos[i]!=i)
        {
            while (pos[0]!=0)
            {
                swap(pos[0], pos[pos[0]]);
                c++;
            }
            if (pos[i]!=i)
            {
                swap(pos[0], pos[i]);
                c++;
            }
        }
    }
    printf("%d\n", c);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

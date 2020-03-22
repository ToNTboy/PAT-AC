#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 100000

int n;
char t[5];
set<int> id;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int tid, j;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%s", t);
        tid = j = 0;
        while (t[j] != '\0')
            tid += (t[j++] - '0');
        id.insert(tid);
    }
    printf("%d\n", id.size());
    for (set<int>::iterator it=id.begin(); it!=id.end(); it++)
        printf(it==id.begin()?"%d":" %d", *it);
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

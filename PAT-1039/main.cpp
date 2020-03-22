#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 40001

int n, k, ti, tn;
char tmp[5];
map<string, vector<int> > m;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &n, &k);
    for (int i=0; i<k; i++)
    {
        scanf("%d %d", &ti, &tn);
        for (int i=0; i<tn; i++)
        {
            scanf("%s", tmp);
            string sname(tmp);
            m[sname].push_back(ti);
        }
    }
    for (int i=0; i<n; i++)
    {
        scanf("%s", tmp);
        string sname(tmp);
        printf("%s ", tmp);
        vector<int> *a = &(m[sname]);
        sort(a->begin(), a->end());
        printf(a->size()==0?"%d":"%d ", a->size());
        for (int i=0; i<a->size(); i++)
        {
            printf(i==0?"%d":" %d", (*a)[i]);
        }
        printf("\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

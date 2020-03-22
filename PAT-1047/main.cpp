#include <bits/stdc++.h>

using namespace std;

#define LOCAL

int n, k, c;
char tmp[5];
vector<int> courses[2501];

int ID(char *name)
{
    int id = 0;
    for (int i=0; i<3; i++)
    {
        id = (id * 26 + name[i] - 'A');
    }
    id = (id * 26 + name[3] - '0');
    return id;
}

char *NAME(int id, char name[5])
{
    name[0] = id/26/26/26 + 'A';
    name[1] = id/26/26%26 + 'A';
    name[2] = id/26%26 + 'A';
    name[3] = id%26 + '0';
    name[4] = '\0';
    return name;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++)
    {
        scanf("%s %d", tmp, &c);
        int id = ID(tmp);
        int tc;
        while (c--)
        {
            scanf("%d", &tc);
            courses[tc].push_back(id);
        }
    }
    for (int i=1; i<=k; i++)
    {
        sort(courses[i].begin(), courses[i].end());
        printf("%d %d\n", i, courses[i].size());
        for (int j=0; j<courses[i].size(); j++)
        {
            printf("%s\n", NAME(courses[i][j], tmp));
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

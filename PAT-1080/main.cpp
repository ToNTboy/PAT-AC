#include <bits/stdc++.h>

using namespace std;

#define LOCAL

typedef struct student
{
    int sid;
    int ge, gi;
    int choice[5];
    bool adm;
} stu;

typedef struct apy
{
    int sid;
    int ch;
} apy;

int n, m, k, t;
int quota[100];
stu ss[40000];
vector<int> admit[100];
int admge[100]={-1}, admgi[100]={-1};

bool cmp(const stu& a, const stu& b)
{
    if (a.ge + a.gi == b.ge + b.gi)
        return a.ge > b.ge;
    return a.ge + a.gi > b.ge + b.gi;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d %d", &n, &m, &k);
    for (int i=0; i<m; i++)
    {
        scanf("%d", &quota[i]);
    }
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &ss[i].ge, &ss[i].gi);
        ss[i].sid = i;
        for (int j=0; j<k; j++)
        {
            scanf("%d", &t);
            ss[i].choice[j] = t;
        }
    }

    sort(ss, ss+n, cmp);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<k; j++)
        {
            int ch = ss[i].choice[j];
            if (quota[ch] > 0)
            {
                quota[ch]--;
                admit[ch].push_back(ss[i].sid);
                admge[ch] = ss[i].ge;
                admgi[ch] = ss[i].gi;
                break;
            }
            else if (admge[ch] == ss[i].ge && admgi[ch] == ss[i].gi)
            {
                admit[ch].push_back(ss[i].sid);
                break;
            }
        }
    }

    for (int i=0; i<m; i++)
    {
        sort(admit[i].begin(), admit[i].end());
        for (int j=0; j<admit[i].size(); j++)
        {
            printf(j==0?"%d":" %d", admit[i][j]);
        }
        printf("\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

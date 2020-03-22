#include <cstdio>
#include <vector>

using namespace std;

#define LOCAL
#define MAXN 1000
#define NSIZE 11

int n;
char names[MAXN][NSIZE], pass[MAXN][NSIZE];
vector<int> mdf;

void check(int idx)
{
    int i = 0;
    bool modified = false;
    while (pass[idx][i]!='\0')
    {
        switch (pass[idx][i])
        {
        case '1':
            pass[idx][i] = '@';
            modified = true;
            break;
        case '0':
            pass[idx][i] = '%';
            modified = true;
            break;
        case 'l':
            pass[idx][i] = 'L';
            modified = true;
            break;
        case 'O':
            pass[idx][i] = 'o';
            modified = true;
            break;
        default:
            break;
        }
        i++;
    }
    if (modified)
    {
        mdf.push_back(idx);
    }
}

void prtmdf()
{
    if (mdf.size() == 0)
    {
        if (n < 2)
            printf("There is %d account and no account is modified\n", n);
        else
            printf("There are %d accounts and no account is modified\n", n);
        return;
    }
    printf("%d\n", mdf.size());
    for (int i=0; i<mdf.size(); i++)
    {
        printf("%s %s\n", names[mdf[i]], pass[mdf[i]]);
    }
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
        scanf("%s %s", names[i], pass[i]);
        check(i);
    }
    prtmdf();

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

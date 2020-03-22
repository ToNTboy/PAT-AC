#include <cstdio>
#include <cstring>

using namespace std;

#define LOCAL

int n, lcspos, last;
char lcs[257], tmp[257];

void updatelcs()
{
    for (int i=last, j=strlen(tmp)-1; i>=lcspos && j>=0;)
    {
        if (lcs[i] != tmp[j])
        {
            lcspos = i+1;
            break;
        }
        i--;
        j--;
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d\n", &n);
    scanf("%[^\n]\n", lcs);
    lcspos = 0;
    last = strlen(lcs) - 1;
    for (int i=1; i<n && lcspos <= last; i++)
    {
        scanf("%[^\n]\n", tmp);
        updatelcs();
    }

    if (lcspos > last)
    {
        printf("nai\n");
    }
    else
    {
        printf("%s\n", lcs+lcspos);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <cstdio>
#include <vector>

using namespace std;

#define LOCAL
#define MAXN 10001
#define ASC 129

char s1[MAXN], s2[MAXN];
char n[ASC];
vector<int> p[ASC];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%[^\n]\n", s1);
    scanf("%[^\n]\n", s2);

    int i=0, j;
    while (s1[i]!='\0')
    {
        j = s1[i];
        n[j]++;
        p[j].push_back(i);
        i++;
    }
    i=0;
    while (s2[i]!='\0')
    {
        j = s2[i];
        n[j] = -1;
        i++;
    }
    i=0;
    while (i<ASC)
    {
        if (n[i]==-1)
        {
            for (j=0; j<p[i].size(); j++)
            {
                s1[p[i][j]] = -1;
            }
        }
        i++;
    }
    i=0;
    while (s1[i]!='\0')
    {
        if (s1[i]!=-1)
        {
            printf("%c", s1[i]);
        }
        i++;
    }
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

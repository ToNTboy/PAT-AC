#include <cstdio>
#include <cstring>

using namespace std;

#define LOCAL

int n, n1, n2, n3;
char s[81];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%s", s);
    n = strlen(s);
    n1 = n3 = (n - 2) / 3 + 1;
    n2 = (n - 2) / 3 + (n - 2) % 3 + 2;
    if ((n - 2) % 3 == 2)
    {
        n2 -= 2;
        n1 += 1;
    }
    int i=0, j=n-1;
    for (; (j-i+1) > n2;)
    {
        printf("%c", s[i]);
        for (int k=0; k<n2-2; k++)
            printf(" ");
        printf("%c\n", s[j]);
        i++;
        j--;
    }
    for (;i<=j; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

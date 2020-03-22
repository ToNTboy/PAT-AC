#include <cstdio>

using namespace std;

#define LOCAL

char color[3];

void radix13(int num)
{
    color[0] = '0';
    color[1] = '0';
    int m, i=1;
    while (num && i>-1)
    {
        m = num % 13;
        num = num / 13;
        color[i] = m>9? m-10+'A': m+'0';
        i--;
    }
    color[2] = '\0';
    printf("%s", color);
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int r, g, b;
    scanf("%d %d %d\n", &r, &g, &b);
    printf("#");
    radix13(r);
    radix13(g);
    radix13(b);
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <cstdio>

using namespace std;

#define LOCAL

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    char s[10];
    int a, b, r, len, i=0;
    scanf("%d %d", &a, &b);
    r = a + b;
    len = sprintf(s, "%d", r);
    if (r < 0) {
        putchar('-');
        i++;
        len--;
    }
    putchar(s[i]);
    len--;
    i++;
    while (len > 0) {
        if (len % 3 == 0) {
            putchar(',');
        }
        putchar(s[i]);
        len--;
        i++;
    }
    putchar('\n');

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

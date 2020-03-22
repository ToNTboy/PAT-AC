#include <cstdio>

using namespace std;

#define LOCAL

typedef struct polynomial {
    int e;
    double c;
}p;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int e;
    double c;
    p *a, *b, *r;
    int ka, kb;

    scanf("%d", &ka);
    a = new p[ka];
    for( int i = 0; i < ka; i++) {
        scanf("%d %lf", &e, &c);
        a[i].e = e;
        a[i].c = c;
    }

    scanf("%d", &kb);
    b = new p[kb];
    for( int i = 0; i < kb; i++) {
        scanf("%d %lf", &e, &c);
        b[i].e = e;
        b[i].c = c;
    }

    r = new p[ka + kb];
    int i, j, k, *m;
    p *t;
    i = j = k = 0;
    while (ka > j || kb > k) {
        if (j == ka || k == kb) {
            t = (j == ka? b : a);
            m = (j == ka? &k : &j);
            r[i] = t[*m];
            (*m)++;
        } else {
            if (a[j].e == b[k].e) {
                r[i].e = a[j].e;
                r[i].c = a[j].c + b[k].c;
                j++;
                k++;
                if (r[i].c == 0) {
                    continue;
                }
            } else if (a[j].e < b[k].e) {
                r[i] = b[k];
                k++;
            } else {
                r[i] = a[j];
                j++;
            }
        }
        i++;
    }

    printf("%d", i);
    for (int h = 0; h < i; h++) {
        printf(" %d %.1f", r[h].e, r[h].c);
    }
    putchar('\n');

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

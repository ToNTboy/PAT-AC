#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define LOCAL
#define MAXM 800
#define MAXN 600

int m, n;
int img[MAXM*MAXN+1];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d %d\n", &m, &n);
    int c = m*n;
    for (int i=0; i<c; i++)
    {
        scanf("%d", &img[i]);
    }
    sort(img, img+c);

    int i=0, p=img[0], pb=-1, mxn=0, mxp=-1;
    img[c]=-2;
    while (i<=c)
    {
        if (img[i]!=p)
        {
            if (i-pb > mxn)
            {
                mxn=i-pb;
                mxp=p;
            }
            p=img[i];
            pb=i;
        }
        i++;
    }
    printf("%d\n", mxp);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

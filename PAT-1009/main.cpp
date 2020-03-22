#include <cstdio>
#include <map>

using namespace std;

#define LOCAL

map<int, double> result;
int exp1[1000], exp2[1000];
double coe1[1000], coe2[1000];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // input
    int k1, k2, tmpe;
    double tmpc;
    scanf("%d", &k1);
    for (int i=0; i<k1; i++)
    {
        scanf("%d %lf", &tmpe, &tmpc);
        exp1[i] = tmpe;
        coe1[i] = tmpc;
    }
    scanf("%d", &k2);
    for (int i=0; i<k2; i++)
    {
        scanf("%d %lf", &tmpe, &tmpc);
        exp2[i] = tmpe;
        coe2[i] = tmpc;
    }

    // code
    for (int i=0; i<k1; i++)
    {
        for (int j=0; j<k2; j++)
        {
            tmpe = exp1[i] + exp2[j];
            tmpc = coe1[i] * coe2[j];
            if (result.count(tmpe) != 0)
            {
                result[tmpe] = result[tmpe] + tmpc;
                if (result[tmpe]==0)
                {
                    result.erase(tmpe);
                }
            }
            else
            {
                result[tmpe] = tmpc;
            }
        }
    }
    printf("%d", result.size());
    for (map<int, double>::reverse_iterator it=result.rbegin(); it!=result.rend(); it++)
    {
        printf(" %d %.1lf", it->first, it->second);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

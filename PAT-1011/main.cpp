#include <cstdio>

using namespace std;

#define LOCAL

float bets[3][3];
int maxi[3];
int maxs = -1;
char r[3] = {'W', 'T', 'L'};

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // input
    for (int i=0; i<3; i++)
    {
        maxs = -1;
        for (int j=0; j<3; j++)
        {
            scanf("%f", &bets[i][j]);
            if (bets[i][j] > maxs)
            {
                maxs = bets[i][j];
                maxi[i] = j;
            }
        }
    }

    // code
    float sum = (bets[0][maxi[0]] * bets[1][maxi[1]] * bets[2][maxi[2]] * 0.65 - 1) * 2;
    printf("%c %c %c %.2f", r[maxi[0]], r[maxi[1]], r[maxi[2]], sum);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

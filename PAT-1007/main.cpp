#include <cstdio>

using namespace std;

#define LOCAL

int k;
int nums[10000];
int maxs = -1, sum = 0;
int bidx, eidx, cidx;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &k);
    bidx = 0;
    cidx = 0;
    eidx = k - 1;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
        if (sum < 0)
        {
            sum = 0;
            cidx = i + 1;
        }
        else if (maxs < sum)
        {
            maxs = sum;
            bidx = cidx;
            eidx = i;
        }
    }
    if (maxs < 0)
    {
        maxs = 0;
    }
    printf("%d %d %d", maxs, nums[bidx], nums[eidx]);



#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

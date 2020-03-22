#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 100001

int n, nums[MAXN], s1, s2;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &nums[i]);
    sort(nums, nums+n);
    for (int i=0; i<n/2; i++)
        s1 += nums[i];
    for (int i=n/2; i<n; i++)
        s2 += nums[i];
    printf("%d %d\n", n&1, s2-s1);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

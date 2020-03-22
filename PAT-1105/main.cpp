#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 10001

int N, m, n;
int nums[MAXN];

bool cmp(int& a, int& b)
{
    return a>b;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%lld", &N);
    REP(i, 0, N)
        scanf("%d", &nums[i]);
    sort(nums, nums+N, cmp);
    m = n = sqrt(N);
    while (N % n != 0)
        n--;
    m = N / n;
    vector<vector<int> > matrix(n);
    REP(i, 0, n)
        matrix[i].resize(m);
    int x = 0, y = 0, p = 0;
    int xl = -1, xr = n, yt = -1, yb = m;
    while (p < N)
    {
        while (x < xr && xl < x && yt < y && y < yb)
            matrix[x++][y] = nums[p++];
        x = xr-1; y++;
        yt++;
        while (x < xr && xl < x && yt < y && y < yb)
            matrix[x][y++] = nums[p++];
        y = yb-1; x--;
        xr--;
        while (x < xr && xl < x && yt < y && y < yb)
            matrix[x--][y] = nums[p++];
        x = xl+1; y--;
        yb--;
        while (x < xr && xl < x && yt < y && y < yb)
            matrix[x][y--] = nums[p++];
        y = yt+1; x++;
        xl++;
    }
    REP(i, 0, m)
    {
        REP(j, 0, n)
            printf(j==0?"%d":" %d", matrix[j][i]);
        printf("\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

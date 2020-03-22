#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LOCAL
#define lli long long int
#define MAXN 101

typedef struct test
{
    lli id;
    int local;
    int frank;
    int lrank;
    int score;
} test;

int n, k[MAXN], total;
vector<test> tests[MAXN];

bool cmp(const test& a, const test& b)
{
    if (a.score == b.score)
        return a.id < b.id;
    return a.score > b.score;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &k[i]);
        total += k[i];
        for (int j=0; j<k[i]; j++)
        {
            test t;
            t.local = i + 1;
            scanf("%lld %d", &t.id, &t.score);
            tests[i].push_back(t);
        }
        sort(tests[i].begin(), tests[i].end(), cmp);
        int pre = -1;
        for (int j=0; j<k[i]; j++)
        {
            if (tests[i][j].score != pre)
            {
                tests[i][j].lrank = j + 1;
                pre = tests[i][j].score;
            }
            else
                tests[i][j].lrank = tests[i][j-1].lrank;
        }
    }
    vector<test> merged;
    for (int i=0; i<n; i++)
    {
        merged.insert(merged.end(), tests[i].begin(), tests[i].end());
    }
    sort(merged.begin(), merged.end(), cmp);

    int pre = -1;
    printf("%d\n", total);
    for (int i=0; i<total; i++)
    {
        if (merged[i].score != pre)
        {
            merged[i].frank = i + 1;
            pre = merged[i].score;
        }
        else
            merged[i].frank = merged[i-1].frank;
        printf("%013lld %d %d %d\n", merged[i].id, merged[i].frank, merged[i].local, merged[i].lrank);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

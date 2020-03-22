#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define REP(x, b, e) for (int x=b; x<e; x++)
#define MAXN 101
#define WOLF -1
#define HUMAN 0

int n, m, t;
int state[MAXN], judge[MAXN];
vector<int> lie;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    REP(i, 1, n+1)
    scanf("%d\n", &judge[i]);
    REP(i, 1, n+1)
    {
        REP(j, i+1, n+1)
        {
            memset(state, HUMAN, sizeof(state));
            lie.clear();
            state[i] = state[j] = WOLF;
            REP(k, 1, n+1)
            {
                if (state[abs(judge[k])] != (judge[k] > 0? HUMAN : WOLF))
                    lie.push_back(k);
            }
            if (lie.size() == 2 && (state[lie[0]] + state[lie[1]] == -1))
            {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

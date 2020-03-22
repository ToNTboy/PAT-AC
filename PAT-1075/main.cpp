#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 100001

typedef struct user
{
    int uid;
    int tscore;
    int subscore[6];
    int solved;
} user;

int n, k, m;
int fmark[6];
user users[MAXN];

bool cmp(const user& a, const user& b)
{
    if (a.tscore == b.tscore)
    {
        if (a.solved == b.solved)
            return a.uid < b.uid;
        return a.solved > b.solved;
    }
    return a.tscore > b.tscore;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    memset(users, -1, sizeof(users));
    int uid, qid, score;
    scanf("%d %d %d", &n, &k, &m);
    for (int i=1; i<=k; i++)
    {
        scanf("%d", &fmark[i]);
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d %d %d", &uid, &qid, &score);
        users[uid].uid = uid;
        if (score == -1 && users[uid].subscore[qid] < 0)
            users[uid].subscore[qid] = -2;
        else if (users[uid].subscore[qid] < score)
            users[uid].subscore[qid] = score;
    }
    for (int i=1; i<=n; i++)
    {
        int solved = 0;
        users[i].uid = i;
        users[i].tscore = 0;
        bool rec = false;
        for (int j=1; j<=k; j++)
        {
            if (users[i].subscore[j] > -1)
                rec = true;
            users[i].tscore += (users[i].subscore[j]<0?0:users[i].subscore[j]);
            if (users[i].subscore[j] == fmark[j]) solved++;
        }
        if (!rec)
            users[i].tscore = -1;
        users[i].solved = solved;
    }
    sort(users+1, users+n+1, cmp);
    int crank = 0, ptscore = -2000;
    for (int i=1; i<=n; i++)
    {
        if (users[i].tscore == -1)
            break;
        if (users[i].tscore != ptscore)
        {
            crank = i;
            ptscore = users[i].tscore;
        }
        printf("%d ", crank);
        printf("%05d %d", users[i].uid, users[i].tscore);
        for (int j=1; j<=k; j++)
        {
            if (users[i].subscore[j] == -1)
                printf(" -");
            else
                printf(" %d", users[i].subscore[j]==-2?0:users[i].subscore[j]);
        }
        printf("\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

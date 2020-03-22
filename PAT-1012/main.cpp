#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LOCAL

#define A 'A'
#define C 'C'
#define M 'M'
#define E 'E'

typedef struct student
{
    int id, a, c, m, e;
    int rk;
    char mj;
} stu;

stu stus[1000000] = {0};

vector<int> a;
vector<int> c;
vector<int> m;
vector<int> e;

bool descbya(const int& i, const int& j)
{
    return stus[i].a > stus[j].a;
}

bool descbyc(const int& i, const int& j)
{
    return stus[i].c > stus[j].c;
}

bool descbym(const int& i, const int& j)
{
    return stus[i].m > stus[j].m;
}

bool descbye(const int& i, const int& j)
{
    return stus[i].e > stus[j].e;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int N, K, tid, ta, tc, tm, te, rk, mj;
    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++)
    {
        scanf("%d %d %d %d", &tid, &tc, &tm, &te);
        ta = (tc + tm + te) / 3;
        stus[tid].id = tid;
        stus[tid].a = ta;
        stus[tid].c = tc;
        stus[tid].m = tm;
        stus[tid].e = te;
        a.push_back(tid);
        c.push_back(tid);
        m.push_back(tid);
        e.push_back(tid);
    }
    sort(a.begin(), a.end(), descbya);
    sort(c.begin(), c.end(), descbyc);
    sort(m.begin(), m.end(), descbym);
    sort(e.begin(), e.end(), descbye);

    int prk = 1, trk;
    for (int i=0; i<N; i++)
    {
        if (i < 1 || stus[a[i]].a == stus[a[i-1]].a)
        {
            stus[a[i]].rk = prk;
        }
        else
        {
            stus[a[i]].rk = i+1;
            prk = i+1;
        }
        stus[a[i]].mj = A;
    }
    prk = 1;
    for (int i=0; i<N; i++)
    {
        if (i < 1 || stus[c[i]].c == stus[c[i-1]].c)
        {
            trk = prk;
        }
        else
        {
            trk = i+1;
            prk = i+1;
        }
        if (stus[c[i]].rk > trk)
        {
            stus[c[i]].rk = trk;
            stus[c[i]].mj = C;
        }
    }
    prk = 1;
    for (int i=0; i<N; i++)
    {
        if (i < 1 || stus[m[i]].m == stus[m[i-1]].m)
        {
            trk = prk;
        }
        else
        {
            trk = i+1;
            prk = i+1;
        }
        if (stus[m[i]].rk > trk)
        {
            stus[m[i]].rk = trk;
            stus[m[i]].mj = M;
        }
    }
    prk = 1;
    for (int i=0; i<N; i++)
    {
        if (i < 1 || stus[e[i]].e == stus[e[i-1]].e)
        {
            trk = prk;
        }
        else
        {
            trk = i+1;
            prk = i+1;
        }
        if (stus[e[i]].rk > trk)
        {
            stus[e[i]].rk = trk;
            stus[e[i]].mj = E;
        }
    }

    for (int i=0; i<K; i++)
    {
        scanf("%d", &tid);
        if (stus[tid].id == 0)
        {
            printf("N/A\n");
            continue;
        }
        printf("%d %c\n", stus[tid].rk, stus[tid].mj);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

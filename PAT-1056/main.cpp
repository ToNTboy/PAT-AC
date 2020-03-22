#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

#define LOCAL
#define MAXN 1000

int np, ng;
int p[MAXN], l[MAXN], seq[MAXN], res[MAXN];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %d\n", &np, &ng);
    for (int i=0; i<np; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i=0; i<np; i++)
    {
        scanf("%d", &seq[i]);
    }

    deque<int> q;
    vector<int> tmp(seq, seq+np);
    vector<int> wins;
    int w, lv=0;
    while (tmp.size()>1)
    {
        wins.clear();
        for (int i=0; i<tmp.size(); i+=ng)
        {
            w=tmp[i];
            for (int j=i; j<i+ng && j<tmp.size(); j++)
            {
                if (i==j)
                {
                    continue;
                }
                if (p[tmp[j]]>p[w])
                {
                    q.push_back(w);
                    l[w]=lv;
                    w=tmp[j];
                }
                else
                {
                    q.push_back(tmp[j]);
                    l[tmp[j]]=lv;
                }
            }

            wins.push_back(w);
        }
        tmp.clear();
        for (int i=0; i<wins.size(); i++)
        {
            tmp.push_back(wins[i]);
        }
        lv++;
    }
    q.push_back(tmp.front());
    l[tmp.front()]=lv;
    int plv=lv+1, prk=1, i=1;
    for (deque<int>::reverse_iterator it=q.rbegin(); it!=q.rend(); it++)
    {
        if (l[*it]!=plv)
        {
            plv=l[*it];
            prk=i;
            res[*it]=i;
        }
        else
        {
            res[*it]=prk;
        }
        i++;
    }
    for (int i=0; i<np; i++)
    {
        printf(i==0? "%d": " %d", res[i]);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

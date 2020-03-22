#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

#define LOCAL
#define MAXN 100000

typedef struct node
{
    double price;
    int pa;
    vector<int> childs;
} node;

double opri, rate, hpri = 0;
int n, num;
node s[MAXN];
vector<int> high;

void level(int r)
{
    deque<int> q;
    q.push_back(r);
    s[r].price = opri;
    while (!q.empty())
    {
        int t = q.front();
        q.pop_front();
        if (s[t].price > hpri)
        {
            hpri = s[t].price;
            num = 1;
        }
        else if (s[t].price == hpri)
        {
            num++;
        }
        double newpri = s[t].price * (rate/100+1);
        for (int i=0; i<s[t].childs.size(); i++)
        {
            int no = s[t].childs[i];
            s[no].price = newpri;
            q.push_back(no);
        }
    }
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %lf %lf", &n, &opri, &rate);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &s[i].pa);
        if (s[i].pa != -1)
            s[s[i].pa].childs.push_back(i);
    }
    for (int i=0; i<n; i++)
    {
        if (s[i].pa == -1)
        {
            level(i);
        }
    }
    printf("%.2lf %d\n", hpri, num);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

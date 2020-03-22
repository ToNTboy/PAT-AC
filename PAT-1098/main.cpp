#include <cstdio>
#include <algorithm>

using namespace std;

#define LOCAL
#define MAXN 101
#define lc(x) (((x + 1) * 2) - 1)
#define rc(x) ((x + 1) * 2)

int n, step=0;
int ori[MAXN], res[MAXN], instseq[MAXN], heapseq[MAXN];

void prtseq(int *seq)
{
    for (int i=0; i<n; i++)
    {
        printf(i==0? "%d" : " %d", seq[i]);
    }
    printf("\n");
}

bool issame(int *a, int *b)
{
    for (int i=0; i<n; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool inststep()
{
    if (step >= n)
        return false;
    int cur = instseq[step];
    int pos = 0;
    for (int i=step; i>0; i--)
    {
        if (cur >= instseq[i-1])
        {
            pos = i;
            break;
        }
    }
    for (int j=step; j>pos; j--)
    {
        instseq[j] = instseq[j-1];
    }
    instseq[pos] = cur;
    return issame(instseq, res);
}

void percodown(int idx, int hi)
{
    if (idx >= hi)
        return;
    int i = idx+1, j = i * 2;
    while(j <= hi)
    {
        if(j + 1 <= hi && heapseq[j] > heapseq[j-1])
            j++;
        if(heapseq[j-1] > heapseq[i-1])
        {
            swap(heapseq[j-1], heapseq[i-1]);
            i = j;
            j = i * 2;
        }
        else
            break;
    }
}

void initheap()
{
    for (int i=n-1; i>=0; i--)
    {
        percodown(i, n);
    }
}

void popmax()
{
    int t = heapseq[n-step-1];
    heapseq[n-step-1] = heapseq[0];
    heapseq[0] = t;
    percodown(0, n-step-1);
}

bool heapstep()
{
    if (step >= n)
        return false;
    popmax();
    return issame(heapseq, res);
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
        scanf("%d", &ori[i]);
        instseq[i] = heapseq[i] = ori[i];
    }
    for (int i=0; i<n; i++)
    {
        scanf("%d", &res[i]);
    }

    initheap();
    for (step=0; step<n; step++)
    {
        if (inststep())
        {
            printf("Insertion Sort\n");
            do
            {
                step++;
                inststep();
            }
            while (issame(instseq, res) && step < n-1);
            prtseq(instseq);
            break;
        }
        else
        {
            if (heapstep())
            {
                printf("Heap Sort\n");
                step++;
                heapstep();
                prtseq(heapseq);
                break;
            }
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

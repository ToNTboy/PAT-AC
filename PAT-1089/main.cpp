#include <bits/stdc++.h>

using namespace std;

#define LOCAL

int n;
int iseq[100], mseq[100], cseq[100];

bool equalseg(int *a, int *b, int l)
{
    return memcmp(a, b, sizeof(int)*l) == 0;
}

bool insertstep(int *a, int l, int s)
{
    if (s>=l) return true;
    for (int i=s-1; i>=-1; i--)
    {
        if (i==-1 || a[i]<=a[s])
        {
            int t = a[s];
            for (int j=s; j>i+1; j--)
            {
                a[j] = a[j-1];
            }
            a[i+1] = t;
            return equalseg(a, cseq, l);
        }
    }
    exit(-1);
}

void trymerge(int *a, int lw, int mi, int hi, int l)
{
    if (mi >= l) return;
    hi = min(hi, l);
    int *A = new int[mi-lw], *B=a+mi;
    memcpy(A, a+lw, sizeof(int)*(mi-lw));
    int i=0, j=0, k=lw;
    while (i<(mi-lw))
    {
        if (j>=(hi-mi))
            a[k++] = A[i++];
        else
            a[k++] = (A[i]>B[j]?B[j++]:A[i++]);
    }
}

bool mergestep(int *a, int l, int s)
{
    int width = 1<<(s-1);
    if (width >= l) return true;
    for (int i=0; i<l; i+=(width<<1))
    {
        trymerge(a, i, i+width, i+(width<<1), l);
    }
    return equalseg(a, cseq, l);
}

void prtseq(int *seq, int l)
{
    for (int i=0; i<l; i++)
    {
        printf(i==0?"%d":" %d", seq[i]);
    }
    printf("\n");
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &iseq[i]);
    for (int i=0; i<n; i++)
        scanf("%d", &cseq[i]);

    // merge sort
    memcpy(mseq, iseq, sizeof(int)*n);

    int step = 1;
    while(!mergestep(mseq, n, step))
    {
        step++;
    }
    if (equalseg(mseq, cseq, n))
    {
        step++;
        while(mergestep(mseq, n, step))
        {
            step++;
        }
        printf("Merge Sort\n");
        prtseq(mseq, n);
    }
    else
    {
        // insertion sort
        step = 1;
        while (!insertstep(iseq, n, step))
        {
            step++;
        }
        if (equalseg(iseq, cseq, n))
        {
            step++;
            while(insertstep(iseq, n, step))
            {
                step++;
            }
            printf("Insertion Sort\n");
            prtseq(iseq, n);
        }
        else
        {
            printf("No solution\n");
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

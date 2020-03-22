#include <bits/stdc++.h>

using namespace std;

#define LOCAL

int num, t, ms, mlen;
deque<int> s;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &num);
    t = num;
    for (int i=2; i<sqrt(num); i++)
    {
        if (t%i==0)
        {
            s.push_back(i);
            t /= i;
            if (mlen < s.size())
            {
                ms = s.front();
                mlen = s.size();
            }
        }
        else
        {
            while (!s.empty())
            {
                t *= s.front();
                s.pop_front();
                if (t%i==0)
                {
                    s.push_back(i);
                    break;
                }
            }
        }
    }
    if (ms == 0)
    {
        ms = num;
        mlen = 1;
    }
    printf("%d\n", mlen);
    for (int i=0; i<mlen; i++)
    {
        printf(i==0?"%d":"*%d", ms+i);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

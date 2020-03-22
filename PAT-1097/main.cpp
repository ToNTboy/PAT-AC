#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 100000+10

int head = -1, tail = -1, remv = -1, rmtail = -1, n;
int key[MAXN], nxt[MAXN];
set<int> s;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int ti, tk, tn, cur;
    scanf("%d %d", &head, &n);
    while (n--)
    {
        scanf("%d %d %d", &ti, &tk, &tn);
        key[ti] = tk;
        nxt[ti] = tn;
    }
    cur = head;
    tail = head;
    s.insert(abs(key[head]));
    while (nxt[cur] != -1)
    {
        cur = nxt[cur];
        if (s.count(abs(key[cur])) > 0)
        {
            if (remv == -1)
            {
                remv = rmtail = cur;
            }
            else
            {
                nxt[rmtail] = cur;
                rmtail = cur;
            }
        }
        else
        {
            s.insert(abs(key[cur]));
            nxt[tail] = cur;
            tail = cur;
        }
    }
    nxt[tail] = -1;
    nxt[rmtail] = -1;
    cur = head;
    while (cur != -1)
    {
        printf(nxt[cur]==-1? "%05d %d -1\n":"%05d %d %05d\n", cur, key[cur], nxt[cur]);
        cur = nxt[cur];
    }
    cur = remv;
    while (cur != -1)
    {
        printf(nxt[cur]==-1? "%05d %d -1\n":"%05d %d %05d\n", cur, key[cur], nxt[cur]);
        cur = nxt[cur];
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

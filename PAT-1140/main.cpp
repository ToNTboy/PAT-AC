#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define MAXN 1000

char d[2], tmp[MAXN];
int n;
string t;

string nextnum(string& s)
{
    string nxt;
    int i=0, m=0;
    while (i<s.length())
    {
        m = 0;
        char c = s[i];
        nxt.append(1, c);
        while (i<s.length() && s[i] == c)
        {
            m++;
            i++;
        }
        sprintf(tmp, "%d", m);
        nxt.append(tmp);
    }
    return nxt;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%s %d", d, &n);
    t.append(d);
    for (int i=1; i<n; i++)
        t = nextnum(t);
    printf("%s\n", t.c_str());

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

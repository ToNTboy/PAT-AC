#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define LOCAL

char s[1048576+10];
map<string, int> m;

bool valid(char& c)
{
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void lower(int c)
{
    if (s[c] >= 'A' && s[c] <= 'Z')
        s[c] = (s[c] + 'a' - 'A');
}


int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%[^\n]\n", s);
    int len = strlen(s);
    int num = 0, cur = 0;
    string str = "";
    while (cur < len)
    {
        lower(cur);
        if (valid(s[cur]))
        {
            str+=s[cur];
            num++;
        }
        else if (num > 0)
        {
            m[str]++;
            str = "";
            num = 0;
        }
        cur++;
    }
    if (num)
    {
        m[str]++;
    }

    int maxn = -1;
    string maxstr;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        if (it->second > maxn)
        {
            maxn = it->second;
            maxstr = it->first;
        }
        else if (it->second == maxn)
        {
            if (it->first.compare(maxstr) < 0)
            {
                maxstr = it->first;
            }
        }
    }

    printf("%s %d\n", maxstr.c_str(), maxn);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

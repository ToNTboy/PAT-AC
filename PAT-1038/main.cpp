#include <bits/stdc++.h>

using namespace std;

#define LOCAL

int n, tn;
char tc[9];
vector<string> nums;

bool cmp(const string& a, const string& b)
{
    size_t la = a.length(), lb = b.length();
    int diff = strncmp(a.c_str(), b.c_str(), la<lb?la:lb);
    if (diff == 0 && la != lb)
    {
        string ta(a), tb(b);
        ta.append(b);
        tb.append(a);
        if ((diff = ta.compare(tb)) == 0)
            return la < lb;
    }
    return diff < 0;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d ", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%s", tc);
        string tnum(tc);
        nums.push_back(tnum);
    }
    sort(nums.begin(), nums.end(), cmp);
    bool f = true;
    for (int i=0; i<n; i++)
    {
        sscanf(nums[i].c_str(), "%d", &tn);
        if (tn == 0 && i!=n-1)
            continue;
        if (f)
        {
            printf("%d", tn);
            f = false;
        }
        else
        {
            printf("%s", nums[i].c_str());
        }
    }
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define LOCAL
#define MAXN 66
#define BASE 100000000
#define WIDTH 8

/******************************************************
** a Big-Interger template with add and sub operation *
*******************************************************/

int n;
char a[MAXN], b[MAXN], c[MAXN];

typedef struct bigint
{
    int sign;
    vector<int> nums;
    bool lt(const vector<int>& a, const vector<int>& b)
    {
        if (a.size() < b.size())
            return true;
        else if (a.size() > b.size())
            return false;
        int i = a.size()-1;
        while (a[i] == b[i] && i > 0)
        {
            i--;
        }
        return a[i] < b[i];
    }
    void addpos(const vector<int>& a, const vector<int>& b, vector<int>& res)
    {
        res.clear();
        int add = 0;
        int ta, tb, tres, cur = 0;
        while (cur < a.size() || cur < b.size())
        {
            ta = (cur < a.size()? a[cur] : 0);
            tb = (cur < b.size()? b[cur] : 0);
            tres = ta + tb + add;
            res.push_back(tres % BASE);
            add = tres / BASE;
            cur++;
        }
        if (add > 0)
            res.push_back(add);
    }
    void subpos(const vector<int>& a, const vector<int>& b, vector<int>& res)
    {
        // a is no less than b
        res.clear();
        int add = 0;
        int ta, tb, tres, cur = 0;
        while (cur < a.size() || cur < b.size())
        {
            ta = (cur < a.size()? a[cur] : 0);
            tb = (cur < b.size()? b[cur] : 0);
            tres = ta - tb + add;
            res.push_back(tres < 0? tres + BASE : tres);
            add = (tres < 0? -1 : 0);
            cur++;
        }
        while (res.size() > 1 && res.back() == 0)
        {
            res.pop_back();
        }
    }
    bool operator<(const bigint& b)
    {
        if (this->sign == b.sign)
        {
            if (this->sign == -1)
                return lt(b.nums, this->nums);
            else
                return lt(this->nums, b.nums);
        }
        if (this->sign == -1)
            return true;
        return false;
    }
    bigint operator+(const bigint& b)
    {
        bigint sum;
        if (this->sign == b.sign)
        {
            sum.sign = this->sign;
            addpos(this->nums, b.nums, sum.nums);
        }
        else
        {
            if (lt(this->nums, b.nums))
            {
                subpos(b.nums, this->nums, sum.nums);
                sum.sign = b.sign;
            }
            else if (lt(b.nums, this->nums))
            {
                subpos(this->nums, b.nums, sum.nums);
                sum.sign = this->sign;
            }
            else
            {
                sum.nums.clear();
                sum.nums.push_back(0);
                sum.sign = 1;
            }
        }
        return sum;
    }
    bigint(){}
    bigint(char *num, int l)
    {
        if (num[0] == '-')
        {
            sign = -1;
            num++;
            l--;
        }
        else
        {
            sign = 1;
        }

        int t;
        char tmp[WIDTH+1];
        while (l-WIDTH > 0)
        {
            l -= WIDTH;
            strncpy(tmp, num+l, WIDTH);
            tmp[WIDTH] = '\0';
            sscanf(tmp, "%d", &t);
            nums.push_back(t);
        }
        strncpy(tmp, num, l);
        tmp[l] = '\0';
        sscanf(tmp, "%d", &t);
        nums.push_back(t);
    }
    void prt()
    {
        if (sign == -1)
            printf("-");
        printf("%d", nums[nums.size()-1]);
        for (int i=nums.size()-2; i>=0; i--)
        {
            printf("%08d", nums[i]);
        }
        printf("\n");
    }
} bigint;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%s %s %s", a, b, c);
        bigint ta(a, strlen(a)), tb(b, strlen(b)), tc(c, strlen(c));
        if (tc < (ta+tb))
            printf("Case #%d: true\n", i+1);
        else
            printf("Case #%d: false\n", i+1);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}


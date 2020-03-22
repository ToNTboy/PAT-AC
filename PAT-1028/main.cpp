#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define LOCAL
#define MAXN 100001

typedef struct student
{
    int id;
    char name[9];
    int grade;
} stu;

bool cmp1(const stu& a, const stu& b)
{
    return a.id < b.id;
}

bool cmp2(const stu& a, const stu& b)
{
    int t = strcmp(a.name, b.name);
    if (t==0)
        return a.id < b.id;
    return t < 0;
}

bool cmp3(const stu& a, const stu& b)
{
    if (a.grade == b.grade)
        return a.id < b.id;
    return a.grade < b.grade;
}

int n, c;
stu s[MAXN];
bool (*cmp[3])(const stu& a, const stu& b) = {cmp1, cmp2, cmp3};

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    scanf("%d %d", &n, &c);
    for (int i=0; i<n; i++)
    {
        scanf("%d %s %d", &s[i].id, s[i].name, &s[i].grade);
    }
    sort(s, s+n, cmp[c-1]);
    for (int i=0; i<n; i++)
    {
        printf("%06d %s %d\n", s[i].id, s[i].name, s[i].grade);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

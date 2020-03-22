#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LOCAL
#define M 0
#define F 1

typedef struct student
{
    char name[11];
    char gender;
    char id[11];
    int grade;
} stu;

bool cmp(const stu& a, const stu& b)
{
    return a.grade < b.grade;
}

vector<stu> m, f;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    // code
    int n;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++)
    {
        stu s;
        scanf("%s %c %s %d\n", s.name, &s.gender, s.id, &s.grade);
        if (s.gender=='M')
        {
            m.push_back(s);
        } else
        {
            f.push_back(s);
        }
    }
    sort(m.begin(), m.end(), cmp);
    sort(f.begin(), f.end(), cmp);

    if (f.empty())
    {
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", f.back().name, f.back().id);
    }

    if (m.empty())
    {
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", m.front().name, m.front().id);
    }

    if (f.empty() || m.empty())
    {
        printf("NA\n");
    }
    else
    {
        printf("%d\n", f.back().grade - m.front().grade);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

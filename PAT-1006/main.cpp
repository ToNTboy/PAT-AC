#include <cstdio>
#include <cstring>

using namespace std;

#define LOCAL

typedef struct time
{
    int hh;
    int mm;
    int ss;
    bool operator<(const struct time &b)
    {
        if (this->hh < b.hh)
        {
            return true;
        }
        else if (this->hh == b.hh)
        {
            if (this->mm < b.mm)
            {
                return true;
            }
            else if (this->mm == b.mm)
            {
                if (this->ss < b.ss)
                {
                    return true;
                }
            }
        }
        return false;
    }
    time(int nhh, int nmm, int nss) : hh(nhh), mm(nmm), ss(nss) {}
} time;

char unlock[16], lock[16], id[16];
time early(99, 99, 99), late(-1, -1, -1);
int ihh, imm, iss, ohh, omm, oss;
int n;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d %d:%d:%d", id, &ihh, &imm, &iss, &ohh, &omm, &oss);
        time in(ihh, imm, iss), out(ohh, omm, oss);
        if (in < early)
        {
            early = in;
            strcpy(unlock, id);
        }
        if (late < out)
        {
            late = out;
            strcpy(lock, id);
        }
    }
    printf("%s %s", unlock, lock);

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

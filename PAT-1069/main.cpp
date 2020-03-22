#include <bits/stdc++.h>

using namespace std;

#define LOCAL

int num;
char decn[5] = {0}, incn[5] = {0}, tmp[5] = {0};

void convert(char *tmp, char *decn, char *incn)
{
    sort(tmp, tmp+4);
    for (int i=0; i<4; i++)
        incn[i] = tmp[i];
    for (int i=0; i<4; i++)
        decn[i] = tmp[3-i];
}

void calc(char *tmp, char *decn, char *incn)
{
    int a, b;
    sscanf(decn, "%d", &a);
    sscanf(incn, "%d", &b);
    sprintf(tmp, "%04d", a-b);
}

bool step()
{
    convert(tmp, decn, incn);
    calc(tmp, decn, incn);
    printf("%s - %s = %s\n", decn, incn, tmp);
    if (strcmp(tmp, "6174") == 0)
        return true;
    return false;
}

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &num);
    sprintf(tmp, "%04d", num);
    if (tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[2] == tmp[3])
        printf("%s - %s = 0000\n", tmp, tmp);
    else
        while (!step()) {}

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

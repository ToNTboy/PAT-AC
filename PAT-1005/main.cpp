#include <cstdio>
#include <cstring>

using namespace std;

//#define LOCAL

char digit[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char num[102];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%s", num);

    // code
    int sum = 0;
    for (int i = 0; i < strlen(num); i++)
    {
        int tmp = num[i] - '0';
        sum += tmp;
    }
    sprintf(num, "%d", sum);

    for (int i = 0; i < strlen(num); i++)
    {
        printf(i == 0? "%s" : " %s", digit[num[i] - '0']);
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}

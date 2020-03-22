#include <cstdio>
using namespace std;

int main() {
    FILE *in = freopen("input.dat", "r", stdin);
    int result = 0;
    int n;
    scanf("%d", &n);
    int *elems = new int[n];
    int *rmin = new int[n];
    int *lmax = new int[n];
    int *res = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }
    rmin[n-1] = elems[n-1];
    lmax[0] = elems[0];
    for (int i = 1; i < n; i++) {
        if (lmax[i-1] < elems[i]) {
            lmax[i] = elems[i];
        } else {
            lmax[i] = lmax[i-1];
        }
    }
    for (int i = n-2; i > -1; i--) {
        if (elems[i] < rmin[i+1]) {
            rmin[i] = elems[i];
        } else {
            rmin[i] = rmin[i+1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (lmax[i] <= elems[i] && elems[i] <=rmin[i]) {
            result++;
            res[i] = 1;
        }
    }
    printf("%d\n", result);
    int count = result;
    for (int i = 0; i < n; i++) {
        if (res[i] == 1) {
            count--;
            if (count == result-1) {
                printf("%d", elems[i]);
            } else {
                printf("%c%d", ' ', elems[i]);
            }
        }
    }
    printf("\n");
    return 0;
}

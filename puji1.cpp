#include <iostream>
using namespace std;
int ml[1000];
int nl[1000];
int result[1000];

int* convertToHP(long int n, int* nlist) {
    int counter = 1;

    while (n % 10 != 0 || n / 10 != 0) {
        nlist[counter] = n % 10;
        counter++;
        n /= 10;
    }
    nlist[0] = --counter;

    return nlist;
}

void printHP(int* nlist) {
    for (int i = nlist[0]; i >= 1; i--) {
        cout << nlist[i];
    }

    cout << endl;
}

int* HPAdd (int* a, int* b, int* result) {
    memset(result, 0, 1000);
    int digit = a[0] > b[0] ? a[0] : b[0];
    for (int i = 1; i <= digit; i++) {
        if (a[i] + b[i] < 10) {
            result[i] = a[i] + b[i] + result[i];
        } else {
            result[i] = (a[i] + b[i]) % 10 + result[i];
            result[i+1] += 1;
        }
    }

    result[0] = result[digit + 1] == 0 ? digit : digit + 1;
    cout << "counter: " << result[0] << endl;

    return result;
}


int main () {
    long int m, n;
    cin >> m; cin >> n;

    printHP(HPAdd(convertToHP(m, ml), convertToHP(n, nl), result));
}

/*#include <iostream>
#include <cmath>
using namespace std;

int main () {
    long int n, k, base;
    int count = 0;
    cin >> n; cin >> k;
    base = n;
    for (int i = 0; i < 500; i++) {
        base *= n;
        count++;
        if (base % ((long int) pow(10, k)) == n) {
            cout << count << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}*/
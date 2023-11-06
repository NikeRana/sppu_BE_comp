#include <iostream>
using namespace std;

int binomialCoefficient(int n, int k) {
    int C[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    if (k > n) {
        cout << "Invalid input. k should be less than or equal to n." << endl;
    } else {
        int result = binomialCoefficient(n, k);
        cout << "C(" << n << ", " << k << ") = " << result << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

const int N = 6;
const int M = 1e9 + 7;

ll n;

struct Matrix {
    ll v[N][N];

    Matrix() {
        memset(v, 0, sizeof(v));
        for (int i = 0; i < N; i++)
            v[i][i] = 1;
    }

    Matrix(const ll d[N][N]) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                v[i][j] = d[i][j];
    }

    Matrix operator *(const Matrix& B) {
        Matrix C;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                C.v[i][j] = 0;
                for (int k = 0; k < N; k++)
                    C.v[i][j] += v[i][k] * B.v[k][j] % M, C.v[i][j] %= M;
            }

        return C;
    }

    Matrix pow(ll n) {
        Matrix X = *this;
        Matrix A;
        for (; n; X = X * X, n >>= 1)
            if (n & 1)
                A = A * X;

        return A;
    } 
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;

    ll base[N][N] = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1}
    };

    Matrix X(base);

    Matrix A = X.pow(n + 6);
    cout << A.v[0][0] << "\n";
    return 0;
}
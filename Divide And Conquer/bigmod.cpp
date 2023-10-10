// implementation of (a^k)%m using fermat's little therom and binomial exponential

#include<bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long b, long long m) {
    if (b == 0) {
        return 1;
    }
    
    long long result = 1;
    a = a % m;
    
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        
        b = b / 2;
        a = (a * a) % m;
    }
    
    return result;
}

long long modPowerUsingFermat(long long a, long long k, long long m) {
    long long pMinus1 = m - 1;
    k = k % pMinus1;
    
    return modPow(a, k, m);
}

int main() {
    long long a = 7;
    long long k = 123;
    long long m = 11;

    long long result = modPowerUsingFermat(a, k, m);

    std::cout << a << "^" << k << " mod " << m << " = " << result << std::endl;

    return 0;
}

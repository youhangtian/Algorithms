//greatest common divisor
int getgcd(int a, int b) {
    if (a == 0 || b == 0) return a + b;
    else return getgcd(b, a % b);
}

//a * x + b * y = gcd(a, b)
int euclide(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int g = euclide(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

//inverse, x * k = y * mod + 1, mod = 1e9 + 7
//a * x = (a + a * y * mod) / k
int getinv(int k) {
    int x, y;
    euclide(k, mod, x, y);
    return (x + mod) % mod;
}

//pow
int getpow(long a, long b) {
    long res = 1;
    
    while (b > 0) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        
        a *= a;
        a %= mod;
        b >>= 1;
    }
    
    return (int)res;
}

//i choose j
long long choose[size][size];
mem(choose, 0);

rep(i, size) {
    choose[i][0] = choose[i][i] = 1;
    for (int j = 1; j < i; j ++) choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
}

//prime numbers
vector<int> pres;
vector<bool> prime(n + 1, true);

for (int i = 2; i <= n; i ++) {
    if (prime[i]) {
        for (int i2 = i + i; i2 <= n; i2 += i) prime[i2] = false;
            pres.pb(i);
            }
}

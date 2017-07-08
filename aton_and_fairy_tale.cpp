#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    long long n, m;
    cin >> n >> m;
    if (m >= n)
    {
        cout << n << endl;
        return 0;
    }
    double x = (sqrt(1.0 + 8.0 * (double(n) - double(m))) - 1.0) / 2.0;
    long long r = (long long)(ceil(x)) << 1;
    long long l = (long long)(ceil(x)) >> 1;
    long long target = 2 * (n - m);
    while (l < r)
    {
        long long mid = (l + r) >> 1;
        long long x = mid * (mid + 1);
        if (x >= target)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l + m << endl;
    return 0;
}

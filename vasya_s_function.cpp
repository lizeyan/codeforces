#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
long long gcd(long long a, long long b)
{
    if(b)
        while ((a %= b) && (b %= a));
    return a + b;
}
int main ()
{
    long long a, b;
    cin >> a >> b;
    long long d = gcd(a, b);
    long long x = a / d, y = b / d;
    vector<long long> factors;
    for (long long i = 2; i * i <= x; ++i)
    {
        while (x % i == 0)
        {
            factors.push_back(i);
            x /= i;
        }
    }
    if (x > 1)
        factors.push_back(x);
    long long ans = 0;
    if (factors.size() == 1)
    {
        if (x > y)
        {
            ans = y;
        }
        else
        {
            ans = (y % x) + y / x;
        }
    }
    else
    {
        while (y != 0)
        {
            vector<long long> new_factors;
            long long t = y;
            for (long long factor: factors)
            {
                t = min(t, y % factor);
            }
            y -= t;
            ans += t;
            for (long long factor: factors)
            {
                if (y % factor != 0)
                {
                    t = min(t, y % factor);
                    new_factors.push_back(factor);
                }
                else
                {
                    y /= factor;
                }
            }
            factors.swap(new_factors);
        }
    }
    cout << ans << endl;
    return 0;
}
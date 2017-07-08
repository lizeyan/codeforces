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
    cout << (long long)(ceil(x)) + m << endl;
    return 0;
}
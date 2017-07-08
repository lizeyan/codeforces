#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    a %= b;
    return gcd(b, a);
}
int main ()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // Note that we should assure x and y both greater or equal to 0
    if ((d - b) % gcd(a, c) == 0)
    {
        if (d >= b)
        {
            int x = std::max(0, (d - b) / a);
            while (true)
            {
                int y = (a * x + b - d) / c;
                if (y >= 0 && y * c == a * x + b - d)
                    break;
                ++x;
            }
            cout << a * x + b << endl;
        }
        else
        {
            int y = std::max(0, (b - d) / c);
            while (true)
            {
                int x = (c * y + d - b) / a;
                if (x >= 0 && x * a == c * y + d - b)
                    break;
                ++y;
            }
            cout << c * y + d << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
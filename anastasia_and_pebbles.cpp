#include <iostream>
using namespace std;
int main ()
{
    int n, k;
    cin >> n >> k;
    int w;
    int half_days = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> w;
        half_days += (w + k - 1) / k;
    }
    int days = half_days >> 1;
    if (half_days & 1)
        days += 1;
    cout << days << endl;
    return 0;
}
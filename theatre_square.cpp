#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int m, n, a;
    cin >> n >> m >> a;
    cout << (long long)(ceil(double(n) / a) * ceil(double(m) / a)) << endl;
}
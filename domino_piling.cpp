#include <iostream>
using namespace std;
int main ()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    cout << (n / 2) * m + (n % 2) * (m / 2) << endl;
    return 0;
}

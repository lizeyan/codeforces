#include <iostream>
using namespace std;
int main ()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    size_t count = 0;
    size_t n;
    cin >> n;
    for (size_t i = 0; i != n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2)
            ++count;
    }
    cout << count << endl;
    return 0;
}

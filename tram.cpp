#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    size_t n;
    cin >> n;
    size_t capacity = 0;
    size_t num_psger = 0;
    for (size_t i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        num_psger -= a;
        num_psger += b;
        capacity = max(capacity, num_psger);
    }
    cout << capacity << endl;
    return 0;
}

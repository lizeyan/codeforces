#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    int count[5] = {0};
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        count[x] += 1;
    }
    int num_cars = 0;
    num_cars += count[4];

    num_cars += count[3];
    if (count[3] > 0)
        count[1] -= count[3];

    num_cars += ((count[2] + 1) / 2);
    if (count[2] % 2 > 0)
        count[1] -= 2;

    if (count[1] > 0)
        num_cars += ((count[1] + 3) / 4);

    cout << num_cars << endl;

    return 0;
}

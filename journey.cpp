#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int>* neighbors;
double journey(int pos, int comefrom)
{
    double sum = 0;
    int count = 0;
    for (const auto& city: neighbors[pos])
    {
        if (city == comefrom)
            continue;
        sum += journey(city, pos) + 1;
        ++count;
    }
    // cout << "pos:" << pos << endl;
    // cout << "come from:" << comefrom << endl;
    // cout << "sum:" << sum << endl;
    if (count == 0)
        return 0;
    else
        return sum / double(count);
}
int main ()
{
    cin >> n;
    neighbors = new vector<int>[n + 1];
    int a, b;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }
    cout.precision(17);
    cout << journey(1, 0) << endl;
    return 0;
}
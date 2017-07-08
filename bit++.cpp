#include <iostream>
#include <string>
using namespace std;
int main ()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    size_t n;
    cin >> n;
    string line;
    int x = 0;
    for (size_t i = 0; i != n; ++i)
    {
        getline(cin, line);
        if (line.size() != 3)
        {
            --i;
            continue;
        }
        if (line[0] == '+' || line[2] == '+')
            ++x;
        else
            --x;
    }
    cout << x << endl;
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main ()
{
    string a, b;
    cin >> a >> b;
    unordered_map<char, char> m;
    for (auto i = 0; i < 26; ++i)
    {
        m[a[i]] = b[i];
        m[a[i] - ('a' - 'A')] = b[i] - ('a' - 'A');
    }
    string c;
    cin >> c;
    string d;
    for (auto i = 0; i < c.size(); ++i)
    {
        if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
            d.push_back(m[c[i]]);
        else
            d.push_back(c[i]);
    }
    cout << d << endl;
    return 0;
}

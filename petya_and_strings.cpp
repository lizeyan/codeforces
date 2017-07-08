#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main ()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for_each(a.begin(), a.end(), [](char& c){if (c >= 'A' && c <= 'Z') c += ('a' - 'A');});
    for_each(b.begin(), b.end(), [](char& c){if (c >= 'A' && c <= 'Z') c += ('a' - 'A');});
    int result = 0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] < b[i])
        {
            result = -1;
            break;
        }
        else if (a[i] > b[i])
        {
            result = 1;
            break;
        }

    }
    cout << result << endl;
    return 0;

}

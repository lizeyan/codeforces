#include <iostream>
#include <string>
using namespace std;
int main ()
{
    size_t n = 0, max_volume = 0, current_volume = 0;
    cin >> n;
    string line;
    getline(cin, line);
    getline(cin, line);

    for (size_t i = 0; i < n; ++i)
    {
        char current = line[i];
        // cout << "current char:" << current << endl;
        if (!((current <= 'Z' && current >= 'A') || (current <= 'z' && current >= 'a')))
        {
            if (current_volume > max_volume)
                max_volume = current_volume;
            current_volume = 0;
            // cout << "current volume:" << current_volume << endl;
            // cout << "max volume:" << max_volume << endl;
        }
        else
        {
            if (current <= 'Z' && current >= 'A')
                current_volume += 1;
            // cout << "current volume:" << current_volume << endl;
        }
    }
    if (current_volume > max_volume)
        max_volume = current_volume;
    current_volume = 0;
    cout << max_volume << endl;
    return 0;
}
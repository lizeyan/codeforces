#include <iostream>
constexpr size_t max_length = 1000;
using namespace std;
int main ()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    std::string input;
    getline(cin, input);
    std::string output;
    for (const auto& _chr: input)
    {
        char chr = _chr;
        if (chr >= 'A' && chr <= 'Z')
            chr += ('a' - 'A');
        if ('a' == chr || 'e' == chr || 'i' == chr || 'o' == chr || 'u' == chr || 'y' == chr)
            ;
        else
        {
            output.push_back('.');
            output.push_back(chr);
        }
    }
    cout << output << endl;
    return 0;
}

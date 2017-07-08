#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main ()
{
    string input;
    getline(cin, input);
    vector<char> numbers;
    for (const auto& chr: input)
    {
        if (chr != '+')
            numbers.push_back(chr);
    }
    sort(begin(numbers), end(numbers));
    if (numbers.size() > 0)
        cout << numbers.front();
    for (size_t i = 1; i < numbers.size(); ++i)
        cout << '+' << numbers.at(i);
    cout << endl;
    return 0;
}

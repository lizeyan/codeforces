#include <iostream>
#include <array>
#include <algorithm>


using namespace std;
constexpr size_t Max = 12;
constexpr long long factorials[Max + 1] = {0};
template <size_t v>
struct Factorial
{
    constexpr static long long value = v * Factorial<v - 1>::value;
};
template <>
struct Factorial<0>
{
    constexpr static long long value = 1;
};
int main ()
{
    long long f[13];
    #define assign(x) (f[x] = Factorial<x>::value)
    assign(1);
    assign(2);
    assign(3);
    assign(4);
    assign(5);
    assign(6);
    assign(7);
    assign(8);
    assign(9);
    assign(10);
    assign(11);
    assign(12);
    int a, b;
    cin >> a >> b;
    cout << f[min(a, b)] << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(const string& num1, const string& num2)
{
    string result;
    int carry = 0;

    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        result.push_back(sum + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

string subtract(const string& num1, const string& num2)
{
    string result;
    int borrow = 0;

    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0)
    {
        int digit1 = num1[i--] - '0';
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }

    reverse(result.begin(), result.end());
    while (result.length() > 1 && result[0] == '0')
    {
        result.erase(result.begin());
    }
    return result;
}

string multiply(const string& num1, const string& num2)
{
    string result;
    int carry = 0;

    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 * digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        result.push_back(sum + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

string karatsubaMultiplication(const string& num1, const string& num2)
{
    int n = max(num1.length(), num2.length());

    if (n == 1)
    {
        int product = (num1[0] - '0') * (num2[0] - '0');
        return to_string(product);
    }

    string x = num1;
    string y = num2;
    while (x.length() < n)
        x.insert(x.begin(), '0');
    while (y.length() < n)
        y.insert(y.begin(), '0');

    int m = (n + 1) / 2;

    string a = x.substr(0, n - m);
    string b = x.substr(n - m);
    string c = y.substr(0, n - m);
    string d = y.substr(n - m);

    string ac = karatsubaMultiplication(a, c);
    string bd = karatsubaMultiplication(b, d);
    string sumOfABCD = karatsubaMultiplication(add(a, b), add(c, d));

    string part1 = ac;
    string part2 = subtract(subtract(sumOfABCD, ac), bd);
    string part3 = bd;

    for (int i = 0; i < 2 * m; ++i)
        part1.push_back('0');
    for (int i = 0; i < m; ++i)
        part2.push_back('0');
    return add(add(part1, part2), part3);
}

int main()
{
    string number1, number2;
    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2;

    string product = karatsubaMultiplication(number1, number2);

    cout << "---------------------ANSWER-----------------------" << endl;

    cout << "Product of the numbers: " << product << endl;

    return 0;
}

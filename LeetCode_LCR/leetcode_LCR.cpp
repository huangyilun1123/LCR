#include <bits/stdc++.h>
using namespace std;

// LCR #1 两数相除
int divide(int a, int b)
{

    int sign = 1;
    if ((a > 0 && b < 0) || (a < 0 && b > 0))
        sign = -1;

    a = abs(a);
    b = abs(b);

    int res = 0;
    int count = 1;
    while (a >= b)
    {
        a = a - b;
        b >> 1;
        count >> 1;
        res += count;
    }
    return sign == -1 ? res : -res;
}

// LCR #2 二进制求和
string addBinary(string a, string b)
{
    string res;
    if (a.size() < b.size())
    {
        string temp;
        temp = a;
        a = b;
        b = temp;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int cal = 0;
    for (int i = 0; i < b.size(); ++i)
    {
        if (a[i] == '1' && b[i] == '1' && cal == 1)
        {
            res.push_back('1');
            cal = 1;
        }
        else if (a[i] == '1' && b[i] == '1' && cal == 0)
        {
            res.push_back('0');
            cal = 1;
        }
        else if (a[i] == '1' && b[i] == '0' && cal == 1)
        {
            res.push_back('0');
            cal = 1;
        }
        else if (a[i] == '1' && b[i] == '0' && cal == 0)
        {
            res.push_back('1');
            cal = 0;
        }
        else if (a[i] == '0' && b[i] == '1' && cal == 1)
        {
            res.push_back('0');
            cal = 1;
        }
        else if (a[i] == '0' && b[i] == '1' && cal == 0)
        {
            res.push_back('1');
            cal = 0;
        }
        else if (a[i] == '0' && b[i] == '0' && cal == 1)
        {
            res.push_back('1');
            cal = 0;
        }
        else if (a[i] == '0' && b[i] == '0' && cal == 0)
        {
            res.push_back('0');
            cal = 0;
        }
    }

    for (int i = b.size(); i < a.size(); i++)
    {
        if (a[i] == '1' && cal == 0)
        {
            res.push_back('1');
            cal = 0;
        }
        else if (a[i] == '1' && cal == 1)
        {
            res.push_back('0');
            cal = 1;
        }
        else if (a[i] == '0' && cal == 1)
        {
            res.push_back('1');
            cal = 0;
        }
        else if (a[i] == '0' && cal == 0)
        {
            res.push_back('0');
            cal = 0;
        }
    }
    if (cal == 1)
        res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}

// LCR #3 比特位计数
// 一般方法
vector<int> countBits(int n)
{

    vector<int> res;
    for (int i = 0; i <= n; i++)
    {
        int numcount = 0;
        int m = i;
        while (m > 0)
        {
            if (m % 2 == 1)
                numcount++;
            m = m / 2;
        }
        res.push_back(numcount);
    }

    return res;
}
// 动态规划
vector<int> countBits_dp(int n)
{
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            dp[i] = dp[i / 2];
        else if (i % 2 == 1)
            dp[i] = dp[i / 2] + 1;
    }

    return dp;
}

// LCR #4 只出现一次的数字

int singleNum(vector<int> &nums)
{

    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
            return it.first;
    }

    return 0;
}

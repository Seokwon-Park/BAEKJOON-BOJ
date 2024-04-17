#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

string dp[251]; // true:SK, false:CY win

string add(string a, string b)
{
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;
	if (n < 17)
	{
		return to_string(stoll(a) + stoll(b));
	}
	string res(n, '0');
	int carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int tmp = (a[i] - '0') + (b[i] - '0') + carry;
		res[i] = tmp % 10 + '0';
		carry = tmp / 10;
	}
	if (carry)
		res = '1' + res;

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";
	for (int i = 3; i <= 250; i++)
	{
		dp[i] = add(add(dp[i - 1], dp[i - 2]), dp[i-2]);
	}
	int n;
	while (cin >> n)
	{
		cout << dp[n] << '\n';
	}

	return 0;
}
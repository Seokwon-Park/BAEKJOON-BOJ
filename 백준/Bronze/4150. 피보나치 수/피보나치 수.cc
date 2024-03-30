#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string add(string a, string b)
{
	int n = max(a.size(), b.size());
	if (n < 18)
	{
		return to_string(stoll(a) + stoll(b));
	}
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;
	int carry = 0;
	string result(n, '0');
	for(int i = n - 1; i >= 0; i--)
	{
		int an = a[i] - '0';
		int bn = b[i] - '0';
		int res = (an + bn + carry) % 10;
		carry = (an + bn + carry) / 10;
		result[i] = res + '0';
	}
	if (carry)
		result = '1' + result;
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<string> dp(3);
	dp[1] = "1";
	dp[2] = "1";
	for (int i = 3; i <= n; i++)
	{
		dp.push_back(add(dp[i - 1], dp[i - 2]));
	}
	cout << dp[n];

	return 0;
}
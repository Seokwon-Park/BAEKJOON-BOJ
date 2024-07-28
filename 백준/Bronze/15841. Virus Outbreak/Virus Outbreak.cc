#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

using bigInt = vector<int>;
const ll base = 1e9;

bigInt stringToBigInteger(string s)
{
	bigInt res;
	while (s.size() % 9 != 0)s.insert(s.begin(), '0');
	for (int i = 0; i < s.size(); i += 9)
	{
		res.push_back(stoi(s.substr(i, 9)));
	}
	return res;
}

bigInt operator+(bigInt a, bigInt b)
{
	int n = max(a.size(), b.size());
	bigInt res(n, 0);
	while (a.size() < n)a.insert(a.begin(), 0);
	while (b.size() < n)b.insert(b.begin(), 0);
	ll carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ll x = a[i];
		ll y = b[i];
		ll tmp = (x + y + carry) % base;
		carry = (x + y + carry) / base;
		res[i] = tmp;
	}
	if (carry)
		res.insert(res.begin(), carry);
	return res;
}

ostream& operator<<(ostream& ost, bigInt a)
{
	ost << a[0];
	for (int i = 1; i < a.size(); i++)
	{
		ost << setw(9) << setfill('0') << a[i];
	}
	return ost;
}

bigInt dp[491];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	dp[0] = stringToBigInteger("0");
	dp[1] = stringToBigInteger("1");
	for (int i = 2; i <= 490; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	while (1)
	{
		int n;
		cin >> n;
		if (n == -1)
			break;
		cout << "Hour " << n << ": " << dp[n] << " cow(s) affected\n";

	}




	return 0;
}
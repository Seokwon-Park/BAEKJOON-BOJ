#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	if (n == 1)
	{
		cout << "no";
		return 0;
	}
	
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << "no";
			return 0;
		}
	}

	string s = to_string(n);
	string rev = s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '5' || s[i] == '8')
		{
			rev[s.size() - 1 - i] = s[i];
		}
		else if (s[i] == '6')
		{
			rev[s.size() - 1 - i] = '9';
		}
		else if (s[i] == '9')
		{
			rev[s.size() - 1 - i] = '6';
		}
		else if (s[i] == '3' || s[i] == '4' || s[i] == '7' )
		{
			cout << "no";
			return 0;
		}
	}

	ll revn = stoll(rev);
	for (ll i = 2; i * i <= revn; i++)
	{
		if (revn % i == 0)
		{
			cout << "no";
			return 0;
		}
	}
	cout << "yes";


	return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

string Sub(string a, string b)
{
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;
	int carry = 0;
	string ret(n, '0');
	for (int i = n - 1; i >= 0; i--)
	{
		int aa = a[i] - '0';
		int bb = b[i] - '0';
		int res = (aa - bb - carry) % 2;
		if (res < 0)
		{
			res += 2;
			carry = 1;
		}
		else
			carry = 0;
		ret[i] = res + '0';
	}

	int ix = 0;
	while (ret[ix] == '0')ix++;
	if (ix == ret.size())
		return "0";
	ret = ret.substr(ix);

	return ret;
}


string Add(string a, string b)
{
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;
	int carry = 0;
	string ret(n, '0');
	for (int i = n - 1; i >= 0; i--)
	{
		int aa = a[i] - '0';
		int bb = b[i] - '0';
		int res = (aa + bb + carry) % 2;
		carry = (aa + bb + carry) / 2;
		ret[i] = res + '0';
	}
	if (carry) ret = "1" + ret;

	return ret;
}

string And(string a, string b)
{
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;
	string ret(n, '0');
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == '1' && b[i] == '1')
			ret[i] = '1';
		else
			ret[i] = '0';
	}
	int ix = 0;
	while (ret[ix] == '0')ix++;
	if (ix == ret.size())
		return "0";
	ret = ret.substr(ix);
	return ret;
}


string Not(string a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '1')
			a[i] = '0';
		else
			a[i] = '1';
	}
	int ix = 0;
	while (a[ix] == '0')ix++;
	if (ix == a.size())
		return "0";
	a = a.substr(ix);
	return a;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;

	int ans = 0;
	while (s != "0")
	{
		ans++;
		s = Sub(s, And(s, Add(Not(s), "1")));
	}
	cout << ans;

	return 0;
}
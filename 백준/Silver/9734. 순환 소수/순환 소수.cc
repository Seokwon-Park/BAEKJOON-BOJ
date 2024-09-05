#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll pow(ll n, ll m)
{
	ll res = 1;
	for (int i = 0; i < m; i++)
	{
		res *= n;
	}
	return res;
}

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	while (cin >> s)
	{
		string tmp = "";
		int ix = 0;
		while (s[ix] != '.')
		{
			tmp += s[ix];
			ix++;
		}
		ix++;
		int asz = tmp.size();
		int a = stoi(tmp);

		tmp = "";
		while (s[ix] != '(')
		{
			tmp += s[ix];
			ix++;
		}
		ix++;
		int bsz = 0;
		int b = 0;
		if (!tmp.empty())
		{
			bsz = tmp.size();
			b = stoi(tmp);
		}
		tmp = "";
		while (s[ix] != ')')
		{
			tmp += s[ix];
			ix++;
		}
		int csz = tmp.size();
		int c = stoi(tmp);

		ll first = a;
		first *= pow(10, bsz);
		first += b;
		first *= pow(10, csz);
		first += c;
		//cout << first << '\n';

		ll firstx = pow(10, bsz + csz);
		ll second = a;
		second *= pow(10, bsz);
		second += b;
		//cout << second << '\n';
		ll secondx = pow(10, bsz);

		ll denom = firstx - secondx;
		ll numer = first - second;
		int g = gcd(denom, numer);

		cout << s << " = " << numer / g << " / " << denom / g << '\n';
	}
	return 0;
}
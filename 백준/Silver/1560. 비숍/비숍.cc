#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

string add(string a, string b)
{
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;
	int carry = 0;
	string ret(n, '0');
	for (int i = n - 1; i >= 0; i--)
	{
		int an = a[i] - '0';
		int bn = b[i] - '0';
		ret[i] = (an + bn + carry) % 10 + '0';
		carry = (an + bn + carry) / 10;
	}
	if (carry)
	{
		ret = '1' + ret;
	}
	return ret;
}

string sub(string a, string b) // a must bigger than b
{
	if (a == b)
		return "0";
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;
	int carry = 0;
	string ret(n, '0');
	for (int i = n - 1; i >= 0; i--)
	{
		int an = a[i] - '0';
		int bn = b[i] - '0';
		int tmp = an - bn - carry;
		if (tmp < 0)
		{
			ret[i] = (tmp + 10) % 10 + '0';
			carry = 1;
		}
		else
		{
			ret[i] = tmp + '0';
			carry = 0;
		}
	}

	int ix = 0;
	while (ret[ix] == 0) ix++;
	ret = ret.substr(ix);


	return ret;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	if (s == "1")
		cout << "1";
	else
		cout << add(s, sub(s, "2"));



	return 0;
}


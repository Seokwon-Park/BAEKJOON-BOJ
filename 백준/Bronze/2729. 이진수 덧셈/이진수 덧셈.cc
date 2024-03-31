#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string bitsum(string a, string b)
{
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;
	int carry = 0;
	string result(n, '0');
	for (int i = n - 1; i >= 0; i--)
	{
		int aa = a[i] - '0';
		int bb = b[i] - '0';
		int res = aa ^ bb ^ carry;
		carry = ((aa & bb) | ((aa ^ bb) & carry));
		result[i] = res + '0';
	}
	if (carry)
		result = '1' + result;
	return result;
}

void remove_zero(string& s)
{
	int ix = 0;
	while (s[ix] == '0') ix++;
	if (ix == s.size()) s = "0";
	else s = s.substr(ix);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string a, b;
		cin >> a >> b;
		remove_zero(a);
		remove_zero(b);
		cout << bitsum(a, b) << '\n';
	}

	return 0;
}
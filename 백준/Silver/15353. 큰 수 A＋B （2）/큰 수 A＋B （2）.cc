#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

using bigInt = vector<int>;
const int base = 1e9;

bigInt add(bigInt a, bigInt b)
{
	int n = max(a.size(), b.size());
	while (a.size() < n)a.push_back(0);
	while (b.size() < n)b.push_back(0);

	bigInt res(n);
	int carry = 0;
	for (int i = 0; i < n; i++)
	{
		ll tmp = (a[i] + b[i] + carry) % base;
		carry = (a[i] + b[i] + carry) / base;
		res[i] = tmp;
	}
	if (carry)
	{
		res.push_back(carry);
	}

	return res;
}

bigInt stob(string s)
{
	if (s.empty()) return stob("0");
	while (s.size() % 9 != 0)s = '0' + s;
	bigInt ret;
	for (int i = s.size(); i >=9; i-=9)
	{
		ret.push_back(stoi(s.substr(i - 9, 9)));
	}
	return ret;
}

ostream& operator<<(ostream& os, const bigInt& n)
{
	os << n[n.size()-1];
	for (int i = n.size() - 2; i >= 0; i--)
	{
		os << setw(9) << setfill('0') << n[i];
	}
	return os;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string A, B;
	cin >> A >> B;
	bigInt a = stob(A);
	bigInt b = stob(B);

	cout << add(a, b);

	return 0;
}
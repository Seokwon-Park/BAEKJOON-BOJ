#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

const double PI = acos(-1);

string add(string a, string b)
{
	if (a.size() < 9 && b.size() < 9)
	{
		long long l = stoll(a) + stoll(b);
		return to_string(l);
	}
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;
	string res(n, '0');
	int carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int an = a[i] - '0';
		int bn = b[i] - '0';

		int apb = (an + bn + carry) % 10;
		res[i] = apb +'0';
		carry = (an + bn + carry) / 10;
	}
	if (carry)
		res = '1' + res;

	return res;
}

bool operator<(string a, string b)
{
	if (a.size() != b.size())
	{
		return a.size() < b.size();
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i])
				continue;
			return a[i] < b[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int tc = 0; tc < 3; tc++)
	{
		int n;
		cin >> n;

		string pos = "0";
		string neg = "0";
		for (int i = 0; i < n; i++)
		{
			string num;
			cin >> num;

			if (num[0] == '-')
			{
				neg = add(neg, num.substr(1));
			}
			else
			{
				pos = add(pos, num);
			}
		}
		if (neg == pos)
		{
			cout << 0 << '\n';
		}
		else if (neg < pos)
		{
			cout << "+\n";
		}
		else
		{
			cout << "-\n";
		}

	}

	return 0;
}
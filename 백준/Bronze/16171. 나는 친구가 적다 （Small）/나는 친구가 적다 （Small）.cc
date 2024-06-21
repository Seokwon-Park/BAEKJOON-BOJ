#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<int> failure(string s)
{
	vector<int> f(s.size(), 0);
	int j = 0;
	for (int i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	return f;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	string s;
	int ix = 0;
	vector<int> f = failure(b);
	for (auto c : a)
	{
		if (!isdigit(c))
		{
			s += c;
		}
	}

	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (j > 0 && s[i] != b[j]) j = f[j - 1];
		if (s[i] == b[j]) j++;
		if (j == b.size())
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> failure(string s)
{
	int j = 0;
	vector<int> f(s.size());
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
	
	string crypt;
	cin >> crypt;

	int n;
	cin >> n;

	vector<vector<int>> f(n);
	vector<string> str(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		f[i] = failure(s);
		str[i] = s;
	}

	for (int shift = 0; shift < 26; shift++)
	{
		string decrypt = "";
		for (auto c : crypt)
		{
			int ix = c - 'a';
			ix = (ix + shift) % 26;
			decrypt += 'a' + ix;
		}

		for (int i = 0; i < n; i++)
		{
			int j = 0;
			for (int k = 0; k < decrypt.size(); k++)
			{
				while (j > 0 && decrypt[k] != str[i][j]) j = f[i][j - 1];
				if (decrypt[k] == str[i][j]) j++;
				if (j == str[i].size())
				{
					cout << decrypt;
					return 0;
				}
			}
		}
	}
	

	return 0;
}
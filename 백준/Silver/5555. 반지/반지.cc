#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> fail(string s)
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
	
	string p;
	cin >> p;
	vector<int> f = fail(p);
	int n;
	cin >> n;
	int cnt = 0;
	while (n--)
	{
		string s;
		cin >> s;
		s = s + s.substr(0, p.size());
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			while (j > 0 && s[i] != p[j]) j = f[j - 1];
			if (s[i] == p[j]) j++;
			if (j == p.size())
			{
				cnt++;
				break;
			}
		}
	}
	cout << cnt;


	return 0;
}
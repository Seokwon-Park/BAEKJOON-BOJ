#include<bits/stdc++.h>
using namespace std;

vector<int> fail(string& s)
{
	vector<int> f(s.size());;
	int j = 0;
	for (int i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str, pat;
	cin >> str >> pat;
	vector<int> f = fail(pat);

	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		while (j > 0 && str[i] != pat[j]) j = f[j - 1];
		if (str[i] == pat[j]) j++;
		if (j == pat.size())
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
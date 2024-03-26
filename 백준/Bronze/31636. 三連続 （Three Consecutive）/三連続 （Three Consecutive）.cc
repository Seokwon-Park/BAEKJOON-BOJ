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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	string p = "ooo";
	vector<int> f = fail(p);

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j > 0 && p[j] != s[i]) j = f[j - 1];
		if (s[i] == p[j]) j++;
		if (j == p.size())
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	//int cont = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	if (s[i] == 'o')
	//		cont++;
	//	else
	//		cont = 0;
	//}


	return 0;
}
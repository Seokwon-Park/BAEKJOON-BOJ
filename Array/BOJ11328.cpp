#include <bits/stdc++.h>

using namespace std;

string strfry(string str, string cmp_str)
{
	int str_n[26];
	int cmp_n[26];

	fill(str_n, str_n + 26, 0);
	fill(cmp_n, cmp_n + 26, 0);

	for (auto c : str)
	{
		str_n[c - 'a']++;
	}
	for (auto c : cmp_str)
	{
		cmp_n[c - 'a']++;
	}

	for (size_t i = 0; i < 26; i++)
	{
		if (str_n[i] != cmp_n[i]) return "Impossible";
	}
	return "Possible";

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		cout << strfry(s1, s2) << '\n';
	}
		
	return 0;
}



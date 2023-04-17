#include <bits/stdc++.h>

using namespace std;

bool cmp(string s1, string s2)
{
	if (s1.length() == s2.length())
	{
		if (s1 < s2) return true;
		else
			return false;
	}
	else if (s1.length() < s2.length())
		return true;
	else 
		return false;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> dict(n);
	for (int i = 0; i < n; i++)
	{
		cin >> dict[i];
	}
		
	sort(dict.begin(), dict.end(), cmp);
	dict.erase(unique(dict.begin(), dict.end()), dict.end());

	for (auto str: dict)
	{
		cout << str << '\n';
	}
	
	return 0;
}


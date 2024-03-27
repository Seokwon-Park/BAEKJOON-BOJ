#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		string a, b;
		cin >> a >> b;
		if (a.size() != b.size())
		{
			cout << a << " & " << b << " are NOT anagrams.\n";
			continue;
		}
		vector<int> alpha1(26, 0); 
		vector<int> alpha2(26, 0); 
		for (int i = 0; i < a.size(); i++)
		{
			alpha1[a[i] - 'a']++;
			alpha2[b[i] - 'a']++;
		}

		if (alpha1 != alpha2)
		{
			cout << a << " & " << b << " are NOT anagrams.\n";
		}
		else
		{
			cout << a << " & " << b << " are anagrams.\n";
		}
	}

	return 0;
}
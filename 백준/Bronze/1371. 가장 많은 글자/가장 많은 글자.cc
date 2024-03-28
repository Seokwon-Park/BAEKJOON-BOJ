#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

using ll = long long;

int a[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while (getline(cin, s))
	{
		for (char c : s)
		{
			a[c - 'a']++;
		}
	}

	int mx = *max_element(a, a + 26);
	for (int i = 0; i < 26; i++)
	{
		if (a[i] == mx)
			cout << (char)(i + 'a');
	}
	
	return 0;
}
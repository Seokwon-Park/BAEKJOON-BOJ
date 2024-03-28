#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	for (auto c : s)
	{
		a[c - 'A']++;
	}
	cout << (char)((min_element(a, a + 26)- a)+'A');

	return 0;
}
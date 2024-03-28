#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	while (*s.rbegin() == '0')
		s.pop_back();

	int cnt = 0;
	for (char c : s)
		if (c == '0')
			cnt++;
	cout << cnt;

	return 0;
}
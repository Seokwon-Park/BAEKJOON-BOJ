#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (find(s.begin(), s.end(), '+') != s.end())
			cnt++;
	}
	cout << cnt;

	return 0;
}
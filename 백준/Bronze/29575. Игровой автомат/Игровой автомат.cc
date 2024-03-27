#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int reward[10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		string c;
		int w;
		cin >> c >> w;
		reward[stoi(c)] = w;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cur -= 10;
		string c;
		cin >> c;
		cur += reward[stoi(c)];
	}

	cout << cur;

	return 0;
}

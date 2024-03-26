#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int timeline[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	istringstream iss(s);
	string tmp;
	int cnt = 0;
	while (getline(iss, tmp, ','))
	{
		cnt++;
	}
	cout << cnt;

	return 0;
}
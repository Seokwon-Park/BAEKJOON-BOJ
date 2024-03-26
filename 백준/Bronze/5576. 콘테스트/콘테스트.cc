#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int timeline[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> w(10), k(10);

	for (int i = 0; i < 10; i++)
	{
		cin >> w[i];
	}
	sort(w.begin(), w.end(), greater<int>());
	for (int i = 0; i < 10; i++)
	{
		cin >> k[i];
	}
	sort(k.begin(), k.end(), greater<int>());

	cout << w[0] + w[1] + w[2] << ' ' << k[0] + k[1] + k[2];

	return 0;
}

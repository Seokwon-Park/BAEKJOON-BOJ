#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> cur(11, -1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int cow, pos;
		cin >> cow >> pos;
		if (cur[cow] == -1)
		{
			cur[cow] = pos;
		}
		else
		{
			if (cur[cow] != pos)
			{
				cur[cow] = pos;
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}
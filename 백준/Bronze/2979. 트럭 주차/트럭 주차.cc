#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int timeline[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	int minst = INT_MAX;
	int maxed = INT_MIN;
	for (int i = 0; i < 3; i++)
	{
		int st, ed;
		cin >> st >> ed;
		minst = min(st, minst);
		maxed = max(ed, maxed);
		for (int j = st; j < ed; j++)
		{
			timeline[j]++;
		}
	}

	int ans = 0;
	for (int i = minst; i < maxed; i++)
	{
		if (timeline[i] == 1)
			ans += a;
		else if (timeline[i] == 2)
			ans += b*2;
		else if(timeline[i] == 3)
			ans += c*3;
	}
	cout << ans;

	return 0;
}
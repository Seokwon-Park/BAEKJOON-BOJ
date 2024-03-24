#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int isused[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (isused[input])
			ans++;
		else
			isused[input] = true;
	}
	cout << ans;
	
	return 0;
}

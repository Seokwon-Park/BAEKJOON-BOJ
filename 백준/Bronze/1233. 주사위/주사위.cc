#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t[81];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for (int i = 1; i <= s1; i++)
		for (int j = 1; j <= s2; j++)
			for (int k = 1; k <= s3; k++)
				t[i + j + k]++;
	
	int ans = 0;
	int val = INT_MIN;
	for(int i = 0; i<=s1+s2+s3; i++)
	{
		if (t[i] > val)
		{
			val = t[i];
			ans = i;
		}
	}
	cout << ans;

	return 0;
}
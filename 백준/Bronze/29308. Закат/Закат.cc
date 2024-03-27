#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int mx = INT_MIN;
	string ans;
	for (int i = 0; i < n; i++)
	{
		int cost;
		string name, str;
		cin >> cost >> name >> str;
		if (str == "Russia")
		{
			if (cost > mx)
			{
				mx = cost;
				ans = name;
			}
		}
	}
	cout << ans;

	return 0;
}
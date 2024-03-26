#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	bool isGood = true;
	for (int i = 0; i < 3; i++)
	{
		bool isSeven = false;
		for (int j = 0; j < n; j++)
		{
			int m;
			cin >> m;
			if (m == 7) isSeven = true;
		}
		if (!isSeven)
			isGood = false;
	}

	cout << (isGood ? 777 : 0);
	return 0;
}
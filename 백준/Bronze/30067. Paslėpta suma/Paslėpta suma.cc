#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int ans = 0;
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
		ans += n;
	}

	for (int i : v)
	{
		int tmp = ans - i;
		if (tmp == i)
		{
			cout << i;
			return 0;
		}
		
	}
	
	
	return 0;
}
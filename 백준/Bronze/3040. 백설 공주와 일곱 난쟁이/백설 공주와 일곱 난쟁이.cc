#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int sum = 0;
vector<int> v;
vector<int> ans;
bool isused[9];

bool func(int n)
{
	if (n == 7)
	{
		if (sum == 100)
			return true;
		else 
			return false;
	}
	for (int i = 0; i < 9; i++)
	{
		if (isused[i]) continue;
		if (sum + v[i] > 100) continue;
		isused[i] = true;
		sum += v[i];
		ans.push_back(v[i]);
		if (func(n + 1))
		{
			return true;
		}
		ans.pop_back();
		sum -= v[i];
		isused[i] = false;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 0; i< 9 ;i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	if (func(0))
	{
		for (int i : ans)
			cout << i << '\n';
	}

	return 0;
}
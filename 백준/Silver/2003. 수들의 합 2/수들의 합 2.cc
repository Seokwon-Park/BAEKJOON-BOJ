#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int st = 0 , ed = 0;
	vector<int> v;
	vector<int> presum(1, 0);
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 1; i <= n; i++)
	{
		presum.push_back(presum[i-1] + v[i-1]);
	}
	
	int answer = 0;
	while (ed <= n)
	{
		long long sum = presum[ed] - presum[st];
		if (sum <= m)
		{
			if (sum == m) answer++;
			ed++;
		}
		else
		{
			st++;
		}
	}

	cout << answer;

	return 0;
}
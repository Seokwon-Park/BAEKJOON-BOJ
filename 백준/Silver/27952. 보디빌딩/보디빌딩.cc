#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	long long cur = 0;
	int ans = 0;
	vector<int> avec;
	vector<int> bvec;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		avec.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		bvec.push_back(b);
	}
	for (int i = 0; i < n; i++)
	{
		cur += bvec[i];
		if (cur < avec[i])
		{
			cout << -1;
			return 0;
		}
	}
	cout << (cur - *avec.rbegin())/ x;

	return 0;
}
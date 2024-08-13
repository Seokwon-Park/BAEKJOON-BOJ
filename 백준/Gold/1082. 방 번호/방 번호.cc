#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int m;
	cin >> m;

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	vector<int> nums(10, 0);
	int a = min_element(v.begin()+1, v.end()) - v.begin();
	int b = min_element(v.begin(), v.end()) - v.begin();
	if (v[a] > m)
	{
		cout << 0;
		return 0;
	}
	int leftCost = m - v[a];
	int bPurchase = leftCost / v[b];
	leftCost = leftCost - (bPurchase * v[b]);
	nums[a]++;
	nums[b] += bPurchase;


	for (int i = n - 1; i > a; i--)
	{
		int gap = v[i] - v[a];
		if(leftCost >= gap)
		{
			nums[a]--;
			nums[i]++;
			leftCost -= gap;
			break;
		}


	}

	for (int i = n - 1; i > b; i--)
	{
		if (b == i) continue;
		int gap = v[i] - v[b];
 		while (nums[b] >0 && leftCost >= gap)
		{
			nums[b]--;
			nums[i]++;
			leftCost -= gap;
		}
	}

	for (int i = 9; i >= 0; i--)
	{
		while (nums[i]) 
		{
			cout << i;
			nums[i]--;
		}
	}


	return 0;

}
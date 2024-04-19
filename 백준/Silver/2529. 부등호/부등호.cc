#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int k;
string nums;

char v[10];
bool isused[10];

ll mx = LLONG_MIN;
ll mn = LLONG_MAX;
string smx;
string smn;

void func(int n)
{
	if (n == k + 1)
	{
		if (mx < stoll(nums))
		{
			mx = stoll(nums);
			smx = nums;
		}
		if (mn > stoll(nums))
		{
			mn = stoll(nums);
			smn = nums;
		}
		return;
	}
	if (n == 0)
	{
		for (int i = 0; i< 10; i++)
		{
			nums.push_back(i+'0');
			isused[i] = true;
			func(n+1);
			isused[i] = false;
			nums.pop_back();
		}
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (isused[i]) continue;
		if (v[n - 1] == '<')
		{
			if (nums[n - 1]-'0' > i) continue;
		}
		else if (v[n - 1] == '>')
		{
			if (nums[n - 1]-'0' < i) continue;
		}
		nums.push_back(i+'0');
		isused[i] = true;
		func(n+1);
		isused[i] = false;
		nums.pop_back();
	}
		
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> v[i];

	func(0);
	
	cout << smx << '\n';
	cout << smn;

	return 0;
}
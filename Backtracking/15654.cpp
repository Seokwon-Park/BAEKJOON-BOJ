#include <bits/stdc++.h>

using namespace std;

int n, m, in;
int arr[10];
int isused[10];
vector<int> nums;


//k는 수의 길이
void bt(int k)
{
	//base condition
	if (k == m)
	{
		//print
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}		
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!isused[i])
		{
			arr[k] = nums[i];
			isused[i] = 1;
			bt(k + 1);
			isused[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);				

	cin >> n >> m;

	nums.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	//사전 순 증가를 위해 sorting
	sort(nums.begin(), nums.end());
	
	bt(0);

	
	return 0;
}


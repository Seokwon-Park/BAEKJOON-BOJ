#include <bits/stdc++.h>

using namespace std;

int n, m, in;
int arr[13];
int isused[13];
int saved[13];
vector<int> nums;


//k는 수의 길이
void bt(int k)
{
	//base condition
	if (k == 6)
	{
		//print
		for (int i = 0; i < 6; i++) {
			cout << arr[i] << ' ';
		}		
		cout << '\n';
		return;
	}
	int tmp = 0;

	for (int i = 0; i < n; i++)
	{
		if(!isused[i])
		if (tmp != nums[i])
		{
			if (k > 0) {
				if (arr[k - 1] < nums[i])
				{
					saved[k] = nums[i];
					tmp = saved[k];
					arr[k] = nums[i];
					isused[i] = 1;
					bt(k + 1);
					isused[i] = 0;
				}
			}
			else
			{
				saved[k] = nums[i];
				tmp = saved[k];
				arr[k] = nums[i];
				isused[i] = 1;
				bt(k + 1);
				isused[i] = 0;
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);				

	while (1)
	{
		cin >> n;
		if (n == 0) break;

		nums.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		bt(0);
		cout << '\n';
	}

	
	return 0;
}


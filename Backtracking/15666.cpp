#include <bits/stdc++.h>

using namespace std;

int n, m, in;
int arr[10];
int isused[10];
int saved[10];
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
	int tmp = 0;
	//3 3
	//3 4 3 과 같은 입력이 들어온 경우
	//saved에 기존에 찾은 수열 (3 4 3)같은 값이 저장되어 있는데
	//4 3 ? 의 ? 에 들어갈 값을 찾는 과정에서 이미 saved에는 3이 들어가 있음
	//그래서 4 3 3 은 정상적인 결과이지만 출력이 x
	//따라서 해당 자리에 대해 처음 비교할때는 0으로 초기화 시키고 for문 내에서 다시 값을 설정해준다.
	for (int i = 0; i < n; i++)
	{
		if (tmp != nums[i])
		{
			if (k > 0) {
				if (arr[k - 1] <= nums[i])
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


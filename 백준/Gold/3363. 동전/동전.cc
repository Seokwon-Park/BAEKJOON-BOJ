#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

vector<int> nums[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	

	vector<char> cmp(3);
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int num;
			cin >> num;
			nums[i].push_back(num);
		}
		cin >> cmp[i];
		for (int j = 0; j < 4; j++)
		{
			int num;
			cin >> num;
			nums[i].push_back(num);
		}
	}

	vector<string> ans;
	for (int i = 1; i <= 12; i++)
	{
		// i 가 무거운 동전인 경우
		// 모순이 하나라도 있으면 후보가 될 수 없다.
		bool isCand = true;
		for (int j = 0; j < 3; j++) // 3개의 등식에 대해 i가 무거운 경우를 체크해보자.
		{
			int ix = find(nums[j].begin(), nums[j].end(), i) - nums[j].begin();
			if (ix == 8)// 부등식에 i가 없는 경우 equal이어야 하는데 아니면 모순
			{
				if (cmp[j] != '=')
				{
					isCand = false;
					break;
				}
			}
			else if (ix < 4) // 만약 무거운데 왼쪽이면 부등호가 > 여야 함. 아니면 모순
			{
				if (cmp[j] != '>')
				{
					isCand = false; 
					break;
				}
			}
			else // <=4인데 오른쪽에 있으면 부등호가 < 여야 함. 아니면 모순
			{
				if (cmp[j] != '<')
				{
					isCand = false;
					break;
				}
			}
		}

		if (isCand)
		{
			ans.push_back(to_string(i) + '+');
			continue;
		}
		// i가 가벼운 모조품일 경우를 보자ㅏ.
		isCand = true;
		for (int j = 0; j < 3; j++) // 3개의 등식에 대해 i가 가벼운 경우를 체크해보자.
		{
			int ix = find(nums[j].begin(), nums[j].end(), i) - nums[j].begin();
			if (ix == 8)// 부등식에 i가 없는 경우 equal이어야 하는데 아니면 모순
			{
				if (cmp[j] != '=')
				{
					isCand = false;
					break;
				}
			}
			else if (ix < 4) // 만약 무거운데 왼쪽이면 부등호가 < 여야 함. 아니면 모순
			{
				if (cmp[j] != '<')
				{
					isCand = false;
					break;
				}
			}
			else // <=4인데 오른쪽에 있으면 부등호가 < 여야 함. 아니면 모순
			{
				if (cmp[j] != '>')
				{
					isCand = false;
					break;
				}
			}
		}
		if (isCand)
		{
			ans.push_back(to_string(i) + '-');
		}
	}

	if (ans.empty()) // 비어 있으면 가능한 경우가 없다는 뜻
	{
		cout << "impossible";
	}
	else if (ans.size() == 1)
	{
		cout << ans[0];
	}
	else
	{
		cout << "indefinite";
	}

	return 0;
}


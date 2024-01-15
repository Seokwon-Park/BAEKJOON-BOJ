#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> plug;
	vector<int> usecnt(105, 0);
	vector<bool> isused(105, false);
	vector<int> list(k);
	for (int i = 0; i < k; i++)
	{
		cin >> list[i];
		usecnt[list[i]]++;
	}

	// 1. 같은 용품을 또 쓰는 경우
	// 2. 플러그가 비어있는 경우
	// 3. 앞으로 안쓸 거?
	// 4. 다시 써야 되는데 현재 플러그 기준으로 제일 나중에 필요한거?
	int answer = 0;
	for (int i =0; i< k; i++)
	{
		usecnt[list[i]]--; // list[i]번 물품의 남은 사용횟수를 감소시킨다.
		if (!isused[list[i]]) // 이 제품이 플러그에 꽂혀있지 않아야 쓸 수 있다. 꽂혀있으면 그냥 횟수만 내리고 스킵
		{
			isused[list[i]] = true;
			if (plug.size() < n) // 만약 중복도 아니고 빈 플러그가 있으면 꽂아준다.
			{
				plug.push_back(list[i]);
			}
			else
			{
				bool findFlag = false;
				for (int j = 0; j < n; j++)
				{
					if (usecnt[plug[j]] == 0) // 현재 꽂혀있는 플러그 물품 중에 이후에 쓸일이 없으면 걍 교체 해버리고 break;
					{ // 어차피 이후에 나올일이 없기 때문에 is used는 수정하지 않아도 된다.
						findFlag = true;
						plug[j] = list[i];
						answer++;
						break;
					}
				}
				if (!findFlag) // 나중에 다 사용해야 하는 경우라면 현 시점에서 여기서 제일 나중에 써야 하는 것을 뽑는다.
				{
					int late_ix = -1;
					int slot_num = 0;
					for (int j = 0; j < n; j++)
					{
						int ix = find(list.begin() + i, list.end(), plug[j]) - (list.begin() + i);
						if (late_ix < ix)
						{
							late_ix = ix;
							slot_num = j;
						}
					}
					isused[plug[slot_num]] = false; // 원래 슬롯에 있던 물품은 이제 사용안하고 있다는 뜻으로 변경해준다.
					plug[slot_num] = list[i];
					answer++;
				}
			}
		}
	}
	cout << answer;

	return 0;
}
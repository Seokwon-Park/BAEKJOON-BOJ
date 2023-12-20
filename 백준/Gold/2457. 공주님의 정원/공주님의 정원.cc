#include <bits/stdc++.h>

using namespace std;

int month[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int answer = 0;

	int n;
	cin >> n;

	vector<pair<int, int>> flowers;

	int from = month[3] + 1;
	int to = month[11] + 30;

	for (int i = 0; i < n; i++)
	{
		int stmon, stday, edmon, edday;
		cin >> stmon >> stday >> edmon >> edday;
		int st = month[stmon] + stday;
		int ed = month[edmon] + edday;

		flowers.push_back({ st,ed });
	}

	sort(flowers.begin(), flowers.end(), [](pair<int, int> a, pair<int, int> b)
		{
			return a.first < b.first;
		});

	int stpt = from;
	int edpt = from;
	for (int i = 0; i < n; i++)
	{
		if (flowers[i].first <= stpt) // 3월 1일을 기준으로 끝나는 기간이 긴걸 찾음
		{
			if (flowers[i].second > edpt)
			{
				edpt = flowers[i].second; // 끝나는 기간을 업데이트함
				if (edpt > to)// 만약 근데 이게 11월 30일을 지났으면 더이상 볼 필요가 없음. 같아도 안됨 11월 30일에 지는 꽃이라는 소리라서
				{
					answer++;
					break;
				}
			}
		}
		else if (flowers[i].first > stpt) // 만약 3월1일보다 크게 시작하면 정렬해놓았기 때문에 다음 기간을 찾아야함..
		{
			if (flowers[i].first <= edpt) // 근데 first는 endpoint 보다는 짧거나 같아야 이어질 수 있음 (지는날 피면 이어짐)
			{
				stpt = edpt;
				answer++;
				if (flowers[i].second > edpt) //edpt 기준으로 더큰 값이면 저장해놓음.
				{
					edpt = flowers[i].second; // 끝나는 기간을 업데이트함
					if (edpt > to)
					{
						answer++;
						break;
					}
				}
			}
			else
			{
				break; //아니라면 무조건 꽃피는 기간이 끊긴다는 소리기 때문에 break;
			}
		}
	}

	if (edpt <= to) // edpt가 11월 30일을 못넘어? 넌나가라 ㅋㅋ
	{
		answer = 0;
	}

	cout << answer;


	return 0;
}
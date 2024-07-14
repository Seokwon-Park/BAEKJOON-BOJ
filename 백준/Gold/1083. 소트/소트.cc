#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

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

	int k;
	cin >> k;
	for (int i = 0; i < n; i++) // k번 스왑횟수 안에 i번 자리에 가져올 수 있는 가장 큰 수를 찾아보는 식으로 그리디하게
	{
		int loc = max_element(v.begin() + i, v.end()) - v.begin(); //가장 큰 수의 위치를 찾는다
		if (loc == i) continue; // 만약 i번째 값이 최대값이면 다음 번 값에 대해 찾아본다.

		if (loc - i <= k) // 필요한 스왑 횟수가 k번보다 작거나 같으면
		{
			for (int j = loc; j > i; j--) // i번 자리까지 스왑하면서 가져온다.
			{
				swap(v[j - 1], v[j]);
				k--;
			}
		}
		else // 만약 k번보다 크다면 여기서 k회 이내로 가져올 수 있는 최댓값을 구하는 것으로 종료할 수 있음.
		{
			int new_loc = max_element(v.begin() + i, v.begin() + i + k + 1) - v.begin(); 
			// i번 자리부터 i+k까지의 수 중 최댓값 인덱스을 찾는다.
			if (new_loc == i) continue; // 만약 i번째 값이 최댓값일 경우에는 다음 자리 값을 찾아본다.
			for (int j = new_loc; j > i; j--) // 해당값을 스왑하면서 가져온다.
			{
				swap(v[j - 1], v[j]);
				k--;
			}
		}
		if (k == 0)
			break; //반복문 끝냄.
	}

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}

	return 0;
}
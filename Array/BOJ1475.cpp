#include <bits/stdc++.h>

using namespace std;

int need[10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string room;
	cin >> room;
	for (char k : room)
		need[k - '0']++;

	int mx = 0;

	for (size_t i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)
		{
      //9와 6은 같은 수로 봄, 다만 2로 나눴을때 66999 같은 경우 2세트가 아니라 3세트가 필요하므로 2로 나눈 모듈러 연산 결과를 더해줌
			mx = max(mx, (need[6]+need[9]) / 2 + (need[6] + need[9]) % 2);     
		}
		else
		{
			mx = max(mx, need[i]);
		}
	}
				
	cout << mx;
	
	return 0;
}


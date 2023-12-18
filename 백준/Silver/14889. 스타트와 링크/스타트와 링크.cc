
#include <bits/stdc++.h>

int board[25][25];

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	vector<int> people(n);
	vector<int> pick(n, 1);
	vector<int> picktwo(n/2, 0);

	fill(picktwo.end() - 2, picktwo.end(), 1);

	fill(pick.begin(), pick.begin() + n / 2, 0);

	for (int i = 0; i < n; i++)
	{
		people[i] = i;
	}

	int min_val = INT_MAX;

	do {
		vector<int> start; //start팀
		vector<int> link;  //link팀
		int startsum = 0;  //start팀 능력치 합
		int linksum = 0;   //link팀 능력치 합
		for (int i = 0; i < n; i++)
		{
			if (pick[i] == 1)
				start.push_back(people[i]);
			if (pick[i] == 0)
				link.push_back(people[i]);
		}
		//팀 다뽑았음
		sort(start.begin(), start.end());
		sort(link.begin(), link.end());
		//next_permutation 쓰기위해 다시 정렬

		do {
			vector<int> s;
			vector<int> l;
			for (int j = 0; j < n / 2; j++)
			{
				if (picktwo[j] == 1)
				{
					s.push_back(start[j]);
					l.push_back(link[j]);
				}				
			}
			startsum += board[s[0]][s[1]] + board[s[1]][s[0]]; // Sij + Sji
			linksum += board[l[0]][l[1]] + board[l[1]][l[0]]; // Sij + Sji
		} while (next_permutation(picktwo.begin(), picktwo.end())); // 2팀 각각 2명씩 뽑아서 모든 조합에 대한 능력치 합을 구함
		int sub = abs(startsum - linksum); // 능력치 총합 차이
		if (min_val > sub)min_val = sub;
	} while (next_permutation(pick.begin(), pick.end()));// 반반 뽑기

	cout << min_val;

	return 0;
}
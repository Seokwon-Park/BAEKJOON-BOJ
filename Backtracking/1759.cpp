#include <bits/stdc++.h>

using namespace std;

int n, m, in;
char arr[15];
int isused[15];
vector<char> nums;
int chk1;
int chk2;

void check(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		chk1++;
	else
		chk2++;
}

void inv_check(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		chk1--;
	else
		chk2--;
}



//k는 수의 길이
void bt(int k)
{
	//base condition
	if (k == m)
	{
		if (chk1 >= 1 && chk2 >= 2) {
			//print
			for (int i = 0; i < m; i++) {
				cout << arr[i];
			}
			cout << '\n';
		}
		return;
	}
	//3 3
	//3 4 3 과 같은 입력이 들어온 경우
	//saved에 기존에 찾은 수열 (3 4 3)같은 값이 저장되어 있는데
	//4 3 ? 의 ? 에 들어갈 값을 찾는 과정에서 이미 saved에는 3이 들어가 있음
	//그래서 4 3 3 은 정상적인 결과이지만 출력이 x
	//따라서 해당 자리에 대해 처음 비교할때는 0으로 초기화 시키고 for문 내에서 다시 값을 설정해준다.
	for (int i = 0; i < n; i++)
	{
		if (!isused[i])
		{
			if (k > 0)
			{
				if (arr[k - 1] < nums[i])
				{
					check(nums[i]);
					arr[k] = nums[i];
					isused[i] = 1;
					bt(k + 1);
					inv_check(nums[i]);
					isused[i] = 0;
					
				}
			}
			else
			{
				check(nums[i]);
				arr[k] = nums[i];
				isused[i] = 1;
				bt(k + 1);
				inv_check(nums[i]);
				isused[i] = 0;
			}
		}			
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);				

	cin >> m >> n;
		
	nums.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	bt(0);
	cout << '\n';


	
	return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	stack<int> st;
	int ix = 1;

	for (int i = 0; i < n; i++)
	{
		int input;
		// stack에 들어있는 값이 있으면 입력 전에 먼저 비교해서 
		// 순서에 맞는 값은 stack에서 빼기
		while (!st.empty())
		{
			if (st.top() == ix)
			{
				ix++;
				st.pop();
			}
			else
			{
				break;
			}
		}
		cin >> input;
		// 만약 입력한 값이 순서대로가 아니면 stack으로 push
		if (input != ix)
		{
			st.push(input);
		}
		else
		{
			ix++;
		}
	}
	//만약 다 입력했는데 stack에 남은 값이 있으면 순서대로 되는지 검사
	while(!st.empty())
	{
		if (st.top() == ix)
		{
			ix++;
			st.pop();
		}
		else
		{
			cout << "Sad";
			return 0;
		}
	}

	cout << "Nice";

	return 0;
}
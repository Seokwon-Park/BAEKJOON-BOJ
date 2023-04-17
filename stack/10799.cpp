#include <bits/stdc++.h>

using namespace std;

int main()
{
	string instr;

	stack<int> s;
	int answer = 0;

	cin >> instr;

	for (int i = 0; i < instr.length(); i++)
	{
		if (instr[i] == '(')//일단 '('면 파이프로 판단
		{
			s.push(instr[i]);//stack에 푸쉬
		}
		else//instr[i] = ')'
		{
			//만약 현재 char의 바로 이전 값이 '('면 절단 레이저임"()"
			if (instr[i-1] == '(')
			{
				s.pop();//if(instr[i] == '('이면 파이프로 판단하고 push했기때문에 pop해줌
				answer += s.size();//pipe는 stack의 size만큼 '('가 들어가 있으므로
			}
			else//파이프가 끝난경우
			{
				s.pop();//파이프 한개 제거
				answer++;//자르고 남은 파이프를 더해줌
			}
		}
	}

	cout << answer;

	return 0;
}

#include <iostream>
#include <string>

using namespace std;

typedef struct node
{
	string sent1;
	string sent2;
	string sent3;
	string sent4;
	string sent5;
	string ans1;
	string ans2;
} 				node;

int n;

void	recursive(node *sent, int q_idx, int a_idx, string underline)
{
	if (q_idx < 0 && a_idx < 0)
		return ;
	if (q_idx >= 0)
	{
		cout << underline;
		cout << sent->sent2;
		q_idx--;
		if (q_idx < 0)
		{
			cout << underline;
			cout << sent->ans1;
		}
	}
	if (q_idx >= 0)
	{
		cout << underline << sent->sent3;
		cout << underline << sent->sent4;
		cout << underline << sent->sent5;
		underline += "____";
		recursive(sent, q_idx, a_idx, underline);
	}
	if (q_idx < 0 && a_idx >= 0)
	{
		cout << underline << sent->ans2;
		if ((int)underline.size() != 0)
			underline.erase(underline.begin(), underline.begin() + 4);
		a_idx--;
		recursive(sent, q_idx, a_idx, underline);
	}
}

int main(void)
{
	string underline = "";
	node sent;
	int q_idx, a_idx;
	cin >> n;
	q_idx = n;
	a_idx = n;
	sent.sent1 = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	sent.sent2 = "\"재귀함수가 뭔가요?\"\n";
	sent.sent3 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	sent.sent4 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	sent.sent5 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	sent.ans1 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	sent.ans2 = "라고 답변하였지.\n";
	cout << sent.sent1;
	recursive(&sent, q_idx, a_idx, underline);
}
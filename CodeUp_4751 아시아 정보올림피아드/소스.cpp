#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct _participant
{
	int country;
	int number;
	int score;
}participant;

bool compare(participant a, participant b)
{
	return a.score > b.score;
}
int main()
{
	int n;
	cin >> n;
	vector<participant> p(n);
	vector<int> medal(n, 0);
	for (auto& a : p)
		cin >> a.country >> a.number >> a.score;
	sort(p.begin(), p.end(), compare);
	for (int i = 0, cnt = 0; i < n && cnt < 3; i++)
	{
		if (medal[p[i].country]++ < 2)
		{
			cout << p[i].country << ' ' << p[i].number << endl;
			cnt++;
		}
	}
	return 0;
}
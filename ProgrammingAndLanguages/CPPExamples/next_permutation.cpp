#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p;
	for(int i = 0; i < n; ++i) {
		p.push_back(i);
	}

	vector<vector<int> > ps;
	//����ȫ����
	ps.push_back(p); //�ȱ��浱ǰ��һ�����з�ʽ 
	while(next_permutation(p.begin(), p.end())) {//�õ��µ����з�ʽ����������
		ps.push_back(p);
	}
	system("pause");
	return 0;
}

//��Ŀ����
//���� N ��С���ѣ�ÿ���˶����Լ����ݵ�һ��С���ѣ�Ҳ�������Լ�����
//
//��һ����Ϸ�У���ҪС������һ��Ȧ��ÿ��С���Ѷ����Լ����ݵ�С�������������ֱߡ�
//
//������������Ȧ�������ˣ�
//
//С���ѱ��Ϊ 1, 2, 3, ?N��
//
//��������
//�����һ�У�һ������ N��3 < N < 10 ^ 5����
//
//������һ�� N ���������ɿո�ֿ���
//
//�������
//Ҫ�����һ����������ʾ�������������Ȧ��������

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    // ���ڴ��������Ĵ���
    int n;
    cin >> n;
    vector<int> ans(1e5 + 1, 0);
    vector<int> st(1e5 + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ans[i];
    }
    int maxres = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i] == 1)continue;
        vector<int> temp;
        int j = i, cnt = 0;
        while (find(temp.begin(), temp.end(), j) == temp.end()) {
            temp.push_back(j);
            st[j] = 1;
            j = ans[j];
            cnt++;
        }
        maxres = max(maxres, cnt - (find(temp.begin(), temp.end(), j) - temp.begin()));
    }
    cout << maxres << endl;
    return 0;
}
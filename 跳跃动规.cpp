//题目描述
//小蓝在一个 n 行 m 列的方格图中玩一个游戏。
//
//开始时，小蓝站在方格图的左上角，即第 1 行第 1 列。
//
//小蓝可以在方格图上走动，走动时，如果当前在第 r 行第 c 列，他不能走到行号比 r 小的行，也不能走到列号比 c 小的列。同时，他一步走的直线距离不超过 3。
//
//例如，如果当前小蓝在第 3 行第 5 列，他下一步可以走到第 3 行第 6 列、第 3 行第 7 列、第 3 行第 8 列、第 4 行第 5 列、第 4 行第 6 列、第 4 行第 7 列、第 5 行第 5 列、第 5 行第 6 列、第 6 行第 5 列之一。
//
//小蓝最终要走到第 n 行第 m 列。
//
//在图中，有的位置有奖励，走上去即可获得，有的位置有惩罚，走上去就要接受惩罚。奖励和惩罚最终抽象成一个权值，奖励为正，惩罚为负。
//
//小蓝希望，从第 1 行第 1 列走到第 n 行第 m 列后，总的权值和最大。请问最大是多少？
//
//输入描述
//输入的第一行包含两个整数 n, m表示图的大小。
//
//接下来 n 行，每行 m 个整数，表示方格图中每个点的权值。
//
//输出描述
//输出一个整数，表示最大权值和。

#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int m, n;
    cin >> n >> m;
    int arr[100][100] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < m; q++) {
            int trans = INT_MIN;
            for (int i = 1; i <= 3; i++) {
                for (int j = 1; j <=i; j++) {
                    if (p - j >= 0 && q >= i - j)
                        trans = max( arr[p - j][q - i + j], trans);
                    if(q - j >= 0 && p >= i - j)
                        trans = max(arr[p - i + j][q - j], trans);

                }
            }
           if(trans!=INT_MIN) arr[p][q] += trans;
        }
    }
    cout << arr[n - 1][m - 1] << endl;
    return 0;
}
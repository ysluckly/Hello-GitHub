/*
问题描述：

    光明小学的小朋友们要举行一年一度的接力跑大赛了，但是小朋友们却遇到了一个难题：设计接力跑大赛的线路，你能帮助他们完成这项工作么？
    光明小学可以抽象成一张有N个节点的图，每两点间都有一条道路相连。光明小学的每个班都有M个学生，所以你要为他们设计出一条恰好经过M条边的路径。
    光明小学的小朋友们希望全盘考虑所有的因素，所以你需要把任意两点间经过M条边的最短路径的距离输出出来以供参考。
    你需要设计这样一个函数：
        res[][] Solve( N, M, map[][]);
    
    注意：map必然是N * N的二维数组，且map[i][j] == map[j][i]，map[i][i] == 0，-1e8 <= map[i][j] <= 1e8。（道路全部是无向边，无自环）2 <= N <= 100, 2 <= M <= 1e6。要求时间复杂度控制在O(N^3*log(M))。
    
        map数组表示了一张稠密图，其中任意两个不同节点i,j间都有一条边，边的长度为map[i][j]。N表示其中的节点数。
        你要返回的数组也必然是一个N * N的二维数组，表示从i出发走到j，经过M条边的最短路径
        你的路径中应考虑包含重复边的情况。
    样例：
        N = 3
        M = 2
        map = {
            {0, 2, 3},
            {2, 0, 1},
            {3, 1, 0}
        }

    输出结果result为：
        result = {
            {4, 4, 3},
            {4, 2, 5},
            {3, 5, 2}
        }
    样例解释：
        1->1有两种方法：1->2->1（长度为2+2=4），1->3->1（长度为3+3=6）
        2->2有两种方法：2->1->2（长度为2+2=4），2->3->2（长度为1+1=2）
        3->3有两种方法：3->1->3（长度为3+3=6），3->2->3（长度为1+1=2）
        1->2只有一个方法：1->3->2（长度为3+1=4）
        1->3只有一个方法：1->2->3（长度为2+1=3）
        2->3只有一个方法：2->1->3（长度为2+3=5）
        根据对称性可以得到其它部分的答案

    编译器版本: gcc 4.8.4
    请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
    时间限制: 3S (C/C++以外的语言为: 5 S)   内存限制: 128M (C/C++以外的语言为: 640 M)
    输入:
        输入范例 例如下面表示总共3个节点和：
        3    (表示N=3)
        2    (M=2)
        下面是N*N的矩阵（此处是一个3*3的矩阵）
        3 3
        0 2 3
        2 0 1
        3 1 0
    输出:
        输出是一个N*N的矩阵（此处根据输入得到是一个3*3的矩阵）
        4 4 3
        4 2 5
        3 5 2
    输入范例:
        3
        2
        3 3
        0 2 3
        2 0 1
        3 1 0
    输出范例:
        4 4 3
        4 2 5
        3 5 2

    代码运行完成！ 通过率80.00%
*/
#pragma once

#include<iostream>
#include<vector>

using namespace std;

void search(vector<vector<int>>& map, vector<vector<int>>& res, int m, int start, int end, int distance)
{
    if (m == 0) {
        if (distance < res[start][end]) {
            res[start][end] = distance;
            return;
        }
        return;
    }

    for (int i = 0; i < map.size(); i++) {
        if (map[end][i] != 0)
            search(map, res, m - 1, start, i, distance + map[end][i]);
    }
}

vector<vector<int>> solve(int n, int m, vector<vector<int>>& map) {
    vector<vector<int>> res(n, vector<int>(n, INT8_MAX));
    for (int i = 0; i < map.size(); i++)
        search(map, res, m, i, i, 0);

    return res;
}


int _main()
{
    int n, m, w, h;
    cin >> n;
    cin >> m;
    cin >> w >> h;  // == n
    vector<vector<int>> map(h, vector<int>(w, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
        }

    //vector<vector<int>> res(n, vector<int>(n, INT8_MAX));
    //for (int i = 0; i<data.size(); i++)
    //    search(data, res, m, i, i, 0);
    auto res = solve(n, m, map);

    for (auto s : res) {
        for (auto a : s)
            cout << a << ' ';
        cout << endl;
    }
    //for (int i = 0; i < res.size() - 1; i++) {
    //    for (int j = 0; j < res[i].size() - 1; j++)
    //        cout << res[i][j] << ' ';
    //    cout << res[i][res[i].size() - 1] << endl;
    //}
    //for (int j = 0; j < res[res.size() - 1].size() - 1; j++)
    //    cout << res[res.size() - 1][j] << ' ';
    //cout << res[res.size() - 1][res[res.size() - 1].size() - 1];
        
    return 0;
}


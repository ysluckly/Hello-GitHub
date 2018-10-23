#pragma once

/*
前缀表达式转后缀表达式（逆波兰式）

输入：
    1+((2+3)×4)-5

输出：
    1 2 3 + 4 * + 5 -

虽然网上有很多手工推算的说明，但是到写代码的时候才发现有很多坑

ref: 中、前、后缀表达式 - CSDN博客 https://blog.csdn.net/lin74love/article/details/65631935
这是个人认为说的很清楚的推算过程，但实现的时候还是遇到了很多问题

以下代码中有一些循环可能是多余的，如果字符串合法，应该只需要判断一次，而不需要循环处理（未验证）
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <set>
using namespace std;

//set<char> l1{ '+', '-' };
//set<char> l2{ '*', '/' };
//
//vector<set<char>> l{ l1, l2 };

int get_level(char c) {
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    //case '(':
    //    return 3;
    default:
        return -1;
    }
}

string infix2suffix(const string& s) {
    stack<char> tmp;        // 符号栈
    queue<string> ans;      // 必须使用 string 队列，因为可能存在多位数字
    //stringstream ret;       // 用字符流模拟队列

    bool num_flag = false;      // 用于判断数字的末尾 
                                //初始设为 false 是为了避免第一个字符是括号
    //int v = 0;            // 保存数值
    string v{ "" };         // 用字符串保存更好，这样还能支持字母形式的表达式
    for (auto c : s) {
        // 处理数字
        if (isalnum(c)) {           // 处理多位数字
            v.append(string(1, c)); // 注意，char 字符不能直接转 string
            num_flag = true;
        }
        else {
            if (num_flag) {     // 因为可能存在多位数字，所以数字需要等遇到第一个非数字字符才入队
                ans.push(v);
                //ret << v << ' ';
                v.clear();
                num_flag = false;
            }

            // 处理运算符的过程
            if (c == ')') {  // 如果遇到右括号，则依次弹出栈顶符号，直到遇到**第一个**左括号并弹出（坑点 1：可能存在连续的左括号）
                while (!tmp.empty()) {
                    if (tmp.top() == '(') {
                        tmp.pop();
                        break;
                    }
                    ans.push(string(1, tmp.top()));
                    //ret << tmp.top() << ' ';
                    tmp.pop();
                }
            } // 注意这两个判断的顺序（坑点 2：右括号是始终不用入栈的，所以应该先处理右括号）
            else if (tmp.empty() || tmp.top() == '(' || c == '(') {  // 如果符号栈为空，或栈顶为 ')'，或遇到左括号
                tmp.push(c);                                         // 则将该运算符入栈
            }
            else {
                while (!tmp.empty() && get_level(tmp.top()) >= get_level(c)) {  // 如果栈顶元素的优先级大于等于当前运算符，则弹出
                    if (tmp.top() == '(')  // （坑点 3：左括号的优先级是大于普通运算符的，但它不应该在这里弹出）
                        break;
                    ans.push(string(1, tmp.top()));
                    //ret << tmp.top() << ' ';
                    tmp.pop();
                }
                tmp.push(c);
            }
        }
    }

    if (num_flag) {             // 表达式的最后一个数字入栈
        ans.push(v);
        //ret << v << ' ';
    }

    while (!tmp.empty()) {      // 字符串处理完后，依次弹出栈中的运算符
        if (tmp.top() == '(')   // 这个判断好像是多余的
            tmp.pop();
        ans.push(string(1, tmp.top()));
        //ret << tmp.top() << ' ';
        tmp.pop();
    }

    //return ret.str();

    stringstream ret;
    while (!ans.empty()) {
        ret << ans.front() << ' ';
        ans.pop();
    }
    return ret.str();
}

void solve() {
    // 只测试了以下样例，如果有反例请告诉我

    cout << infix2suffix("12+(((23)+3)*4)-5") << endl;  // 12 23 3 + 4 * + 5 -
    cout << infix2suffix("1+1+1") << endl;              // 1 1 + 1 +
    cout << infix2suffix("(1+1+1)") << endl;            // 1 1 + 1 +
    cout << infix2suffix("(1+(1+1))") << endl;          // 1 1 1 + +
    cout << infix2suffix("1+(2-3)*4+10/5") << endl;     // 1 2 3 - 4 * + 10 5 / +
    cout << infix2suffix("az-(b+c/d)*e") << endl;       // az b c d / + e * -
}
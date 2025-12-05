//
// Created by lspic on 2025/12/5.
//
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstring>
#include <iostream>
using namespace std;

// 将月份(mmm)转换为数字(1-12)
int monthStringToInt(const char mmm[]) {
    char m[4];
    int i = 0;

    for (i = 0; i <= 3; i++) {
        char c = mmm[i];

        if (c == '\0') { // 确保以 '\0' 结尾
            m[i] = '\0';
            break;
        }

        if (c >= 'A' && c <= 'Z') {
            c = (char) (c - 'A' + 'a');
            // char类型在参加表达式运算时会自动提升为int，尽管最终运算结果不会超出char的范围，将表达式强制转换为char仍然是好习惯。
        }

        m[i] = c;
    }
    m[i] = '\0'; // 确保以 '\0' 结尾

    if (strcmp(m, "jan") == 0)
        return 1;
    if (strcmp(m, "feb") == 0)
        return 2;
    if (strcmp(m, "mar") == 0)
        return 3;
    if (strcmp(m, "apr") == 0)
        return 4;
    if (strcmp(m, "may") == 0)
        return 5;
    if (strcmp(m, "jun") == 0)
        return 6;
    if (strcmp(m, "jul") == 0)
        return 7;
    if (strcmp(m, "aug") == 0)
        return 8;
    if (strcmp(m, "sep") == 0)
        return 9;
    if (strcmp(m, "oct") == 0)
        return 10;
    if (strcmp(m, "nov") == 0)
        return 11;
    if (strcmp(m, "dec") == 0)
        return 12;

    return -1; // 错误月份
}


// 按题目要求实现 getDate
void getDate(int &dd, int &mm, int &yy) {
    char dateString[30];
    char mmm[10];
    int i = 0;

    cout << "请输入日期 (dd-mmm-yy): ";

    cin >> dateString;

    // ============ 解析日dd ================
    dd = 0;
    if (dateString[i] < '0' || dateString[i] > '9') {
        cout << "格式错误，应以数字开头（dd-mmm-yy）\n";
        return;
    }
    while (dateString[i] >= '0' && dateString[i] <= '9') {
        dd = dd * 10 + dateString[i] - '0';
        ++i;
    }

    if (dateString[i] != '-') {
        cout << "格式错误，缺少第一个 '-'（dd-mmm-yy）\n";
        return;
    }
    ++i;

    // ============ 解析月mmm ================
    int j = 0;
    if (dateString[i] == '-' || dateString[i] == '\0') {
        cout << "格式错误，月份缩写缺失\n";
        return;
    }
    while (dateString[i] != '-' && dateString[i] != '\0' && j < 9) {
        mmm[j++] = dateString[i++];
    }
    mmm[j] = '\0';

    if (dateString[i] != '-') {
        cout << "格式错误，缺少第二个 '-'（dd-mmm-yy）\n";
        return;
    }
    ++i;

    // ============ 解析年yy ================
    yy = 0;
    if (dateString[i] < '0' || dateString[i] > '9') {
        cout << "格式错误，年份部分应为数字\n";
        return;
    }
    while (dateString[i] >= '0' && dateString[i] <= '9') {
        yy = yy * 10 + dateString[i] - '0';
        ++i;
    }

    // ============ 转换月份 ================
    mm = monthStringToInt(mmm);

    if (mm == -1) {
        cout << "月份缩写错误，应为 Jan, Feb, Mar ...\n";
        return;
    }
    cout << "转换结果: 日 = " << dd << ", 月 = " << mm << ", 年 = " << yy << endl;
}


int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int dd = 0, mm = 0, yy = 0;

    getDate(dd, mm, yy);

    return 0;
}

/*
 *
 * 简单写法：
 * #include<cstdio>
 * if (sscanf(dateString, "%d-%9s-%d", &dd, mmm, &yy) != 3) {
 * cout << "格式错误，应为 dd-mmm-yy\n";
 * return;
 * }
 *
*/

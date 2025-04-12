#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    double pi;
    // scanfによる入力
    printf("2つの数値を空白区切りで入力してEnterボタンを押してください\n");
    scanf("x = %d, pi = %lf", &x, &pi);
    // ↑ こんなふうに書くと，「x = 12345, pi = 3.141593」と
    //   入力しなければならない
    
    printf("x = %d, pi = %lf\n", x, pi);

    printf("文字列を入力してEnterボタンを押してください\n");
 
    double d;
    scanf("%lf", &d);
 
    printf("入力された数値は：%lf\n", d);
 
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[9][9];
	int b[9];
	bool flag=true;
	for(int i=0;i<9;i++)for(int j=0;j<9;j++)cin>>a[i][j];
    // 各行について調査
	for(int i=0;i<9;i++){
        for(int k=0;k<9;k++)b[k]=0; // 1-9 すべての数字がそれぞれ1回ずつ現れるかの確認用
		for(int j=0;j<9;j++)b[a[i][j]-1]++; // 現れた数字-1 (a[i][j]-1) を添字として，それに対応した b の要素をインクリメント
		for(int k=0;k<9;k++)if(b[k]!=1)flag=false; // 現れた数字に対応した b の要素は1になっている
                                                   // (1度だけインクリメントされるため)
	}
    // 各列について調査
    for(int j=0;j<9;j++){
        for(int k=0;k<9;k++)b[k]=0; // 1-9 すべての数字がそれぞれ1回ずつ現れるかの確認用
		for(int i=0;i<9;i++)b[a[i][j]-1]++; // 現れた数字-1 (a[i][j]-1) を添字として，それに対応した b の要素をインクリメント
		for(int k=0;k<9;k++)if(b[k]!=1)flag=false; // 現れた数字に対応した b の要素は1になっている
                                                   // (1度だけインクリメントされるため)
    }
    // 各 3×3 について調査
	for(int i=0;i<9;i+=3){
		for(int j=0;j<9;j+=3){
			for(int k=0;k<9;k++)b[k]=0; // 1-9 すべての数字がそれぞれ1回ずつ現れるかの確認用
			for(int ii=0;ii<3;ii++){
				for(int jj=0;jj<3;jj++){
					b[a[i+ii][j+jj]-1]++; // 現れた数字-1 (a[i][j]-1) を添字として，それに対応した b の要素をインクリメント
				}
			}
			for(int k=0;k<9;k++)if(b[k]!=1)flag=false; // 現れた数字に対応した b の要素は1になっている
                                                       // (1度だけインクリメントされるため)
		}
	}
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

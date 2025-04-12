#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// bool isTd_fromS(int Td, vector<int> S(N));

int main() {
  int N;
  string Td;
  cin >> N >> Td;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  
  vector<int> ind;
  
  // すべてのSについて調べる
  for (int i = 0; i < N; i++) {
    
    // 文字数が同じ場合 → ケース1,4について調査
    if (Td.size() == S.at(i).size()) {
      // cout << "文字数が同じです．ケース1,4について調査します" << endl;
      int count = 0;
      for (int j = 0; j < Td.size(); j++) {
        if (Td.at(j) != S.at(i).at(j)) {
          count++;
        }
      }
      if (count == 0 || count == 1) {
        // S.at(i)がTと等しい可能性がある
        ind.push_back(i);
      }
    }
    
    // Sが1文字少ない場合 → ケース3について調査
    else if (Td.size() == S.at(i).size() + 1) {
      // cout << S.at(i) << "は" << Td << "よりも1文字少ないです．ケース3について調査します" << endl;
      // 不一致(それが挿入した文字かも)ならそれ以降はSにおいて1つ先を比較
      int a = 0;
      int count = 0;
      // for (int j = 0; j < S.at(i).size(); j++) {
      for (int j = 0; j < Td.size(); j++) {
        if (j == S.at(i).size()) continue;
        if (a == 0) {
          // 不一致以前
          if (Td.at(j) != S.at(i).at(j)) {
            // cout << "1度目の不一致が発生" << endl;
            a++;
          }
        }
        else {
          // 不一致以降
          if (Td.at(j) != S.at(i).at(j-1)) {
            // cout << Td.at(j) << "!=" << S.at(i).at(j-1) << ": ";
            // cout << a + count + 1 << "度目の不一致が発生" << endl;
            count++;
          }
        }
      }
      if (count == 0) {
        // S.at(i)がTと等しい可能性がある
        ind.push_back(i);
      }
    }
    // Sが1文字多い場合 → ケース2について調査
    else if (Td.size() == S.at(i).size() - 1) {
      // cout << S.at(i) << "は" << Td << "よりも1文字多いです．ケース2について調査します" << endl;
      //不一致(それが挿入した文字かも)ならそれ以降はSにおいて1つ前を比較
      int a = 0;
      int count = 0;
      // for (int j = 0; j < Td.size(); j++) {
      for (int j = 0; j < S.at(i).size(); j++) {
        // if (j == Td.size()) break;
        if (a == 0) {
          // 不一致以前
          if (Td.at(j) != S.at(i).at(j)) {
            // cout << "1度目の不一致が発生" << endl;
            a++;
          }
        }
        else {
          // 不一致以降
          if (Td.at(j-1) != S.at(i).at(j)) {
            // cout << Td.at(j-1) << "!=" << S.at(i).at(j) << ": ";
            // cout << a + count + 1 << "度目の不一致が発生" << endl;
            count++;
          }
        }
      }
      if (count == 0) {
        // S.at(i)がTと等しい可能性がある
        ind.push_back(i);
      }
    }
    
  } // iについてのforここまで
  
  
  cout << ind.size() << endl;  
  for (int i = 0; i < ind.size(); i++) {
    cout << ind.at(i) + 1;
    if (i != ind.size()-1) cout << " ";
    else cout << endl;
  }
  return 0;
}

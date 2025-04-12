// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int H, W;
//     cin >> H >> W;
//     vector<string> grid(H);
    
//     // 入力を受け取る
//     for (int i = 0; i < H; i++) {
//         cin >> grid[i];
//     }
    
//     vector<vector<int>> sensors(H, vector<int>(W, 0));

//     vector<vector<int>> memo(H, vector<int>(W, 0));
    
//     // 各マスにおけるセンサの個数を計算
//     for (int i = 0; i < H; i++) {
//         for (int j = 0; j < W; j++) {
//             if (grid[i][j] == '#'/* && uncheked memo[i][j] == 0 */) {
//                 for (int dx = -1; dx <= 1; dx++) {
//                     for (int dy = -1; dy <= 1; dy++) {
//                         int ni = i + dx;
//                         int nj = j + dy;
//                         if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
//                             sensors[ni][nj]++;
//                         }
//                     }
//                 }
//             }
//         }
//     }
    
//     // 各マスにおけるセンサの個数を出力
//     // for (int i = 0; i < H; i++) {
//     //     for (int j = 0; j < W; j++) {
//     //         cout << sensors[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     int max_grid;

//     for (int i = 0; i < H; i++) {
//         for (int j = 0; j < W; j++) {
//             max_grid = max(max_grid, sensors[i][j]);
//         }
//     }

//     cout << max_grid << endl;
    
//     return 0;
// }

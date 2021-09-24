#include <iostream>

using namespace std;

bool isBishopCanKillPawn(string bishop, string pawn)
{
    return (abs(bishop[0] - pawn[0]) == abs(bishop[1] - pawn[1]) && bishop[0] - pawn[0] != 0);
}

// Cho 1 ma trận n * n
// Đường chéo chính là đường chéo đi từ ô (1, 1) đến ô (n, n), bao gồm các ô có dạng A[i][i] (i = 1 .. n)
// Đường chéo phụ là đường chéo đi từ ô (1, n) đến ô (n, 1), bao gồm các ô có dạng A[i][n + 1 - i] (i = 1 .. n)
/* 2 ô và nằm trên cùng 1 đường chéo khi và chỉ khi chúng có tổng tọa độ hoặc hiệu tọa độ bằng nhau */
// Tức là, 2 ô (x, y) và (u, v) cùng đường chéo <=> x + y = u + v hoặc x - y = u - v
// Hình ảnh minh họa
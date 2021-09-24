#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Hãy tìm đỉnh mà từ đỉnh đó có thể đi tới tất cả các đỉnh khác
// Đầu vào luôn đảm bảo chỉ tồn tại duy nhất 1 đỉnh như vậy.

// -- có thể sử dụng bfs từ bài trước, nhưng thuật toán này cool ngầu hơn

int beautifulVertex(int n, vector<vector<int>> edges)
{
    vector<bool> v(n, 0);
    for (auto vi : edges)
        v[vi[1]] = 1;
    for (int i = 1; i <= n; i++)
        if (v[i] == 0)
            return i;
}

int main(){

    return 0;
}
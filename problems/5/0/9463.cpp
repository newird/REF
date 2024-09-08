#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, d;
    std::cin >> n >> m >> d;
    
    std::vector<int> happiness(n);
    for (int i = 0; i < n; i++) {
        std::cin >> happiness[i];
    }
    
    // 创建一个大小为 n 的数组，用于存储每一天的最大幸福值
    std::vector<int> maxHappiness(n);
    
    // 初始化第一天的最大幸福值为第一部电影的幸福值
    maxHappiness[0] = happiness[0];
    
    for (int i = 1; i < n; i++) {
        int maxPrevHappiness = 0;
        
        // 计算 gap
        int gap = i - m;
        if (gap < 0) {
            gap = 0;
        }
        
        // 计算前 m 天的最大幸福值
        for (int j = i - 1; j >= gap; j--) {
            int prevHappiness = maxHappiness[j] - d * (i - j - 1);
            maxPrevHappiness = std::max(maxPrevHappiness, prevHappiness);
        }
        
        // 当前天的最大幸福值为前 m 天最大幸福值加上当前电影的幸福值
        maxHappiness[i] = maxPrevHappiness + happiness[i];
    }
    
    // 找到 n 天中的最大幸福值
    int maxTotalHappiness = *std::max_element(maxHappiness.begin(), maxHappiness.end());
    
    std::cout << maxTotalHappiness << std::endl;
    
    return 0;
}
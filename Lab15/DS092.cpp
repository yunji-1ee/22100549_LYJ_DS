#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// K번째로 큰 수를 찾는 함수
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap; // 최대 힙 선언

    // 모든 숫자를 최대 힙에 추가
    for (int num : nums) {
        maxHeap.push(num);
    }

    // 최대 힙에서 K번째로 큰 수 찾기
    for (int i = 1; i < k; ++i) {
        maxHeap.pop();
    }

    return maxHeap.top();
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = findKthLargest(nums, k);
    cout << result << endl;

    return 0;
}

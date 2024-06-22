#include <iostream>
#include <vector>

int findMajorityElement(const std::vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;


    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            candidate = nums[i];
            count = 1;
        }
    }


    count = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    int size;
    std::cin >> size;

    std::vector<int> nums(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> nums[i];
    }

    int majorityElement = findMajorityElement(nums);
    std::cout << majorityElement << std::endl;

    return 0;
}

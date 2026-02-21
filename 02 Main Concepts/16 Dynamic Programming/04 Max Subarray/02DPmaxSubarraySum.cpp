#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    vector<int> sum(nums.size());
    sum[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (sum[i - 1] < 0)
        {
            sum[i] = nums[i];
        }
        else
        {
            sum[i] = sum[i - 1] + nums[i];
        }
    }

    int maxVal = sum[0];
    for (int i = 0; i < sum.size(); i++)
    {
        if (sum[i] > maxVal)
            maxVal = sum[i];
    }

    return maxVal;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);

    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}

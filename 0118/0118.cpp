class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<int> arr;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = i - 2; j >= 0; j--)
            {
                arr[j + 1] = arr[j] + arr[j + 1];
            }
            arr.emplace_back(1);
            result.emplace_back(arr);
        }
        return result;
    }
};
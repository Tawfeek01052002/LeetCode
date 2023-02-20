class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = arr.size() - 1;
    int endingCol = arr[0].size() - 1;
    int count = 0;
    int total_element = arr[0].size() * arr.size();
    while (count < total_element)
    {
        // Printing starting row
        for (int j = startingCol; j <= endingCol && count<total_element; j++)
        {
            ans.push_back(arr[startingRow][j]);
            count++;
        }
        startingRow++;
        // Printing ending col
        for (int j = startingRow; j <= endingRow && count<total_element; j++)
        {
            ans.push_back(arr[j][endingCol]);
            count++;
        }
        endingCol--;

        // Printing ending row
        for (int j = endingCol; j >= startingCol && count<total_element; j--)
        {
            ans.push_back(arr[endingRow][j]);
            count++;
        }
        endingRow--;

        // Printing starting col
        for (int j = endingRow; j >= startingRow && count<total_element; j--)
        {
            ans.push_back(arr[j][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;   
    }
};
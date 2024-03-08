class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::unordered_map<int, int> frequencyMap;

        // count the frequency of each number.
        for (int num : nums) {
            ++frequencyMap[num];
        }

        int maximumFrequency = 0;

        // Find the maximum Frequency.
        for (const auto& pair : frequencyMap) {
            maximumFrequency = std::max(maximumFrequency, pair.second);
        }

        int countOfMaxFrequency = 0;

        // Count the elements with maximum Frequnecy
        for (const auto& pair : frequencyMap) {
            if (pair.second == maximumFrequency) {
                countOfMaxFrequency += pair.second;
            }
        }

        return countOfMaxFrequency;
    }
};
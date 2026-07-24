class Solution {
public:
    struct Info {
        int firstIdx;
        int secondIdx;
        int thirdIdx;
        int count;
        int best;
    };

    int minimumDistance(vector<int>& nums) {
        unordered_map<int, Info> mp;

        for (int i = 0; i < nums.size(); i++) {

            if (!mp.count(nums[i])) {
                mp[nums[i]].firstIdx = i;
                mp[nums[i]].count = 1;
            }

            else if (mp[nums[i]].count == 1) {
                mp[nums[i]].secondIdx = i;
                mp[nums[i]].count = 2;
            }

            else if (mp[nums[i]].count == 2) {
                mp[nums[i]].thirdIdx = i;
                mp[nums[i]].count = 3;

                mp[nums[i]].best =
                    abs(mp[nums[i]].firstIdx - mp[nums[i]].secondIdx) +
                    abs(mp[nums[i]].secondIdx - mp[nums[i]].thirdIdx) +
                    abs(mp[nums[i]].thirdIdx - mp[nums[i]].firstIdx);
            }

            else {
                // Shift the last three occurrences
                mp[nums[i]].firstIdx = mp[nums[i]].secondIdx;
                mp[nums[i]].secondIdx = mp[nums[i]].thirdIdx;
                mp[nums[i]].thirdIdx = i;

                int curr =
                    abs(mp[nums[i]].firstIdx - mp[nums[i]].secondIdx) +
                    abs(mp[nums[i]].secondIdx - mp[nums[i]].thirdIdx) +
                    abs(mp[nums[i]].thirdIdx - mp[nums[i]].firstIdx);

                mp[nums[i]].best = min(mp[nums[i]].best, curr);
            }
        }

        int ans = INT_MAX;

        for (auto &it : mp) {
            if (it.second.count == 3)
                ans = min(ans, it.second.best);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
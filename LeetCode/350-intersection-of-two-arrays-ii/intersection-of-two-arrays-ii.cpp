class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result_vec;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();
        while (iter1 < nums1.end() && iter2 < nums2.end()) {
            if (*iter1 == *iter2) {
                result_vec.push_back(*iter1);
                iter1++;
                iter2++;
            } else if (*iter1 < *iter2) {
                iter1++;
            } else {
                iter2++;
            }
        }
        return result_vec;
    }
};
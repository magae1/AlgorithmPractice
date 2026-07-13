class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        String nums = "123456789";
        List<Integer> ans = new ArrayList<>();

        for (int l = 0; l < nums.length(); l++) {
            for (int r = l + 1; r <= nums.length(); r++) {
                String sub = nums.substring(l, r);
                int s = Integer.valueOf(sub);
                if (low <= s && s <= high) {
                    ans.add(s);
                }
            }
        }

        Collections.sort(ans);

        return ans;
    }
}

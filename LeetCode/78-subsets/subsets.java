class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>((int) Math.pow(2, nums.length));
        result.add(List.of());
        for (int i = 0; i < nums.length; i++) {
            int len = result.size();
            for (int j = 0; j < len; j++) {
                List<Integer> subList = new ArrayList<>(result.get(j));
                subList.add(nums[i]);
                result.add(subList);
            }
        }
        return result;
    }
}
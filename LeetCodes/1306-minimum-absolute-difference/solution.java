import java.util.*;

class Solution {
    private static final int MAX_VALUE = 1000000;

    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int n = arr.length;
        
        Arrays.sort(arr);
        List<List<Integer>> result = new ArrayList<>();
        int minDiff = 2 * MAX_VALUE;
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            int a = arr[i];
            int b = arr[j];
            int diff = b - a;
            if (diff < minDiff) {
                result.clear();
                minDiff = diff;
            }

            if (diff == minDiff) {
                result.add(List.of(a, b));
            }
        }

        return result;
    }
}

import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if (a[0] == b[0]) {
                    return b[1] - a[1];
                }
                return a[0] - b[0];
            }
        });

        int count = 0;
        for (int i = 0; i < intervals.length; i++) {
            count += 1;
            int l = intervals[i][0];
            int r = intervals[i][1];

            for (int j = i + 1; j < intervals.length; ) {
                if (l <= intervals[j][0] && intervals[j][1] <= r) {
                    i = j;
                    j++;
                    continue;
                }
                break;
            }
        }

        return count;
    }
}

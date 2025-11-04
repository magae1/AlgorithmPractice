class Solution {
    private Map<Integer, Integer> countMap = new HashMap<>();
    private Queue<Integer> qu = new LinkedList<>();

    public int[] findXSum(int[] nums, int k, int x) {
        int [] result = new int[nums.length - k + 1];

        int i = 0;
        for (; i < k - 1; i++) {
            Integer n = Integer.valueOf(nums[i]);
            qu.add(n);
            increaseCount(n);
        }

        int r = 0;
        while (i < nums.length) {     
            Integer n = Integer.valueOf(nums[i]);
            qu.add(n);
            increaseCount(n);

            List<Map.Entry<Integer, Integer>> countEntries = new ArrayList<>(countMap.entrySet());
            Collections.sort(countEntries, (e1, e2) ->  {
                int compVal = e2.getValue().compareTo(e1.getValue());
                if (compVal == 0) {
                    return e2.getKey().compareTo(e1.getKey());
                } else {
                    return compVal;
                }
            });

            int sum = 0;
            for (int c = 0; c < x && c < countEntries.size(); c++) {
                Map.Entry<Integer, Integer> countEntry = countEntries.get(c);
                sum += countEntry.getValue() * countEntry.getKey();
            }

            result[r] = sum;
            Integer f = qu.poll();
            decreaseCount(f);
            i++;
            r++;
        }

        return result;
    }

    private void increaseCount(Integer n) {
        if (countMap.containsKey(n)) {
            Integer c = countMap.get(n);
            countMap.put(n, c + 1);
        } else {
            countMap.put(n, 1);
        }
    }

    private void decreaseCount(Integer n) {
        Integer c = countMap.get(n);
        if (c == 1) {
            countMap.remove(n);
        } else {
            countMap.put(n, c - 1);
        }
    }
}
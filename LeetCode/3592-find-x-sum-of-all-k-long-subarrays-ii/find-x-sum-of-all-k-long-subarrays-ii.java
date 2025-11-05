class Solution {
    private final SortedSet<Number> includedSet = new TreeSet<>((n1, n2) -> {
        if (n1.count == n2.count) {
            return n2.n - n1.n;
        }
        return n2.count - n1.count;
    });
    private final SortedSet<Number> excludedSet = new TreeSet<>((n1, n2) -> {
        if (n1.count == n2.count) {
            return n2.n - n1.n;
        }
        return n2.count - n1.count;
    });
    private final Map<Integer, Integer> countMap = new HashMap<>();

    public long[] findXSum(int[] nums, int k, int x) {
        long[] result = new long[nums.length - k + 1];

        int r = 0;
        int l = 0;
        long subSum = 0;
        for (; r < k - 1; r++) {
            int n = nums[r];
            int count = increaseCount(Integer.valueOf(n));
            
            if (excludedSet.contains(new Number(n, count - 1))) {
                excludedSet.remove(new Number(n, count - 1));
                excludedSet.add(new Number(n, count));
            } else {
                excludedSet.add(new Number(n, count));
            }
        }
        
        for (int i = 0; i < x && !excludedSet.isEmpty(); i++) {
            Number firstNum = excludedSet.first();
            excludedSet.remove(firstNum);
            includedSet.add(firstNum);
            subSum += (long) firstNum.n * (long) firstNum.count;
        }

        while (r < nums.length) {
            int n = nums[r];
            int count = increaseCount(Integer.valueOf(n));
            Number prevNum = new Number(n, count - 1);
            if (includedSet.remove(prevNum)) {
                includedSet.add(new Number(n, count));
                subSum += (long) n;
            } else {
                if (includedSet.size() < x) {
                    includedSet.add(new Number(n, count));
                    subSum += (long) n;
                } else {
                    if (excludedSet.remove(prevNum)) {
                        excludedSet.add(new Number(n, count));
                    } else {
                        excludedSet.add(new Number(n, count));
                    }
                    subSum = switchIfNeed(subSum);
                }
            }

            result[l] = subSum;

            n = nums[l];
            count = decreaseCount(Integer.valueOf(n));
            prevNum = new Number(n, count + 1);

            if (excludedSet.remove(prevNum)) {
                excludedSet.add(new Number(n, count));
            } else if (includedSet.remove(prevNum)) {
                includedSet.add(new Number(n, count));
                subSum -= (long) n;
                subSum = switchIfNeed(subSum);
            }
          
            r++;
            l++;
        }

        return result;
    }

    private long switchIfNeed(long subSum) {
        if (!excludedSet.isEmpty() && !includedSet.isEmpty()) {
            boolean isSwitching = false;
            Number firstExNumber = excludedSet.first();
            Number lastInNumber = includedSet.last();

            if (firstExNumber.count > lastInNumber.count) {
                isSwitching = true;
            } else if (firstExNumber.count == lastInNumber.count) {
                if (firstExNumber.n > lastInNumber.n) {
                    isSwitching = true;
                }
            }

            if (isSwitching) {
                excludedSet.remove(firstExNumber);
                includedSet.add(firstExNumber);
                subSum += (long) firstExNumber.n * (long) firstExNumber.count;

                includedSet.remove(lastInNumber);
                excludedSet.add(lastInNumber);
                subSum -= (long) lastInNumber.n * (long) lastInNumber.count;
            }
        } 
        return subSum;
    }

    private int increaseCount(Integer n) {
        if (countMap.containsKey(n)) {
            Integer count = countMap.get(n) + 1;
            countMap.put(n, count);
            return count;
        } else {
            countMap.put(n, 1);
            return 1;
        }
    }

    private int decreaseCount(Integer n) {
        Integer c = countMap.get(n);
        if (c == 1) {
            countMap.remove(n);
            return 0;
        } else {
            int count = c - 1;
            countMap.put(n, Integer.valueOf(count));
            return count;
        }
    }

    class Number {
        public final int n;
        public final int count;

        public Number(int n) {
            this.n = n;
            this.count = 1;
        }

        public Number(int n, int c) {
            this.n = n;
            this.count = c;
        }
    }
}

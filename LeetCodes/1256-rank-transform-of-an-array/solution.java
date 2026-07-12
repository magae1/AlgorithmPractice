class Solution {

    class Element {
        public final int seq;
        private final int num;

        public Element(int seq, int num) {
            this.seq = seq;
            this.num = num;
        }
    }

    public int[] arrayRankTransform(int[] arr) {
        List<Element> list = new ArrayList<>();
        int n = arr.length;
        int prev = Integer.MAX_VALUE;
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            list.add(new Element(i, num));
            prev = Math.min(prev, num);
        }
        list.sort((a, b) -> {
            return a.num - b.num;
        });

        int rank = 1;
        for (Element e : list) {
            if (e.num != prev) {
                rank++;
                prev = e.num;
            }
            answer[e.seq] = rank;
        }

        return answer;
    }
}

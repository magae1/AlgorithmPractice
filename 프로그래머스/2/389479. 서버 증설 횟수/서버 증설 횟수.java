class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int numOfCurrentServers = 0;
        int[] numOfIncreasedServers = new int[players.length];
        int frontIdx = 0, backIdx = 0;
        while(backIdx < k) {
            int numOfRequiredServers = players[backIdx] / m;
            int addedServers = Math.max(0, numOfRequiredServers - numOfCurrentServers);
            numOfCurrentServers += addedServers;
            answer += addedServers;
            numOfIncreasedServers[backIdx] = addedServers;
            backIdx++;
        }
        
        
        while (backIdx < players.length) {
            int numOfRequiredServers = players[backIdx] / m;
            numOfCurrentServers -= numOfIncreasedServers[frontIdx];
            int addedServers = Math.max(0, numOfRequiredServers - numOfCurrentServers);
            numOfCurrentServers += addedServers;
            numOfIncreasedServers[backIdx] = addedServers;
            answer += addedServers;
            frontIdx++;
            backIdx++;
        }
        
        return answer;
    }
}
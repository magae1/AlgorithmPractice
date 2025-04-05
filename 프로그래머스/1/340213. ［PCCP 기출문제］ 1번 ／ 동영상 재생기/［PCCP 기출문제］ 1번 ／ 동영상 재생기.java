class Solution {
    private static final String NEXT = "next";
    private static final String PREV = "prev";
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        int c = 0;
        int videoLenSec = getSeconds(video_len);
        int opStartSec = getSeconds(op_start);
        int opEndSec = getSeconds(op_end);
        int curSec = getSeconds(pos);
        while (true) {
            if (curSec >= opStartSec && curSec <= opEndSec) {
                curSec = opEndSec;
            }
            
            if (c >= commands.length) {
                break;
            }
            
            if (commands[c].equals(NEXT)) {
                curSec += 10;   
            } else {
                curSec -= 10;
            }
            
            curSec = Math.max(0, curSec);
            curSec = Math.min(videoLenSec, curSec);
            c++;
        }
    
        return String.format("%02d:%02d", curSec / 60, curSec % 60);
    }
    
    private int getSeconds(String time) {
        String[] sp = time.split(":");
        return Integer.parseInt(sp[0]) * 60 + Integer.parseInt(sp[1]);
    }
}
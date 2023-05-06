class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        dig_logs: List[str] = []
        let_logs: List[str] = []
        for log in logs:
            fst_content = log.split(sep=' ')[1]
            if fst_content.isdigit():
                dig_logs.append(log)
            else:
                let_logs.append(log)
            
        let_logs.sort(key=lambda x: (x.split(sep=' ')[1:], x.split(sep=' ')[0]))
            
        return let_logs + dig_logs

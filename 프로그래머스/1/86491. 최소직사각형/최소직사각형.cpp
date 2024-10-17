#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = 0;
    int height = 0;
    
    for (vector<int>& size : sizes) {
        int fst_w = max(size[0], width);
        int fst_h = max(size[1], height);
        if (fst_w <= width && fst_h <= height) continue;
        
        int sec_w = max(size[1], width);
        int sec_h = max(size[0], height);
        if (sec_w <= width && sec_h <= height) continue;
        
        int fst_area = fst_w * fst_h;
        int sec_area = sec_w * sec_h;
        
        if (fst_area < sec_area) {
            width = max(width, fst_w);
            height = max(height, fst_h);
        } else {
            width = max(width, sec_w);
            height = max(height, sec_h);
        }
    }
    
    return width * height;
}
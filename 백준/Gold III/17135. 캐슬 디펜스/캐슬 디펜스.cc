/*
 17135번 : 캐슬 디펜스
 */
#include <iostream>
#include <array>
#include <queue>
using namespace std;

const short MAX_N = 15; //격자판 행의 최대 수
const short MAX_M = 15; //격자판 열의 최대 수
const char NONE_INDEX = 0;
const char ENEMY_INDEX = 1;
const short MAX_ARCHERS = 3;
enum Direction {
    LEFT = 0,
    UP = 1,
    RIGHT = 2
};
typedef struct {
    char index; //초기 블럭 정보
    char temp; //임시 블럭 정보
    short distance; //궁수로부터 거리 정보
}blockInfo;
blockInfo map[MAX_N][MAX_M];

array<pair<short, short>, MAX_ARCHERS> archerposition;
array<pair<short, short>, MAX_ARCHERS> enemiespositiontoattack;

bool depolyArchers(short N, short M) {
    for (short i = 0; i < MAX_ARCHERS; i++)
        archerposition[i].first = N;
    
    if (archerposition[MAX_ARCHERS-1].second < M-1) {
        archerposition[MAX_ARCHERS-1].second++;
        return true;
    }
    else {
        if (archerposition[MAX_ARCHERS-2].second < M-2) {
            archerposition[MAX_ARCHERS-2].second++;
            archerposition[MAX_ARCHERS-1].second = archerposition[MAX_ARCHERS-2].second + 1;
            return true;
        }
        else {
            if (archerposition[MAX_ARCHERS-3].second < M-3) {
                archerposition[MAX_ARCHERS-3].second++;
                archerposition[MAX_ARCHERS-2].second = archerposition[MAX_ARCHERS-3].second + 1;
                archerposition[MAX_ARCHERS-1].second = archerposition[MAX_ARCHERS-2].second + 1;
                return true;
            }
        }
    }
    return false;
}
pair<short, short> getBlockPositiontoAttack(pair<short, short> originposition, Direction direction) {
    pair<short, short> result = { -1, -1 };
    switch(direction) {
        case LEFT:
            result = { originposition.first, originposition.second - 1 };
            break;
        case UP:
            result = {originposition.first - 1, originposition.second };
            break;
        case RIGHT:
            result = { originposition.first, originposition.second + 1 };
            break;
    }
    return result;
}
bool IsBlockAttackable(pair<short, short> position, short N, short M) {
    if ((position.first >= 0) && (position.first < N) && (position.second >= 0) && (position.second < M)) {
        if (map[position.first][position.second].temp == ENEMY_INDEX)
            return true;
    }
    return false;
}
pair<short, short> Attack(pair<short, short> archerposition, short D, short N, short M) {
    bool flag = false;
    queue<pair<short, short>> qu;
    pair<short, short> firstattackblock = { archerposition.first - 1, archerposition.second };
    pair<short, short> result = { -1, -1 };
    
    if (map[firstattackblock.first][firstattackblock.second].temp == ENEMY_INDEX) {
        return firstattackblock;
    }
        
    //BFS(좌, 상, 우 순으로 탐색)
    qu.push(firstattackblock);
    map[firstattackblock.first][firstattackblock.second].distance = 1;
    while(!qu.empty()) {
        pair<short, short> front = qu.front();
        pair<short, short> nextpos;
        
        if (flag == true || map[front.first][front.second].distance >= D)
            break;
        for (short i = 0; i < 3; i++) {
            nextpos = getBlockPositiontoAttack(front, (Direction)i);
            if (nextpos.first >= 0 && nextpos.second >= 0) {
                if (IsBlockAttackable(nextpos, N, M)) {
                    flag = true;
                    result = nextpos;
                    break;
                }
                else {
                    map[nextpos.first][nextpos.second].distance = map[front.first][front.second].distance + 1;
                    qu.push(nextpos);
                }
            }
        }//for..END
        
        qu.pop();
    }//while..END
    
    return result;
}


int main() {
    //격자판 행의 수 N, 격자판 열의 수 M, 궁수의 공격 거리 제한 D 입력
    short N, M, D;
    cin >> N >> M >> D;
    
    //궁수 초기 위치(0, 1, 2) 설정
    for (short i = 0; i < MAX_ARCHERS; i++)
        archerposition[i] = { N, i };
    
    short totalenemies = 0;
    //격자판(map)정보 입력
    for (short i = 0; i < N; i++) {
        for (short j = 0; j < M; j++) {
            cin >> map[i][j].index;
            map[i][j].index -= '0';
            if (map[i][j].index == ENEMY_INDEX)
                totalenemies++;
        }
    }

    short highestkillscore = 0;
    //게임 시작
    do {
        //맵 초기화
        for (short i = 0; i < N; i++) {
            for (short j = 0; j < M; j++) {
                map[i][j].temp = map[i][j].index;
            }
        }
                
        short killedenemies = 0;
        //적이 맵에서 모두 없어질 때까지
        for (short rowNum = N-1; rowNum >= 0; rowNum--) {
            //공격하려는 대상 정하기
            for (short i = 0; i < MAX_ARCHERS; i++)
                enemiespositiontoattack[i] = Attack(archerposition[i], D, N, M);
            //공격 개시
            for (short i = 0; i < MAX_ARCHERS; i++) {
                if (enemiespositiontoattack[i].first != -1) {
                    if (map[enemiespositiontoattack[i].first][enemiespositiontoattack[i].second].temp == ENEMY_INDEX) {
                        ++killedenemies;
                        map[enemiespositiontoattack[i].first][enemiespositiontoattack[i].second].temp = NONE_INDEX;
                    }
                }
            }
            //궁수 이동
            for (short i = 0; i < MAX_ARCHERS; i++)
                archerposition[i] = { archerposition[i].first-1, archerposition[i].second };
        }//게임 종료
        
        //최고기록 저장
        highestkillscore = max(highestkillscore, killedenemies);
        if (highestkillscore >= totalenemies)
            break;
    } while(depolyArchers(N, M));
    
    //결과 출력
    cout << highestkillscore << endl;
    return 0;
}

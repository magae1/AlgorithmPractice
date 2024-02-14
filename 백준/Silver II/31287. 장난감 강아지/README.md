# [Silver II] 장난감 강아지 - 31287 

[문제 링크](https://www.acmicpc.net/problem/31287) 

### 성능 요약

메모리: 31120 KB, 시간: 392 ms

### 분류

브루트포스 알고리즘, 구현, 시뮬레이션

### 제출 일자

2024년 2월 2일 01:29:38

### 문제 설명

<p style="text-align: center;"><img alt="달리는 강아지" src="" style="max-height:150px; object-fit:contain; display:inline-block;"></p>

<p><span style="color:#e74c3c;"><code>U</code></span>, <span style="color:#e74c3c;"><code>D</code></span>, <span style="color:#e74c3c;"><code>L</code></span>, <span style="color:#e74c3c;"><code>R</code></span>로 이루어진 길이 $N$의 문자열 $S$가 주어진다. 문자열 $S$를 $K$번 이어 붙인 문자열을 $T$라고 하자. 장난감 강아지 타카하시는 2차원 좌표평면의 원점에서 시작해서 $T$에 적힌 문자를 하나씩 읽으며, 문자가 <span style="color:#e74c3c;"><code>U</code></span>라면 위쪽, <span style="color:#e74c3c;"><code>D</code></span>라면 아래쪽, <span style="color:#e74c3c;"><code>L</code></span>이라면 왼쪽, <span style="color:#e74c3c;"><code>R</code></span>이라면 오른쪽으로 한 칸 움직인다.</p>

<p>이때, 타카하시가 $T$를 따라 움직이는 동안 원점에 다시 방문하는 경우가 있는지 구해 보자.</p>

### 입력 

 <p>첫째 줄에 정수 $N$과 $K$가 공백을 사이에 두고 주어진다. ($1 \le N \le 2\,000,\ 1 \le K \le 10^9$)</p>

<p>둘째 줄에 문자열 $S$가 주어진다. $S$의 모든 문자는 <span style="color:#e74c3c;"><code>U</code></span>, <span style="color:#e74c3c;"><code>D</code></span>, <span style="color:#e74c3c;"><code>L</code></span>, <span style="color:#e74c3c;"><code>R</code></span>중 하나이다.</p>

### 출력 

 <p>타카하시가 $T$를 따라 움직이는 동안 원점에 다시 방문하는 경우가 있다면 <span style="color:#e74c3c;"><code>YES</code></span>를, 없다면 <span style="color:#e74c3c;"><code>NO</code></span>를 출력한다.</p>


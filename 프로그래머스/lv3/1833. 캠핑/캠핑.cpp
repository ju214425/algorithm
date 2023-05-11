#include <vector>
#include <algorithm>
 
using namespace std;
 
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end()); // 좌표를 x값을 기준으로 오름차순 정렬
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(data[i][0] != data[j][0] && data[i][1] != data[j][1]){ // 두 쌍의 쐐기가 대각선을 이루면
                for(int k=j; k>=0; k--){ // x축으로 두 쌍의 쐐기의 내부(경계선 포함)에 존재하는 쐐기를 대상으로 조건 검사
                    if(data[k][0] < max(data[i][0],data[j][0]) && // 내부에 존재하는지 검사
                       data[k][0] > min(data[i][0],data[j][0]) &&
                       data[k][1] < max(data[i][1],data[j][1]) &&
                       data[k][1] > min(data[i][1],data[j][1])){
                        answer--; // 내부에 존재하면 마이너스
                        break;
                    }
                }
                answer++; // 내부에 쐐기가 없으면 플러스
            }
        }
    }
 
    return answer;
}
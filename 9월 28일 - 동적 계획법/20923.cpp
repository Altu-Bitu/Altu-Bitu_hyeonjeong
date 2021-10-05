#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//그라운드에 있는 카드를 덱으로 옮기는 함수
void moveCard(deque<int>& deck, deque<int>& ground) {
    while (!ground.empty()) {//그라운드 빈경우까지 진행
        deck.push_back(ground.back());//이긴사람 덱에 진사람 그라운드에 카드 옮기기
        ground.pop_back();//그라운드꺼 없애기
    }
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>>& deck, vector<deque<int>>& ground) {
    bool turn = false; //도도부터 시작

    while (m--) {//게임진행횟수 만큼
        //이번 턴의 사람이 카드 뒤집어서 그라운드에 올려놓기
        int card = deck[turn].front();//도도 카드부터
        ground[turn].push_front(card);//그라운드에 하나씩 놓기
        deck[turn].pop_front();//덱에서는 하나 없어짐

        //게임 진행 도중 둘 중 한 명의 덱에 있는 카드의 수가 0개가 되는 즉시 게임 종료
        if (deck[turn].empty())//한 명의 덱이 비는 경우 종료
            break;

        //이번에 종을 칠 사람
        int bell = -1;//초기
        if (card == 5)//도도의경우
            bell = 0;
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5))
            bell = 1;//그라운드가 비지 않고 그라운드 카드의 숫자 합이 5이면 수연이가 종 침

        if (bell != -1) { //누군가가 종을 쳤다면
            moveCard(deck[bell], ground[!bell]);//상대방 그라운드카드 옮기기
            moveCard(deck[bell], ground[bell]);//자신의 그라운드 카드 옮기기
        }
        turn = !turn; //차례 바꾸기
    }
    return make_pair(deck[0].size(), deck[1].size());//도도와 수연의 덱 사이즈 전달
}

/**
 * 1. 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
 * 2. 게임을 진행하던 도중 언제든지 누군가의 카드 덱이 비게되면 게임을 종료
 */
int main() {
    int n, m, num1, num2;//카드의 개수, 게임진행횟수
    vector<deque<int>> deck(2), ground(2);//도도와 수연이의 덱과 그라운드

    cin >> n >> m;
    while (n--) {
        cin >> num1 >> num2;
        deck[0].push_front(num1);//도도의 덱의 숫자 추가
        deck[1].push_front(num2);//수연의 덱의 숫자 추가
    }

    pair<int, int> result = playGame(m, deck, ground);//게임 진행

    if (result.first == result.second)//카드 개수 같으면 동점
        cout << "dosu\n";
    else if (result.first > result.second)//도도가 많으면 도도 승리
        cout << "do\n";
    else if (result.first < result.second)//수연이 많으면 수연 승리
        cout << "su\n";
}
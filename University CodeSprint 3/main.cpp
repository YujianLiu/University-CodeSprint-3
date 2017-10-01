//
//  main.cpp
//  University CodeSprint 3
//
//  Created by yujian liu on 9/29/17.
//  Copyright © 2017 HackerRank. All rights reserved.
//

#include "Header.h"
unordered_map<string, int> res_map;
bool Compare_Bob(pair<int, int> p1, pair<int, int> p2){
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    else return p1.first < p2.first;
    
}

int Bob_Game(vector<string>& board, vector<pair<int, int>> k_pos){
    int result = 0;
    string s;
    sort(k_pos.begin(), k_pos.end(), Compare_Bob);
    for (int i = 0; i < k_pos.size(); i++){
        s += to_string(k_pos[i].first) + ',' + to_string(k_pos[i].second) + '.';
    }
    
    if (res_map.find(s) != res_map.end()) {
        return res_map[s];
    }
    for (int i = 0; i < k_pos.size(); i++) {
        
        int x = k_pos[i].first, y = k_pos[i].second;
        
        if (x > 0 and board[x - 1][y] != 'X') {
            k_pos[i].first--;
            if(Bob_Game(board, k_pos) == 0)
                result++;
            k_pos[i].first++;
        }
        if (y > 0 and board[x][y - 1] != 'X') {
            k_pos[i].second--;
            if(Bob_Game(board, k_pos) == 0)
                result++;
            k_pos[i].second++;
        }
        if (x > 0 and y > 0 and board[x - 1][y - 1] != 'X') {
            k_pos[i].first--;
            k_pos[i].second--;
            if(Bob_Game(board, k_pos) == 0)
                result++;
            k_pos[i].first++;
            k_pos[i].second++;
        }
    }
    
    res_map[s] = result;
    return result;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector<string> board(n);
        for(int board_i = 0; board_i < n; board_i++){
            cin >> board[board_i];
        }
        // Write Your Code Here
        vector<pair<int, int>> k_pos;
        for(int i = 0; i < n; i++){
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'K') {
                    k_pos.push_back({i, j});
                }
            }
        }
        
        
        int result = Bob_Game(board, k_pos);
        for (auto it = res_map.begin(); it != res_map.end(); it++) {
            cout << it -> first << it -> second << endl;
        }
        if (result == 0) {
            cout << "LOSE" << endl;
        }
        else{
            cout << "WIN" <<" "<< result << endl;
        }
    }
    return 0;
}

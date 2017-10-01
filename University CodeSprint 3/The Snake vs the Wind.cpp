//
//  The Snake vs the Wind.cpp
//  University CodeSprint 3
//
//  Created by yujian liu on 9/29/17.
//  Copyright © 2017 HackerRank. All rights reserved.
//

#include "Header.h"

int snake_and_wind(){
    int n;
    cin >> n;
    char d;
    cin >> d;
    int x;
    int y;
    cin >> x >> y;
    vector<bool> a(n,false);
    vector<vector<bool>> ground(n,a);
    vector<int> c(n,0);
    vector<vector<int>> e(n,c);
    ground[x][y] = true;
    e[x][y] = 1;
    for (int i = 2; i <= n * n; i++) {
        if (d == 'e') {
            if (y + 1 < n and ground[x][y + 1] == false) {
                y++;
            }
            else if(x - 1 >= 0 and ground[x - 1][y] == false){
                x--;
            }
            else if (x + 1 < n and ground[x + 1][y] == false){
                x++;
            }else{
                y--;
            }
        }
        else if(d == 's'){
            if (x + 1 < n and ground[x + 1][y] == false) {
                x++;
            }
            else if(y - 1 >= 0 and ground[x][y - 1] == false){
                y--;
            }
            else if (y + 1 < n and ground[x][y + 1] == false){
                y++;
            }else{
                x--;
            }
        }else if (d == 'n'){
            if (x - 1 >= 0 and ground[x - 1][y] == false) {
                x--;
            }
            else if(y - 1 >= 0 and ground[x][y - 1] == false){
                y--;
            }
            else if (y + 1 < n and ground[x][y + 1] == false){
                y++;
            }else{
                x++;
            }
            
        }else{
            if (y - 1 >= 0 and ground[x][y - 1] == false) {
                y--;
            }
            else if(x - 1 >= 0 and ground[x - 1][y] == false){
                x--;
            }
            else if (x + 1 < n and ground[x + 1][y] == false){
                x++;
            }else{
                y++;
            }
        }
        e[x][y] = i;
        ground[x][y] = true;
    }
    for(auto row : e){
        for(auto num : row)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}

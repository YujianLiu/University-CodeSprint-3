//
//  Erupting Volcanoes.cpp
//  University CodeSprint 3
//
//  Created by yujian liu on 9/29/17.
//  Copyright © 2017 HackerRank. All rights reserved.
//

#include "Header.h"

int erupting_vocano(){
    
int n;
cin >> n;
int m;
cin >> m;
    vector<pair<int, pair<int, int>>> vocano;
    int result = 0;
for(int a0 = 0; a0 < m; a0++){
    int x;
    int y;
    int w;
    cin >> x >> y >> w;
    // Write Your Code Here
    vocano.push_back({w, {x, y}});
    
}
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int over = 0;
            int w = 0;
            for(auto mount : vocano){
                
            int disx = abs(mount.second.first - x);
            int disy = abs(mount.second.second - y);
            
            int dis = max(disx, disy);
            
            if (dis < mount.first) {
                over += mount.first - dis;
                result = max(result, w + over);
            }
                
            }
            result = max(result, w);
        }
        
    }
    cout << result;
return 0;
}

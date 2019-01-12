//
//  main.cpp
//  BallEscape
//
//  Created by 박종상 on 11/01/2019.
//  Copyright © 2019 박종상. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int w, h;
string str;

class pair{
public:
    int x;
    int y;
};

int main(int argc, const char * argv[]) {
    // insert code here...

    cin >> w >> h;
    
    char map[w][h];
    pair red;
    pair blue;
    pair exit;
    
    for(int i = 0; i < w; i++){
        cin >> str;
        for(int j = 0; j < h; j++){
            map[i][j] = str.at(j);
            if(map[i][j] == 'R'){
                
            }
        }
    }
    
    
    
    return 0;
}

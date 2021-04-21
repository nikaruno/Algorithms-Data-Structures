string intTobit(int x){
    string s = "0000000000";
    while(x){
        if (x>=512){
            s.at(0) = '1';
            x -= 512;
        }
        else if (x>=256){
            s.at(1) = '1';
            x -= 256;
        }
        else if (x>=128){
            s.at(2) = '1';
            x -= 128;
        }
        else if (x>=64){
            s.at(3) = '1';
            x -= 64;
        }
        else if (x>=32){
            s.at(4) = '1';
            x -= 32;
        } 
        else if (x>=16){
            s.at(5) = '1';
            x -= 16;
        } 
        else if (x>=8){
            s.at(6) = '1';
            x -= 8;
        } 
        else if (x>=4){
            s.at(7) = '1';
            x -= 4;
        } 
        else if (x>=2){
            s.at(8) = '1';
            x -= 2;
        }
        else if (x>=1){
            s.at(9) = '1';
            x -= 1;
        }    
    }
    return s;
}

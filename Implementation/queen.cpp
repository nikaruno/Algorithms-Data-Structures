int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    int north = n - r_q;
    int south = r_q - 1;
    int east  = n - c_q;
    int west  = c_q - 1;
    
    int northEast = (n - c_q)<(n - r_q) ? (n - c_q) : (n - r_q);   
    int northWest = (n - r_q)<(c_q - 1) ? (n - r_q) : (c_q - 1);
    int southWest = (c_q - 1)<(r_q - 1) ? (c_q - 1) : (r_q - 1);
    int southEast = (r_q - 1)<(n - c_q) ? (r_q - 1) : (n - c_q);
    
    
    int r_o, c_o;
    for (vector<vector<int>>::iterator it = obstacles.begin(); it != obstacles.end(); it++){
     r_o = (*it).at(0);
     c_o = (*it).at(1);   
     
     if (c_o == c_q){
         if (r_o > r_q){ //North
            north = (north < (r_o - r_q)) ? north : (r_o - r_q - 1);    
         }
         else{ //South
            south = (south < (r_q - r_o)) ? south : (r_q - r_o - 1); 
         }
     }
     else if (r_o == r_q){
         if (c_o > c_q){ //East
            east = (east < (c_o - c_q)) ? east : (c_o - c_q - 1);    
         }
         else{ // West
            west = (west < (c_q - c_o)) ? east : (c_q - c_o - 1); 
         }         
     }
     else if ((r_o - r_q) == (c_o - c_q)){
         if(r_o > r_q){ //NorthEast
            northEast = (northEast < (r_o - r_q)) ? northEast : (r_o - r_q - 1);    
         }
         else{ //SouthWest
            southWest = (southWest < (r_q - r_o)) ? southWest : (r_q - r_o - 1); 
         }
     }
     else if ((r_o - r_q) == (c_q - c_o)){
        if(c_o > c_q){ //SouthEast
            southEast = (southEast < (c_o - c_q)) ? southEast : (c_o - c_q - 1);
        } 
        else{ //NorthWest
            northWest = (northWest < (c_q - c_o)) ? northWest : (c_q - c_o - 1);
        } 
     }     
    }
 
    return (north + south + east + west + northEast + northWest + southEast + southWest);
}

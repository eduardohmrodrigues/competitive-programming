int pageCount(int n, int p) {
    if(n%2 != 0) n -=1;
    if(p%2 != 0) p -= 1;
    
    int l = p/2;
    int r = (n-p)/2;
    
    return l < r ? l : r;
}

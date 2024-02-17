void bonAppetit(vector<int> bill, int k, int b) {
    int realAnnaAmount = 0;
    for(int i=0; i<bill.size(); ++i) {
        if(i == k) continue;
        realAnnaAmount += bill[i];
    }
    realAnnaAmount /= 2;
    
    if(realAnnaAmount == b) cout << "Bon Appetit" << endl;
    else cout << b - realAnnaAmount << endl;
}

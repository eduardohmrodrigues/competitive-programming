string kangaroo(int x1, int v1, int x2, int v2) {
    bool isPossible = false;
    double mult = 0;
    if(x1 < x2) {
        if(v1 <= v2) return "NO";
        mult = (float)(x2-x1)/(float)(v1-v2);
        isPossible = floor(mult) == ceil(mult);
    } else if (x2 < x1) {
        if(v2 <= v1) return "NO";
        mult = (float)(x1-x2)/(float)(v2-v1);
        isPossible = floor(mult) == ceil(mult);
    } else {
        isPossible = true;
    }
    cout << isPossible << " " << mult << endl;
    return isPossible ? "YES" : "NO";
}

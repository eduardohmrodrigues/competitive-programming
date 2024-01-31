/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

int popCookie(map<int, int> *cookies) {
    int cookie = cookies->begin()->first;
    int cookieAmount = cookies->begin()->second;
        
    if(cookieAmount == 1) {
        cookies->erase(cookie);
    } else {
        cookies->operator[](cookie) -= 1;
    }
    
    return cookie;
}

void pushCookie(int cookie, map<int, int> *cookies) {
    if(cookies->find(cookie) == cookies->end()) cookies->operator[](cookie) = 0;
    cookies->operator[](cookie) += 1;
}

int cookies(int k, vector<int> A) {
    map<int, int> sweetnessToOccurrence;
    int amount = A.size();
    for(int i=0; i<amount; ++i) {
        pushCookie(A[i], &sweetnessToOccurrence);
    }
    
    int it = 0;
    while(amount > 1 && sweetnessToOccurrence.begin()->first < k) {
        ++it;
        int cookie1 = popCookie(&sweetnessToOccurrence);
        int cookie2 = popCookie(&sweetnessToOccurrence);
        pushCookie(cookie1 + 2*(cookie2), &sweetnessToOccurrence);
        amount -= 1;
    }
    
    if(sweetnessToOccurrence.begin()->first < k) it = -1;
    return it;
}

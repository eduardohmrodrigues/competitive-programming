/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int s1=0, s2=0, s3=0, i=0, j=0, k=0;
    while(i<h1.size() || j<h2.size() || k<h3.size()){
        if(i<h1.size()) s1 += h1[i++];
        if(j<h2.size()) s2 += h2[j++];
        if(k<h3.size()) s3 += h3[k++];
    }

    while(s1 != s2 || s1 != s3){
        if(s1 > s2 || s1 > s3){
            s1 -= h1[0];
            h1.erase(h1.begin());
        }

        if(s2 > s1 || s2 > s3) {
            s2 -= h2[0];
            h2.erase(h2.begin());
        }

        if(s3 > s1 || s3 > s2) {
            s3 -= h3[0];
            h3.erase(h3.begin());
        }
    }

    return s1;
}

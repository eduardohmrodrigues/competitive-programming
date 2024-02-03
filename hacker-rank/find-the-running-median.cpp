/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
std::vector<double> runningMedian(std::vector<int> a) {
    std::vector<double> res(a.size());
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    for (int i = 0; i < a.size(); ++i) {
        if (maxHeap.empty() || a[i] <= maxHeap.top()) {
            maxHeap.push(a[i]);
        } else {
            minHeap.push(a[i]);
        }
        
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        if (maxHeap.size() == minHeap.size()) {
            res[i] = (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            res[i] = maxHeap.top();
        }
    }
    
    return res;
}

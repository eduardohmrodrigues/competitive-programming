vector<int> gradingStudents(vector<int> grades) {
    int diff = 0;
    for(int i=0; i<grades.size(); ++i) {
        diff = 5 - (grades[i]%5);
        if(diff < 3 && grades[i] > 37) grades[i] = grades[i] + diff;
    }
    
    return grades;
}

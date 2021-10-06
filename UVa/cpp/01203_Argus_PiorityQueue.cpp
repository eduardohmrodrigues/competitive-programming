#include <iostream>
#include <queue>

class Instruction{
public:
    int qnum;
    int period;
    int defaultPeriod;

    Instruction(int q, int p){
        qnum = q;
        period = p;
        defaultPeriod = p;
    }

    void nextPeriod(){
        period += defaultPeriod;
    }
};

// we are doing operator overloading through this
bool operator<(const Instruction& i1, const Instruction& i2)
{

    // this should return true when second instruction
    // has greater period. Suppose we have i1.period=5
    // and i2.period=5.5 then the object which
    // have max period should be at the top(or
    // max priority). Since what I want is the lower periods
    // on top of the queue (inverted priority), I am inverting
    // the operators of the compare function
    if(i1.period != i2.period){
        return i1.period > i2.period;
    }

    return i1.qnum > i2.qnum;
}

int main() {
    std::string str;
    int qnum, period, k;
    std::priority_queue<Instruction> que;

    while(std::cin >> str && str[0] != '#'){
        std::cin >> qnum >> period;
        que.push(Instruction(qnum, period));
    }
    std::cin >> k;

    while(k--){
        Instruction a = que.top();
        std::cout << a.qnum << std::endl;
        que.pop();
        a.nextPeriod();
        que.push(a);
    }

    return 0;
}

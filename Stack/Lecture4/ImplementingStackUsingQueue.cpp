class MyStack {
public:
   queue<int>q1;
   queue<int>q2;

    MyStack() {
        
    }
    
    void push(int x) {
        if(!q1.empty()){
            q1.push(x);
        }
        else if(!q2.empty()){
            q2.push(x);
        }
        else{
            q1.push(x);
        }
    }
    
    int pop() {
        if(!q2.empty()){
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            int ele = q2.front();
            q2.pop();
            return ele;
        }
        else{
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();
            q1.pop();
            return ele;
        }
    }
    
    int top() {
        if(!q1.empty()){
            return q1.back();
        }
        else{
            return q2.back();
        }
    }
    
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};
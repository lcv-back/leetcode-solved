class CustomStack {
private:
    vector<int> stack;
    int ptr;
public:
    CustomStack(int maxSize){
        stack.resize(maxSize);
        ptr = -1;
    }
    
    void push(int x){
        if(!isFull()){
            ptr++;
            stack[ptr] = x;
        }
    }
    
    int pop(){
        int topElement = -1;
        if(!isEmpty()){
            topElement = stack[ptr];
            ptr--;
        }
        return topElement;
    }
    
    void increment(int k, int val){
        int step = k < stack.size() ? k : stack.size();
        for(int i=0; i<step; i++) stack[i] += val;
    } 
    
    bool isEmpty(){
        return ptr == -1;
    }
    
    bool isFull(){
        return ptr == stack.size()-1;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
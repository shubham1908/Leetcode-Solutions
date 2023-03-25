class BrowserHistory {
public:
    stack<string> currentStack, backStack;
    
    BrowserHistory(string homepage) {
        currentStack.push(homepage);
    }
    
    void visit(string url) {
        currentStack.push(url);
        backStack = stack<string>();
    }
    
    string back(int steps) {
        while(steps-- && currentStack.size() > 1){
            backStack.push(currentStack.top());
            currentStack.pop();
        }
        return currentStack.top();
    }
    
    string forward(int steps) {
        while(!backStack.empty() && steps--){
            currentStack.push(backStack.top());
            backStack.pop();
        }
        return currentStack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
class BrowserHistory {
public:
    
     int count=0,curr=0;
    string v[110];
    BrowserHistory(string homepage) {
        v[count]=homepage;
    }
    
    void visit(string url) {
        v[++count]=url;
        curr=count;
    }
    
    string back(int steps) {
        count = max(count-steps, 0);
        return v[count];
    }
    
    string forward(int steps) {
        count = min(curr, count+steps);
        return v[count];
    }
};
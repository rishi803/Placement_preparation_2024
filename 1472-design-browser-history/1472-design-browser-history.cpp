class BrowserHistory {
public:
    
     int count=0,curr=0;
    string v[110];
    BrowserHistory(string homepage) {
        v[count]=homepage;
    }
    
    void visit(string url) {
        v[++count]=url;          // ex- [ google , facebook , yahoo ] if we are at facebook and visited
                                // linkedin then scenario will change to [ google, facebook, linkedin ]
        curr=count;
    }
    
    string back(int steps) {
        count = max(count-steps, 0);    // count shows at which position we are currently
        return v[count];
    }
    
    string forward(int steps) {
        count = min(curr, count+steps);    // curr shows that how many sites we have visited
        return v[count];
    }
};
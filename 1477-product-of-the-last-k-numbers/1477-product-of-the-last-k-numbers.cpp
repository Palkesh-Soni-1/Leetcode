class ProductOfNumbers {
    private:
    vector<int>t;
public:
    ProductOfNumbers() {
        t.push_back(1);
    }
    
    void add(int num) {
        if(num!=0)
        {
            t.push_back(num*t.back());
        }
        else{
            t.clear();
            t.push_back(1);
        }
    }
    
    int getProduct(int k) {
        int ans=0;
        if(k<t.size())
        {
            ans=t.back()/t[t.size()-k-1];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
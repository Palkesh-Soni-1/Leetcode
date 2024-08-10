struct Node
{
    Node* links[2];

    bool contains(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node* n)
    {
        links[bit]=n;
    }

    Node* get(int bit)
    {
        return links[bit];
    }
};

class Trie{
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }

    void insert(int num)
    {
        Node* node = root;
        for(int i=0;i<=31;i++)
        {
            int bit = (num>>(31-i))&1;
            if(!(node->contains(bit)))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int getmax(int num)
    {
        Node* node = root;
        int ans=0;
        int temp=0;
        for(int i=0;i<=31;i++)
        {
            int bit = (num>>(31-i))&1;
            if((node->contains(1-bit)))
            {
                int x = 1<<(31-i);
                temp = temp|x;
                node = node->get(1-bit);
            }
            else
            node = node->get(bit);
        }
        ans = temp;
        return ans;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            trie.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            int x = trie.getmax(nums[i]);
            ans = max(ans,x);
        }
        return ans;
    }
};
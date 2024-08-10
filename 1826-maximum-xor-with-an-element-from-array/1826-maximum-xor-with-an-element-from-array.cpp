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
    int findMax(int num) {
        // Start traversal from the root node
        Node* node = root; 
        
        // Initialize the maximum XOR value
        int maxNum = 0; 
        
        // Traverse each bit of the number
        // from the most significant bit to
        // the least significant bit
        for(int i = 31; i >= 0; i--) {
            
             // Extract the i-th
             // bit of the number
            int bit = (num >> i) & 1;
            
            // If there exists a different bit
            // in the trie at the current position,
            // choose it to maximize XOR
            if(node->contains(!bit)) {
                
                 // Set the corresponding
                 // bit in the result
                maxNum = maxNum | (1 << i);
                // Move to the child node
                // with the different bit
                node = node->get(!bit); 
            }
            else {
                
                // Move to the child node
                // with the same bit
                node = node->get(bit); 
            }
        }
        
        // Return the maximum XOR value
        return maxNum; 
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0); 
    
     // Vector to store offline queries
    vector<pair<int, pair<int,int>>> offlineQueries;
    // Sort the numsay of numbers
    sort(nums.begin(), nums.end()); 
    
    int index = 0;
    
    // Convert queries to offline
    // queries and store them in a vector
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],{it[0], index++}}); 
    }
    
    // Sort offline queries
    // based on their end points
    sort(offlineQueries.begin(), offlineQueries.end());
    
    // Pointer to iterate through
    // the numsay of numbers
    int i = 0; 
    
    // Number of elements in the numsay
    int n = nums.size(); 
    
    // Create an instance of
    // the Trie data structure
    Trie Trie; 
    
    // Process each offline query
    for(auto &it : offlineQueries) {
        // Insert numbers into the Trie
        // until the current query's end point
        while(i < n && nums[i] <= it.first) {
            Trie.insert(nums[i]); 
            i++; 
        }
        
        // If there are numbers inserted
        // into the Trie, find the maximum
        // XOR value for the query range
        if(i != 0) 
            ans[it.second.second] = Trie.findMax(it.second.first); 
        else 
            // If no numbers inserted,
            // set result to -1
            ans[it.second.second] = -1; 
    }
    // Return the results
    // of all queries
    return ans;
        // vector<int>ans(queries.size(),0);
        // sort(nums.begin(),nums.end());
        // //offline query
        // vector<pair<int,pair<int,int>>>q;
        // for(int i=0;i<queries.size();i++)
        // {
        //     q.push_back({queries[i][1],{queries[i][0],i}});
        // }
        // sort(q.begin(),q.end());
        // for(int i=0;i<q.size();i++)
        // {
        //     int x = q[i].first;
        //     int y = 
        //     vector<int>temp;
        //     for(int i=0;i<nums.size();i++)
        //     {
        //         if(nums[i]<=x)
        //         {
        //             temp.push_back(nums[i]);
        //         }
        //     }
        //     findMaximumXOR(temp);
        // }
    }
};
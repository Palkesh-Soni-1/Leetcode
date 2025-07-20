#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<string, Node*> children;
    string name;
    bool toDelete = false;
    Node(string name = "") : name(name) {}
};

class Solution {
    unordered_map<string, vector<Node*>> dupMap;

    string serialize(Node* node) {
        if (node->children.empty()) return "";
        
        vector<string> keys;
        for (auto& [name, _] : node->children) keys.push_back(name);
        sort(keys.begin(), keys.end());

        string serial;
        for (const string& name : keys) {
            serial += "(" + name + serialize(node->children[name]) + ")";
        }

        dupMap[serial].push_back(node);
        return serial;
    }

    void markDuplicates() {
        for (auto& [serial, nodes] : dupMap) {
            if (nodes.size() > 1) {
                for (Node* node : nodes) node->toDelete = true;
            }
        }
    }

    void collect(Node* node, vector<string>& path, vector<vector<string>>& result) {
        if (node->toDelete) return;
        if (!node->name.empty()) path.push_back(node->name);
        if (!path.empty()) result.push_back(path);

        for (auto& [_, child] : node->children) {
            collect(child, path, result);
        }

        if (!node->name.empty()) path.pop_back();
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();

        for (auto& path : paths) {
            Node* curr = root;
            for (const string& name : path) {
                if (!curr->children.count(name)) {
                    curr->children[name] = new Node(name);
                }
                curr = curr->children[name];
            }
        }

        serialize(root);
        markDuplicates();

        vector<vector<string>> result;
        vector<string> temp;
        collect(root, temp, result);
        return result;
 }
};
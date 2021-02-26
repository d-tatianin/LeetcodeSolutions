#pragma once

// 208. Implement a trie with insert, search, and startsWith methods.

// Solution: (complexity O(M))
// Keep a node for each letter we encounter, and mark
// the last node of a word as end. A good description of
// the solution and use cases can be found here:
// https://leetcode.com/problems/implement-trie-prefix-tree/solution/

SOLUTION_FOR_PROBLEM(208, "Implement Trie (Prefix Tree)") {

class Trie {
public:
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        Node* current = &m_root;

        for (char c : word) {
            if (current->children[c - 'a'])
                current = current->children[c - 'a'];
            else {
                auto new_node = new Node{ false, {} };
                current->children[c - 'a'] = new_node;
                current = new_node;
            }
        }

        current->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        auto* node = prefix_node(word);

        return node && node->is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        return prefix_node(prefix) != nullptr;
    }

private:
    struct Node {
        bool is_end = false;
        Node* children[26]{};
    } m_root;

    Node* prefix_node(const std::string& pref)
    {
        auto* current = &m_root;

        for (char c : pref) {
            if (current->children[c - 'a'])
                current = current->children[c - 'a'];
            else
                return nullptr;
        }

        return current;
    }
};

SOLVE()
{
    Trie trie;

    trie.insert("apple");
    trie.search("apple");   // returns true
    trie.search("app");     // returns false
    trie.startsWith("app"); // returns true
    trie.insert("app");
    trie.search("app");     // returns true
}

}

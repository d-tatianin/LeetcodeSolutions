#pragma once

#include <string>

// 371. Serialize and Deserialize Binary Tree.

// Solution: (complexity O(N))
// Walk the tree in preorder while serializing every node as 'val' + ',' and '#,' for null nodes
// Reconstruct the entire tree by deserializing in preorder following the same rules

namespace problem_297 {

class Codec {
public:
    std::string serialize(TreeNode* root) {
        std::string out;

        do_serialize(root, out);

        return out;
    }

    TreeNode* deserialize(std::string data) {
        size_t offset = 0;

        return do_deserialize(data, offset, nullptr, false);
    }

private:
    void do_serialize(TreeNode* root, std::string& out)
    {
        if (!root) {
            out += "#,";
            return;
        }

        out += std::to_string(root->val);
        out += ',';

        do_serialize(root->left, out);
        do_serialize(root->right, out);
    }

    size_t pop_one(const std::string& in, size_t offset, int& popped, bool& did_pop, bool& is_null)
    {
        if (!(offset < in.size()) || in.empty()) {
            did_pop = false;
            return offset;
        }

        auto end = in.find(',', offset);

        if (end == std::string::npos) {
            did_pop = false;
            return offset;
        }

        if (in[end - 1] == '#') {
            did_pop = true;
            is_null = true;
            return end + 1;
        }

        popped = atoi(in.data() + offset);
        did_pop = true;

        return end + 1;
    }

    TreeNode* do_deserialize(std::string& in, size_t& offset, TreeNode* out, bool is_left = false)
    {
        bool did_pop = false;
        bool is_null = false;
        int val = 0;

        offset = pop_one(in, offset, val, did_pop, is_null);

        if (!did_pop || is_null)
            return out;

        if (out == nullptr) {
            out = new TreeNode(val);
        } else {
            if (is_left) {
                out->left = new TreeNode(val);
                out = out->left;
            } else {
                out->right = new TreeNode(val);
                out = out->right;
            }
        }

        do_deserialize(in, offset, out, true);
        do_deserialize(in, offset, out, false);

        return out;
    }
};

}

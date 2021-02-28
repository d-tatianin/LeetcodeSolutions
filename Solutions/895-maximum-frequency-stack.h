#pragma once

// 895. Implement FreqStack, a class which simulates the operation of a stack-like data structure.

// Solution: (complexity O(1))
// We keep two maps:
// number -> occurences
// occurences -> numbers
// When we push a number, we increment it's number of occurences
// and push it into the second second map.
// When we pop a number we take the top of the second map at the
// maximum frequency, and decrement occurences for that number.

SOLUTION_FOR_PROBLEM(895, "Maximum Frequency Stack") {

class FreqStack {
public:
    void push(int x) {
        int freq = ++m_num_to_freq[x];
        m_freq_to_nums[freq].push(x);

        if (freq > m_max)
            m_max = freq;
    }

    int pop() {
        auto num = m_freq_to_nums[m_max].top();
        m_freq_to_nums[m_max].pop();

        m_num_to_freq[num]--;

        if (m_freq_to_nums[m_max].empty())
            m_max--;

        return num;
    }

private:
    int m_max = 0;
    std::unordered_map<int, int> m_num_to_freq;
    std::unordered_map<int, std::stack<int>> m_freq_to_nums;
};

SOLVE()
{
    FreqStack s;

    s.push(1);
    s.push(1);
    s.push(2);
    auto res = s.pop();
}

}

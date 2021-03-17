#pragma once

// 622. Design your implementation of the circular queue.

// Solution: (complexity O(1))
// Generic circular queue implementation with
// two pointers for head and tail as well as
// size.

SOLUTION_FOR_PROBLEM(622, "Design Circular Queue") {

class MyCircularQueue {
public:
    MyCircularQueue(int k) : m_queue(k) {}

    bool enQueue(int value) {
        if (isFull())
            return false;

        m_queue[m_tail] = value;
        m_size++;

        if (++m_tail == m_queue.size())
            m_tail = 0;

        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        if (++m_head == m_queue.size())
            m_head = 0;
        m_size--;

        return true;
    }

    int Front() const {
        if (isEmpty())
            return -1;

        return m_queue[m_head];
    }

    int Rear() const {
        if (isEmpty())
            return -1;

        return m_queue[m_tail ? m_tail - 1 : m_queue.size() - 1];
    }

    bool isEmpty() const { return m_size == 0; }
    bool isFull() const { return m_size == m_queue.size(); }

private:
    std::vector<int> m_queue;
    size_t m_head = 0;
    size_t m_tail = 0;
    size_t m_size = 0;
};

SOLVE()
{
    MyCircularQueue myCircularQueue(3);
    myCircularQueue.enQueue(1); // return True
    myCircularQueue.enQueue(2); // return True
    myCircularQueue.enQueue(3); // return True
    myCircularQueue.enQueue(4); // return False
    myCircularQueue.Rear();     // return 3
    myCircularQueue.isFull();   // return True
    myCircularQueue.deQueue();  // return True
    myCircularQueue.enQueue(4); // return True
    myCircularQueue.Rear();     // return 4
}

}

#pragma once

#include <unordered_map>
#include <map>

// 1146. Implement a SnapshotArray that supports the following interface:
//       - SnapshotArray(int length) initializes an array - like data structure with the given length.Initially, each element equals 0.
//       - void set(index, val) sets the element at the given index to be equal to val.
//       - int snap() takes a snapshot of the array and returns the snap_id : the total number of times we called snap() minus 1.
//       - int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

// Solution: (complexity -> set: O(1), get: O(log N))
// We simply keep a map of index to it's state at each snapshot id when it was changed.
// Keeping snapshot ids in a map allows us to use upper_bound to extract the latest written change to an index in logarithmic time.

PROBLEM(1146, "Snapshot Array") {

class SnapshotArray {
public:
    SnapshotArray(int length) { }

    void set(int index, int val) { idx_to_snapshot_to_value[index][current_snapshot] = val; }

    int snap() { return current_snapshot++; }

    int get(int index, int snap_id) {
        auto it = idx_to_snapshot_to_value[index].upper_bound(snap_id);

        return it == idx_to_snapshot_to_value[index].begin() ? 0 : prev(it)->second;
    }

private:
    int current_snapshot = 0;
    std::unordered_map<int, std::map<int, int>> idx_to_snapshot_to_value;
};

TRY_SOLVE()
{
    SnapshotArray array(3);
    array.set(0, 0);
    array.snap();
    array.set(0, 1);
    auto res = array.get(0, 0);
}

}

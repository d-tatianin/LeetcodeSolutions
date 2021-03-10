#pragma once

// 1428. Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed)
//       with at least a 1 in it. If such index doesn’t exist, return -1.

// Solution: (complexity O(Log W * Log H))
// Binary search, but we keep the current best and
// skip each row where best is not 1.

SOLUTION_FOR_PROBLEM(1428, "Leftmost Column with at Least a One") {

class BinaryMatrix {
public:
    int get(int row, int col) { return col >= row; }
    std::vector<int> dimensions() { return { 3, 3 };  }
};

int leftMostColumnWithOne(BinaryMatrix binaryMatrix)
{
    auto dim = binaryMatrix.dimensions();

    int current_leftmost = dim[1];

    for (int i = 0; i < dim[0]; ++i)
    {
        if (binaryMatrix.get(i, current_leftmost - 1) == 0)
            continue;

        int begin = 0;
        int end = current_leftmost - 1;

        while (begin <= end)
        {
            int middle = begin + (end - begin) / 2;

            if (binaryMatrix.get(i, middle) == 0)
                begin = middle + 1;
            else
                end = middle - 1;
        }

        current_leftmost = std::min(current_leftmost, begin);

        if (current_leftmost == 0)
            break;
    }

    return current_leftmost;
}

SOLVE()
{
    auto res = leftMostColumnWithOne({});
}

}

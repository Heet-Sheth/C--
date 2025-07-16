#include <iostream>
#include <vector>
using namespace std;
class SegmentTree
{
    vector<int> tree;
    int n;
    void build(vector<int> &arr, int index, int low, int high)
    {
        if (low == high)
        {
            tree[index] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(arr, 2 * index + 1, low, mid);
        build(arr, 2 * index + 2, mid + 1, high);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    int find(int low, int high, int l, int r)
    {
        if (l > high || r < low)
            return 0; // No overlap
        if (l <= low && r >= high)
            return tree[0]; // Total overlap

        int mid = (low + high) / 2;
        int leftSum = find(low, mid, l, r);
        int rightSum = find(mid + 1, high, l, r);

        return leftSum + rightSum; // Partial overlap
    }
};

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    SegmentTree *st = new SegmentTree(arr);
    return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

class minHeap {
    private:
        int* heap;
        int heapSize;

    public:
        minHeap(int n) : heapSize(0) {
            heap = (int*) malloc((n + 1) * sizeof(int));
        }

        void push(int x) {
            heap[++heapSize] = x;
            int cur = heapSize;
            while (cur > 1) {
                int fa = cur >> 1;
                if (heap[cur] >= heap[fa]) break;
                swap(heap[cur], heap[fa]);
                cur = fa;
            }
        }

        int pop() {
            int res = heap[1];
            heap[1] = heap[heapSize--];
            int fa = 1;
            while ((fa << 1) <= heapSize) {
                int child = fa << 1;
                if (child < heapSize && heap[child + 1] < heap[child]) child++;
                if (heap[fa] <= heap[child]) break;
                swap(heap[fa], heap[child]);
                fa = child;
            }
            return res;
        }

        int size() {
            return heapSize;
        }
};

int main() {
    int n;
    scanf("%d", &n);
    minHeap heap(n);
    while (n--) {
        int num;
        scanf("%d", &num);
        heap.push(num);
    }
    int ans = 0;
    while (heap.size() > 1) {
        int num1 = heap.pop(), num2 = heap.pop();
        ans += num1 + num2;
        heap.push(num1 + num2);
    }
    printf("%d", ans);
    return 0;
}

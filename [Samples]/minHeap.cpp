#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
using namespace std;

class minHeap {
    private:
        int* heap;
        int heapSize;

    public:
        minHeap(int n) : heap((int*) malloc((n + 1) * sizeof(int))), heapSize(0) {}

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
    srand(time(0));
    minHeap heap(10);
    printf("Input sequence: ");
    for (int i = 1; i <= 10; i++) {
        int num = rand() % 100 + 1;
        printf("%d ", num);
        heap.push(num);
    }
    printf("\nOutput sequence: ");
    while (heap.size()) {
        printf("%d ", heap.pop());
    }
    printf("\n");
    return 0;
}

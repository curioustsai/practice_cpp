class FixedMultiStack {
public:
    // Create 3 stacks, each stack is of size stackCapacity.
    FixedMultiStack(int stackCapacity);
    virtual ~FixedMultiStack();

    // Push an element onto stack stackNum, where stackNum is from 0 to 2.
    void push(int stackNum, int value);

    // Pop the top element from stack stackNum, where stackNum is from 0 to 2.
    void pop(int stackNum);

    // Return the top element on stack stackNum, where stackNum is from 0 to 2.
    int top(int stackNum) const;

    bool isEmpty(int stackNum) const;
    bool isFull(int stackNum) const;

private:
    int numOfStack = 3;
    int *stackArray;
    int stackCapacity;
    int *stackCapacityUsed;
    int indexOfTop(int stackNum) const;
};

FixedMultiStack::FixedMultiStack(int stackCapacity)
    : stackCapacity(stackCapacity) {
    stackArray = new int[numOfStack * stackCapacity]{0};
    stackCapacityUsed = new int[numOfStack];
}

FixedMultiStack::~FixedMultiStack() {
    delete[] stackCapacityUsed;
    delete[] stackArray;
}

int FixedMultiStack::indexOfTop(int stackNum) const {
    return stackNum * stackCapacity + stackCapacityUsed[stackNum] - 1;
}

void FixedMultiStack::push(int stackNum, int value) {
    int index_top = indexOfTop(stackNum);

    if (isFull(stackNum)) return;

    stackArray[index_top] = value;
    stackCapacityUsed[stackNum]++;
}

void FixedMultiStack::pop(int stackNum) {
    if (isEmpty(stackNum)) return;
    stackArray[indexOfTop(stackNum)] = 0;
    stackCapacityUsed[stackNum]--;
}

bool FixedMultiStack::isEmpty(int stackNum) const {
    return (stackCapacityUsed[stackNum] == 0);
}

bool FixedMultiStack::isFull(int stackNum) const {
    return (stackCapacityUsed[stackNum] == stackCapacity);
}

int main() {
    FixedMultiStack fs(10);
    int arr[] = {100, 200, 300, 400, 500, 600};

    return 0;
}

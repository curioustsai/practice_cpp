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

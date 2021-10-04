class Node {
    Node* next{nullptr};
    int data;
    Node(int d): next{nullptr}, data(d) {};
};

class Stack {
    public: 
        int top() const;
        void pop();
        void push(int d);

   private:
        Node* topNode;
        Node* stack;
        int size;
};

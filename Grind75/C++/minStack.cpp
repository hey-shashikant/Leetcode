// Using Two Stacks

class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;
public:
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Using single stack.

class MinStack {
private:
    struct Node {
        int val;
        int min;
        Node* next;

        Node(int v, int m, Node* n) : val(v), min(m), next(n) {}
    };

    Node* head;

public:
    MinStack() : head(nullptr) {}

    void push(int val) {
        if (head == nullptr) {
            head = new Node(val, val, nullptr);
        } else {
            head = new Node(val, std::min(val, head->min), head);
        }
    }

    void pop() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int top() {
        if (head != nullptr) {
            return head->val;
        }
        return -1; // or throw an exception
    }

    int getMin() {
        if (head != nullptr) {
            return head->min;
        }
        return -1; // or throw an exception
    }

    ~MinStack() {
        while (head != nullptr) {
            pop();
        }
    }
};

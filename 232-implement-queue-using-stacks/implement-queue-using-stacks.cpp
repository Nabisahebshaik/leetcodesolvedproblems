class MyQueue {
public:
    stack<int> st;

    void transfer(stack<int> &firstSt, stack<int> &secondSt)
    {
        while (!firstSt.empty())
        {
            secondSt.push(firstSt.top());
            firstSt.pop();
        }
    }

    void push(int x) {
        st.push(x);
    }

    int pop() {
        stack<int> queueSt;
        transfer(st, queueSt);

        int val = queueSt.top();
        queueSt.pop();

        transfer(queueSt, st);
        return val;
    }

    int peek() {
        stack<int> queueSt;
        transfer(st, queueSt);

        int val = queueSt.top();

        transfer(queueSt, st);
        return val;
    }

    bool empty() {
        return st.empty();
    }
};
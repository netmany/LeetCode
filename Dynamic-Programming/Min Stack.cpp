/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
    stack<int> mOrig, mMins;
public:
    void push(int x) {
        mOrig.push(x);
        if(mMins.empty() || x <= mMins.top()) 
            mMins.push(x);
    }

    void pop() {
        if(mOrig.top() == mMins.top()) 
            mMins.pop();
        mOrig.pop();
    }

    int top() {
        return mOrig.top();
    }

    int getMin() {
        return mMins.top();
    }
};

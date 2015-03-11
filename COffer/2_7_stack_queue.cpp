// 两个栈实现一个队列

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    // 在队列末尾添加一个结点
    void appendTail(const T& node);

    // 删除队列的头结点
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template <typename T> void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
} 

template <typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size()<= 0)
    {
        while(stack1.size()>0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() == 0)
        throw new exception("queue is empty");

    T head = stack2.top();
    stack2.pop();

    return head;
}

// 两个队列实现一个栈

template <typename T> class CStack
{
public:
    CStack(void);
    ~CStack(void);
    
    // push
    void pushNode(const T& node);

    // pop
    T popNode();

private:
    queue <T> queue1;
    queue <T> queue2;
};

template <typename T> CStack<T>::CStack(void)
{
}

template <typename T> CStack<T>::~CStack(void)
{
}

template <typename T> void CStack<T>::pushNode(const T& element)
{
    queue1.push(element);
} 

template <typename T> T CStack<T>::popNode()
{
    T node;

    memset(&node, 0, sizeof(T));
    
    if (queue1.size() > 0)
    {
        while (queue1.size() > 1)
        {
            T& data1 = queue1.front();
            queue1.pop();
            queue2.push(data1);
        }
        
        node = queue1.front();    
        queue1.pop();

        return node;
    }
    else if (queue1.size() == 0 && queue2.size() > 0)
    {
        while (queue2.size() > 1)
        {
            T& data2 = queue2.front();
            queue2.pop();
            queue1.push(data2);
        }

        node = queue2.front();    
        queue2.pop();
    }
    else
    {
        printf("Stack is empty!\n");
    }

    return node;
} 

#include <iostream>
#include <queue>
#include <deque>
#include <vector>

// This function displays a queue of
// by repeatedly removing elements from the front
// Note that the queue is passed in by value so we
// don't affect the passed in queue.

template <typename T>
void display(std::queue<T> q)
{
    std::cout << "[ ";
    while (!q.empty())
    {
        T elem = q.front();
        q.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::queue<int> q; // By default, deque is used for implementation but other containers can be used to.
    std::stack<int, std::vector<int>> q1;
    std::stack<int, std::deque<int>> q2;

    for (int i : {1, 2, 3, 4, 5})
        q.push(i);
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while (!q.empty())
        q.pop();
    display(q);

    std::cout << "Size: " << q.size() << std::endl;

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;

    q.front() = 5; // Element can be modified
    q.back() = 5000; // Element can be modified

    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;

    return 0;
}

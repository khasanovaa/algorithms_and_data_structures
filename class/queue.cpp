#include<iostream>
#include<deque>
template <typename T, typename Container = std::deque<T>>
class Queue {
private:
	Container q;

public:
	Queue() {}
	T front() const {
		return *q.front();
	}
	T& front() {
		return *q.begin();
	}
	void pop() {
		q.pop_front();
	}
	void push(const T& n) {
		q.push_back(n);
	}
	size_t size() const {
		return q.size();
	}
	bool empty() const {
		return q.empty();
	}
	bool operator == (const Queue& p) const {
		return p.q == q;
	}
	bool operator != (const Queue& p) const {
		return p.q != q;
	}
};
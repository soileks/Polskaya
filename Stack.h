#pragma once
#include<string>
#include<iostream>
#include<map>

using namespace std;

template <typename T>
class Stack {
	size_t size;
	T* mem;
	int top;
public:
	Stack(size_t s = 10) {

		size = s;
		top = -1;
		//top = 0;
		mem = new T[size];
	}
	Stack(const Stack& st)
	{
		top = st.top;
		size = st.size;
		copy(st.mem, st.mem + size, mem);
	}
	size_t Size() {
		return top+1 ;
	}
	bool Is_Empty() {

		return top == -1;
	}
	bool Is_Full() {

		return top == size-1 ;
	}
	void Push(T val)
	{
		if (Is_Full())
		{
			T* tmp = new T[size * 2];
			copy(mem, mem + size, tmp);
			delete[] mem;
			mem = tmp;
			size *= 2;
		}
		top++;
		mem[top] = val;
		
	}
	void Pop() {
		if (Is_Empty()) {
			throw - 1;
		}
		top--;
	}
	T Top()
	{
		if (Is_Empty()) {
			throw - 1;
		}
		return mem[top];
	}

	friend ostream& operator << (ostream& ostr, Stack<T>& st) {
		for (int i = 0; i < st.Size(); i++) {
			ostr << st.mem[i] << " ";
		}
		return ostr;
	}


	~Stack()
	{
		delete[] mem;
	}
};
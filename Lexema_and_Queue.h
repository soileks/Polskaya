#pragma once
#include<string>
#include<iostream>
#include<map>
#include"Stack.h"
#include"Polsk.h"
using namespace std;

enum TypeElement {
	Operation,
	Value

};

class Lexema {
	string str;  //��������� �������� ����, ��� ������ �������
	TypeElement type; //�����(��� ��� �� �������)
public:
	Lexema(string _str = "  ", TypeElement _type = Operation) : str(_str), type(_type) {}; // �������� ���� �������� operation 
	string getStr() { return str; }
	TypeElement getType() { return type; }
	friend ostream& operator << (ostream& out, Lexema& p) {
		out << "{" << p.str << ", ";
		if (p.type == Operation) {
			out << "operation";
		}
		else if (p.type == Value) {
			out << "value";
		};
		out << "}";
		return out;
	}
};

//queue <Lexema> lex(string input) { // �� ���� ��������� �������, ������� �� ����� �������������
//	queue<Lexema>res;
//	input += ' ';
//	int i = 0;  //������� ������������ ������ � ������
//	string tmp = ""; //������������� ����� (��������, ��� �������� ���������� �����)
//	string op = "+-*/()";
//	string sep = " \n\t";
//	int state = 0;//��������� � ������� � �������� 
//	for (i = 0; i < input.size(); i++) {
//		char c = input[i]; //������ ������������ ������ � �������
//		int fres; //
//		switch (state)//����� ������� ���, ��� �� ������ ��� ������ ���������
//		{
//		case 0: // ��������
//			if (c >= '0' && c <= '9') {
//				tmp = c;
//				state = 1;//��������� � ���������  1 ,������� ������� , ��� �� ������ �������� ���������� �����
//				break;
//			}
//			fres = op.find(c);//� ������ �������� ���� ������� ������(������ ������ � ������� ��������) .���� �� ����� ������ �, �� ��� �� ��������
//			if (fres >= 0) {
//				tmp = c;//��������� ������ � �������
//				Lexema l(tmp, Operation);
//				res.push(l);//�������� � �������, ������� ������������ ��� �������� �����
//				state = 0;
//				break;
//			}
//			break;
//		case 1: // �����
//			if (c >= '0' && c <= '9') {//
//				tmp += c;//���������� ������ � �������
//				state = 1;
//				break;
//			}
//			fres = op.find(c);//��������� ��������� �� ��������(���� � ������ ��������)
//			if (fres >= 0) {//���� ��������
//				Lexema l1(tmp, Value);//�������� ����������� ����� � �������
//				res.push(l1);
//				tmp = c;
//				Lexema l2(tmp, Operation);//�������� ������ � �������
//				res.push(l2);
//				state = 0;
//				break;
//			}
//			fres = sep.find(c);//��������� �� ��, ��� ��������� �����������
//			if (fres >= 0) {
//				Lexema l(tmp, Value);//����� �������� � �������
//				res.push(l);
//				state = 0;
//				break;
//			}
//			break;
//		}
//	}
//	return res;
//}
//
//void print(queue <Lexema> t) {//������ �������
//	while (!t.empty()) {
//		cout << t.front() << endl;
//		t.pop();
//	}
//}

template <typename T>
class Queue {
private:
	size_t start;
	size_t end;
	T* p;
	size_t size;
	size_t next(int i) { return ((i + 1) % size); }

public:
	//Queue(){}

	Queue(size_t s = 1)
	{
		size = s;
		p = new T[size];
		end = 0;
		start = next(end);
	}
	size_t Size() { return size; }


	bool Is_Empty()
	{
		if (next(end) == start)
			return true;
		return false;
	}
	bool Is_Full() {
		if (next(next(end)) == start)
		{
			return true;
		}
		return false;
	}
	void Push(T val) {
		if (Is_Full())
		{
			throw - 1;

			//add_Mem();
		}
		end = next(end);
		p[end] = val;
	}
	Queue<T>& operator=(const Queue<T>& q) {
		if (this == &q)
			return *this;
		if (size > 0)
			delete[]p;
		size = q.size;
		end = q.end;
		start = q.start;
		p = new T[size]{};
		for (int i = start; i != next(end); i = next(i)) {
			p[i] = q.p[i];
		}
		return *this;
	}

	T  Pop() {
		if (Is_Empty())
		{
			throw - 2;
		}
		T v = p[start];
		start = next(start);
		return v;
	}
	~Queue()
	{
		if (size != 0)
			delete[] p;
	}
};

Queue<Lexema> que(string input) {
	int i = 0;
	string tmp = "";
	string op = "+-*/()";
	string sep = " \n\t";
	int state = 0;

	Queue<Lexema> res;
	input += ' ';
	for (i = 0; i < input.size(); i++) {
		char c = input[i]; //������ ������������ ������ � �������
		int fres;
		switch (state)//����� ������� ���, ��� �� ������ ��� ������ ���������
		{
		case 0: // ��������
			if (c >= '0' && c <= '9') {
				tmp = c;
				state = 1;//��������� � ���������  1 ,������� ������� , ��� �� ������ �������� ���������� �����
				break;
			}
			fres = op.find(c);//� ������ �������� ���� ������� ������(������ ������ � ������� ��������) .���� �� ����� ������ �, �� ��� �� ��������
			if (fres >= 0) {
				tmp = c;//��������� ������ � �������
				Lexema l(tmp, Operation);
				res.Push(l);//�������� � �������, ������� ������������ ��� �������� �����
				state = 0;
				break;
			}
			break;
		case 1: // �����
			if (c >= '0' && c <= '9') {//
				tmp += c;//���������� ������ � �������
				state = 1;
				break;
			}
			fres = op.find(c);//��������� ��������� �� ��������(���� � ������ ��������)
			if (fres >= 0) {//���� ��������
				Lexema l1(tmp, Value);//�������� ����������� ����� � �������
				res.Push(l1);
				tmp = c;
				Lexema l2(tmp, Operation);//�������� ������ � �������
				res.Push(l2);
				state = 0;
				break;
			}
			fres = sep.find(c);//��������� �� ��, ��� ��������� �����������
			if (fres >= 0) {
				Lexema l(tmp, Value);//����� �������� � �������
				res.Push(l);
				state = 0;
				break;
			}
			break;
		}
	}

	return res;
}

void print(Queue <Lexema> t) {//������ �������
	while (!t.Is_Empty()) {
		//cout << t.front() << endl;
		t.Pop();
	}
}
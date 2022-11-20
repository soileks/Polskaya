#pragma once
#include"Stack.h"
#include"Polsk.h"
#include"Lexema_and_Queue.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class polsk {

	int prior = 0;
	string in;
	vector<Lexema> vec;
	string op = "+-/*";
	Stack<Lexema> st;
	Queue<Lexema> result;

public:
	polsk(string input) {
		in = input;



		result = que(in);




	};
	/*void prioirity() {
		map<char, int> operations;
		operations.emplace('*', 2);
		operations.emplace('/', 2);
		operations.emplace('+', 1);
		operations.emplace('-', 1);
		operations.emplace('(', 0);
		operations.emplace(')', 0);
	}*/



	void func() {
		//char с;

		map<string, int> operations;
		operations.emplace('*', 2);
		operations.emplace('/', 2);
		operations.emplace('+', 1);
		operations.emplace('-', 1);
		operations.emplace('(', 0);
		operations.emplace(')', 0);

		while (!result.Is_Empty()) {
			Lexema l = result.Pop();
			//vec.push_back(l);
			switch (l.getType()) {

			case Operation:

				char s = l.getStr()[0];

				switch (s) {

				case '(':

					//prior = operations.find('(')->second;
					st.Push(l);
					break;
				case ')':
					if (!st.Is_Empty()) {


						if (st.Top().getStr() != ")")
						{
							while ((st.Top().getStr() != ")") || !st.Is_Empty()) {

								vec.push_back(st.Pop());

							}
						}
						if (st.Top().getStr() == ")") {

							st.Pop();
						}

					}
					else {
						throw - 4;
					}

					//prior = operations.find(')')->second;

					break;
				case '*':case'/':

					string c = st.Top().getStr();
					prior = operations[c];
					if (prior == 2) {
						vec.push_back(st.Pop());
					}

					else {
						st.Push(l);
					}
					break;

					/*if ((st.Top().getStr() == "*")|| (st.Top().getStr() == "/")) {
							vec.push_back(st.Pop());
						}*/

				case '+':case'-':

					string c = st.Top().getStr();
					prior = operations[c];

					while (prior == 2 || prior == 1) {
						vec.push_back(st.Pop());
						c = st.Top().getStr();
						prior = operations[c];
					}

					if (st.Is_Empty() || prior == 0) {
						st.Push(l);
					}
					break;

				}
				break;
			case Value:
				vec.push_back(l);
				break;
			}
		}
	}


	//лексический разбиват на лексемы. Синтаксический понимает принадлежит языку или нет ( проверяет что нет ошибок, перевод в обратную польскую)




};
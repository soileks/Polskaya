#include"Lexema_and_Queue.h"
#include <vector>
#include <string>
#include <iostream>
#include"Stack.h"
#include"Polsk.h"
#include<map>


using namespace std;


int  main() {
	//string str = "(123 -10)/ 50 *	\t	30 \n";
	//cout << str;
	//queue <Lexema> lex_res;
	//lex_res = lex(str);//�������� ����������� ����������
	//print(lex_res);
	//void func();

	string input = "(10+10)*4/2";
	//cout << "Input string: ";
	//cin >> input;
	cout <<"string: " << input << endl;
	polsk p(input);
	cout << "---------------------";
	p.print_que();
	cout << "---------------------";
	try {
		p.check();
	}
	catch (exception e) {
		cout << e.what();
		return 0;
	}
	try {
		//p.check();
		p.transl();
	}
	catch (exception e) {
		cout << e.what();
		
		return 0;
	}
	p.calc_stream();
	return 0;
}









//Queue<Lexema*>* que(string input) {
//	input += ' ';
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
//				res->Push(new Lexema(tmp, Operation));//�������� � �������, ������� ������������ ��� �������� �����
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
//				res->Push(new Lexema(tmp, Value));   // tak peredelay vse
//				tmp = c;
//				Lexema l2(tmp, Operation);//�������� ������ � �������
//				res->Push(new Lexema(tmp, Operation));
//				state = 0;
//				break;
//			}
//			fres = sep.find(c);//��������� �� ��, ��� ��������� �����������
//			if (fres >= 0) {
//				Lexema l(tmp, Value);//����� �������� � �������
//				res->Push(new Lexema(tmp, Value));
//				state = 0;
//				break;
//			}
//			break;
//		}
//	}
//	return res;
//}
//
//
//};
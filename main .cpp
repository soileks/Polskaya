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
	//lex_res = lex(str);//вызываем лексический анализатор
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
//		char c = input[i]; //символ обозреваемый сейчас в строчке
//		int fres; //
//		switch (state)//свитч говорит нам, что вы делаем при каждом состоянии
//		{
//		case 0: // операция
//			if (c >= '0' && c <= '9') {
//				tmp = c;
//				state = 1;//переходим в состояние  1 ,которое говорит , что мы сейчас пытаемся распознать число
//				break;
//			}
//			fres = op.find(c);//в строке операций ищем текущий символ(вернет индекс в массиве символов) .Если не нашли символ с, то это не операция
//			if (fres >= 0) {
//				tmp = c;//переводим символ в строчку
//				Lexema l(tmp, Operation);
//				res->Push(new Lexema(tmp, Operation));//помещаем в очередь, которая используется как выходной поток
//				state = 0;
//				break;
//			}
//			break;
//		case 1: // число
//			if (c >= '0' && c <= '9') {//
//				tmp += c;//прибавляем символ к строчке
//				state = 1;
//				break;
//			}
//			fres = op.find(c);//проверяем встретили ли операцию(ищем в строке операций)
//			if (fres >= 0) {//если операция
//				Lexema l1(tmp, Value);//помещаем накопленное число в очередь
//				res->Push(new Lexema(tmp, Value));   // tak peredelay vse
//				tmp = c;
//				Lexema l2(tmp, Operation);//операцию кладем в очередь
//				res->Push(new Lexema(tmp, Operation));
//				state = 0;
//				break;
//			}
//			fres = sep.find(c);//проверяем на то, что встретили разделитель
//			if (fres >= 0) {
//				Lexema l(tmp, Value);//число помещаем в очередь
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
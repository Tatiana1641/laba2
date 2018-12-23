#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//подсчёт количества слов с более чем и 4 символов
int cnt4(const string& str){
	int cnt = 0;
	stringstream ss;
	ss << str;
	string tmp;
	while(ss >> tmp){ if(tmp.size() <= 4) ++cnt; }
	return cnt;
}
int main(){
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	string input;//слово
	stringstream ss;	//строковый поток
	int cnt = 0;
	if(!in){
	  cout << "Ошибка открытия файла";
	  system("pause>>void");
	  return 0;
	}
	while(getline(in, input)){//считываем по предложению
	     cnt += cnt4(input);
	     ss << input << '\n'; //заносим в строковый поток

	}
	while(getline(ss, input)){
		cout << input << '\n';// выводим предложения
	}
	cout << "Количество слов: " << cnt;
	in.close();//закрываем файл										   
	system("pause>>void");
}
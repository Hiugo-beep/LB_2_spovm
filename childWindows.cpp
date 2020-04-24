#include <windows.h>
#include <process.h>//pid
#include<conio.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

	int pid;

	
	char eventName[5];
	
	for(int i=0;i<4;i++) //Формируется строка для вывода(номер процесса 4 раза подряд)
    eventName[i] = argv[0][0];  //создание 
	eventName[4] = '\0';
	HANDLE child = CreateEvent(NULL, FALSE, FALSE, L"1"); //доступ к событию по его имени
	HANDLE signalFromChild = CreateEvent(NULL, FALSE, FALSE, L"signal");//доступ к событию по его имени
	
		
	while (true) {
		WaitForSingleObject(child, INFINITE); //ожидание из родительского процесса 

		for (int i = 0; i < 5; i++) {
			cout << eventName[i] <<flush; //вывод слова с задержкой
			Sleep(200);
		}
		rewind(stdin);
		cout << "\t";
		SetEvent(signalFromChild); //включение родительского события в сигнальное состояние

	}
	return 0;
}

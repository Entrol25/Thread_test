//https://www.youtube.com/watch?v=iANv9una7-c 
#include <Windows.h> // WINAPI
//#pragma comment(lib,"Ws2_32.lib")// библиотека сокетов 
// & s 85 
//#include <WinSock2.h>// подкл сокеты / Sleep(75)
#include <iostream>// вывод в консоль / printf("Client connect...\n");
// & s 85 преобразование адресов 
//#include <WS2tcpip.h>// для работы с сервером 
//using namespace std;// мотает строки в консоли

HANDLE readThread;// Thread

int countth = 0;

DWORD WINAPI SerialRead(LPVOID lpParameter)
{
	for (int i = -1; i > -11; --i)
	{
		wprintf(L"Message 0: %d\n", i);
	}
	++countth;
	wprintf(L"--- 0 --- \n");
	ExitThread(0);
}
int main()//-----------------------------------------------------------------//
{
	readThread = CreateThread(NULL, 0, SerialRead, NULL, 0, NULL);

	/*while (true)
	{
		if (countth == 1) { break; }
	}*/

	// ожидает несколько потоков
	// WARNING! Не INFINITY , а INFINITE.============================
	//WaitForMultipleObjects(1, &readThread, TRUE, INFINITE);
	// 1 - кол-во потоков.
	// 2 - указатель на массив.
	// 3 - TRUE дождаться всех потоков. FALSE дождаться одного потока.
	// 4 - INFINITE ждать до бесконечности, или в милисекундах.
	
	// ожидает один поток
	WaitForSingleObject(readThread, INFINITE);
	wprintf(L"--- WaitForSingleObject() --- \n");
	//---------
	return 1;//
	system("pause"); // задержка консоли до нажатия любой клавиши
}
// stosmichal.cpp: definiuje punkt wejścia dla aplikacji konsolowej

#include "stdafx.h"
#include "my_data.h"
#include "stos.h"
#include "my_interface.h"
#include <malloc.h>	
#include <iostream>
#include <windows.h>
#include "messages.h"


using namespace std;



#pragma warning(disable : 4996)

int main()
{
	stack *top = NULL;
	void * pop_start = NULL;
	int wybor = 0;
	do
	{
		system("cls");
		cout << "przed rozpoczeciem operacji na stosie,nalezy go zainicjowac\n";
		menu();
		cout << endl;
		cin >> wybor;
		switch (wybor)
		{
		case INTERFACE_INIT:
			top=init(top);
			cout << endl;
			break;
		case INTERFACE_PUSH:
			top = pushmain(top);
			cout << endl;
			break;
		case INTERFACE_PRINT:
			if (top != NULL)
			{
				top->print_all(print);
				cout << endl;
			}
			else
			{
				error(There_Is_Nothing_To_Print);
			}
			break;
		case INTERFACE_SAVE:
			top->save_all(save);
			cout << endl;
			break;
		case INTERFACE_LOAD:
			top->load_all(top, load);
			cout << endl;
			break;
		case INTERFACE_CLEAR:
			if (top != NULL)
			{
				delete(top);
			}
			else
			{
				error(No_Elements_In_Stack);
			}
			top = NULL;
			break;
		case INTERFACE_POP:
			if (top != NULL)
			{
				pop_start = NULL;
				top = top->pop(top, pop_start);
				print(pop_start);
				cout << endl;
				delete(pop_start);
				pop_start = NULL;
			}
			else
			{
				error(No_Elements_In_Stack);
			}
			break;
		case INTERFACE_COMPARING:
			if (top->find(porownanie(), maincomparing))
			{
				cout << "element znajduje sie w stosie" << endl;
			}
			else
			{
				cout << "element nie znajduje sie w stosie" << endl;
			}

			break;
		default:
			if (wybor < 0 or wybor>8)
			{
				cout << "nie wybrales elementu z menu" << endl;
			}

		}
		system("pause");
		
	} while (wybor != 8);
	
	return 0;
}
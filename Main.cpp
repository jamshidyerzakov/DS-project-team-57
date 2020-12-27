#include <iostream>
#include <string> 
#include <windows.h>
#include "User.h"
#include "Seat.h"

using namespace std;

string Main_menu[2] = { "          R  E  G  I  S  T  E  R", "\t\tE  X  I  T" };
string Second_menu[2] = {"    R  E  S  E  R  V  A  T  I  O  N", "\t       E  X  I  T" };
string Third_menu[4] = {"   R E S E R V E    A N O T H E R    S E A T",  "       S E A T    I N F O R M A T I O N", "    C A N C E L    R E S E R V A T I O N", "\t       E  X  I  T\n\n" };
string menus[3] = { "  R  E  G  I  S  T  E  R       M  E  N  U", "    S  E  C  O  N  D     M  E  N  U\t", "        T  H  I  R  D     M  E  N  U\t" };

class UserNode {
public:
	User user;
	UserNode* next;
};

class SeatNode {
public:
	Seat seat;
	SeatNode* next;
};

int  color, sleep;
void first_menu(UserNode** head, SeatNode** seat_head);
void second_menu(UserNode** head, SeatNode** seat_head);
void third_menu(UserNode** head, SeatNode** seat_head);
void add_user_info(UserNode** head);
boolean print_seats(SeatNode* head);
void print_reserved_seats(SeatNode* node, UserNode* user_node);
void cancel_reservation(SeatNode* node);


void pressEsc() {   //asking to press space to continue
	cout << "\n\n        \t\t\t\tPress 'escape' to continue\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) != 0)
		{
			break;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void greeting()
{
	string title = "< F L I G H T   S E A T   R E S E R V A T I O N >";
	string welc = "W    E    L    C    O    M    E !";
	int len_text = title.length();
	int len_welc = welc.length();
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
	for (int x = 0; x < len_welc; x++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << welc[x];
		Sleep(35);
	}
	Sleep(2000);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
	for (int x = 0; x < len_text; x++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << title[x];
		Sleep(35);
	}
	Sleep(900);
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t ";
	Sleep(5000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
}
void display_text(string text, int color = 15, int sleep = 35) //font should be 40!!! (in cmd)
{
	int len_text = text.length();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\n\n\n\n\t\t\t\t";
	for (int x = 0; x < len_text; x++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << text[x];
		Sleep(30);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}
void display_text_no_ping(string text, int color = 15) //font should be 40!!! (in cmd)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << "\n\n\n\n\t\t\t\t";
	cout << text;

}

void second_menu(UserNode** head, SeatNode** seat_head)
{
	Sleep(150);
	int pointer_1 = 0;

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		display_text_no_ping(menus[1], color = 12);

		for (int i = 0; i < 2; ++i)
		{
			if (i == pointer_1) 
			{

				display_text_no_ping(Second_menu[i], 11);
			}
			else if (i == pointer_1 - 1 || pointer_1 + 1)
			{
				display_text_no_ping(Second_menu[i], 15);
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer_1 -= 1;
				if (pointer_1 == -1)
				{
					pointer_1 = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer_1 += 1;
				if (pointer_1 == 1)
				{
					pointer_1 = 1;
				}
				if (pointer_1 == 2)
				{
					pointer_1 = 0;
				}
				break;
			}
			else if ((GetAsyncKeyState(VK_ESCAPE) != 0))
			{
				Sleep(1000);
			}
			else if (GetAsyncKeyState(VK_SPACE) != 0)
			{
				switch (pointer_1)
				{
				case 0:
				{
					system("cls");
					if (print_seats(*seat_head)) {
						system("cls");
						display_text(menus[2], color = 12);
						display_text(Third_menu[0]);
						display_text(Third_menu[1]);
						display_text(Third_menu[2]);
						display_text(Third_menu[3]);
						third_menu(head, seat_head);
						Sleep(200);
					}
					else {
						system("cls");
						display_text(menus[1], color = 12);
						display_text(Second_menu[0]);
						display_text(Second_menu[1]);
						Sleep(200);
						second_menu(head, seat_head);

					}

					break;
				}
				break;
				case 1:
				{
					exit(1);
				}
				break;
				}

			}

		}

		Sleep(150);

	}
}
void first_menu(UserNode** head, SeatNode** seat_head)
{
	Sleep(200);
	int pointer = 0;
	while (true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		/*display_text_no_ping(menu_table);*/
		display_text_no_ping(menus[0], color = 12);
		for (int i = 0; i < 2; ++i)
		{
			if (i == pointer)
			{
				display_text_no_ping(Main_menu[i], 11);
			}

			else if (i == pointer - 1 || pointer + 1)
			{
				display_text_no_ping(Main_menu[i], 15);
			}

		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0) 
			{
				pointer -= 1; 
				if (pointer == -1)
				{
					pointer = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 1)
				{
					pointer = 1;
				}
				if (pointer == 2)
				{
					pointer = 0;
				}
				break;
			}
			else if ((GetAsyncKeyState(VK_ESCAPE) != 0))
			{
				exit(1);
				Sleep(150);
			}
			else if (GetAsyncKeyState(VK_SPACE) != 0)
			{
				switch (pointer)
				{
				case 0:
				{
					system("cls");
					add_user_info(head);
					Sleep(1500);
					system("cls");
					display_text(menus[1], color = 12);
					display_text(Second_menu[0]);
					display_text(Second_menu[1]);
					second_menu(head, seat_head);
					break;
				}
				break;
				case 1:
				{
					exit(1);
				}
				break;
				}

			}

		}

		Sleep(150);
	}
}
void third_menu(UserNode** head, SeatNode** seat_head) {
	system("cls");
	Sleep(150);
	int pointer1 = 0;
	while (true) {
		system("cls");
		display_text_no_ping(menus[2], 12);

		for (int i = 0; i < 4; ++i)
		{
			if (i == pointer1)
			{
				display_text_no_ping(Third_menu[i], 11);
			}
			else if (i == pointer1 - 1 || pointer1 + 1)
			{
				display_text_no_ping(Third_menu[i], 15);
			}
			else if (i == pointer1 - 2 || pointer1 + 2)
			{
				display_text_no_ping(Third_menu[i], 15);
			}
			else if (i == pointer1 - 3 || pointer1 + 3)
			{
				display_text_no_ping(Third_menu[i], 15);
			}
		}

		while (true && GetConsoleWindow() == GetForegroundWindow()) {
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer1 -= 1;
				if (pointer1 == -1)
				{
					pointer1 = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer1 += 1;
				if (pointer1 == 1)
				{
					pointer1 = 1;
				}
				if (pointer1 == 4)
				{
					pointer1 = 0;
				}
				break;
			}
			else if ((GetAsyncKeyState(VK_ESCAPE) != 0))
			{
				exit(1);
				Sleep(150);
			}
			else if (GetAsyncKeyState(VK_SPACE) != 0)
			{
				switch (pointer1)
				{

				case 0: {
					system("cls");
					print_seats(*seat_head);
					Sleep(1500);
					third_menu(head, seat_head);

					break;
				}

				case 1:
				{
					system("cls");
					print_reserved_seats(*seat_head, *head);
					Sleep(1500);
					third_menu(head, seat_head);
					break;

				}

				case 2:
				{
					system("cls");
					cancel_reservation(*seat_head);
					Sleep(1500);
					third_menu(head, seat_head);
					break;

				}

				case 3:
				{
					system("cls");
					exit(1);
					Sleep(1500);
					break;
				}
			   break;
				}

			}

		}
		Sleep(150);
	}

}

string randomString(int len)
{
	string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string newstr;
	int pos;
	while (newstr.size() != len) {
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr;
}

// node functions

void add_user_info(UserNode** head) {
	User user;
	string id=randomString(9), first_name, last_name;
	int age;
	display_text("Personal information", 12);

	user.setID(id);
	cout << "\n\n\t\t\tEnter your first name: "; cin >> first_name; user.setFirstName(first_name);
	cout << "\n\t\t\tEnter your last name: "; cin >> last_name; user.setSecondName(last_name);
	cout << "\n\t\t\tEnter your age: "; cin >> age; user.setAge(age);
	
	UserNode* new_node = new UserNode();
	UserNode* last = *head;
	new_node->user = user;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		pressEsc();
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;

	pressEsc();
	return;
}
void add_seat(SeatNode** head, Seat seat) {
	SeatNode* new_node = new SeatNode();
	SeatNode* last = *head;
	new_node->seat = seat;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;

	return;
}

boolean reserve_seat(SeatNode* head, string id) {
	SeatNode* current = head;
	while (current != NULL) {
		if (current->seat.getSeatID() == id && !current->seat.getReserved()) {
			current->seat.setReserved(true);
			return true;
		}
		current = current->next;
	}
	return false;
}
boolean cancel_seat(SeatNode* head, string id) {
	SeatNode* current = head;
	while (current != NULL) {
		if (current->seat.getSeatID() == id && current->seat.getReserved()) {
			current->seat.setReserved(false);
			return true;
		}
		current = current->next;
	}
	return false;
}


void print_user(UserNode* node)
{
	display_text("Your personal Information", 12);
	cout << "\n\t\t\tID\t\tName\t\tSurname\t\tAge\n\n";
	while (node != NULL)
	{	
		cout << "\t\t\t" << node->user.getID() << "\t" << node->user.getFirstName() << "\t\t" << node->user.getSecondName();
		cout << "\t\t" << node->user.getAge();
		node = node->next;
	}
}
boolean print_seats(SeatNode* node)
{		
	display_text("Available seats to reserve", 12);
	SeatNode* temp = node;
	cout << "\n\t\t\tID\tPrice\tType\t\tStatus\n\n";
	while (temp != NULL)
	{
		cout << "\t\t\t" << temp->seat.getSeatID() << "\t" << temp->seat.getPrice() << "\t" << temp->seat.getType();
		temp->seat.getReserved() ? cout << "\treserved\n\n" : cout << "\tnot reserved\n\n";

		temp = temp->next;
	}

	string id;
	cout << "\n\t\tEnter ID of the seat to reserve - "; cin >> id;
	boolean success = reserve_seat(node, id);
	if (success) {
		system("cls");
		display_text("\n\n\n\t\t\t\t\tR e s e r v e d!", 12);
		Sleep(1500);
		return true;
	}
	else {
		system("cls");
		display_text("\n\n\n\t\t\t\tNo such seat or it is already reserved!", 12);
		Sleep(1500);
		return false;
	}
}
void print_reserved_seats(SeatNode* node, UserNode* user_node) {
	print_user(user_node);
	pressEsc();
	system("cls");

	display_text("Seats that you reserved so far", 12);
	SeatNode* temp = node;
	cout << "\n\n\n\t\t\t\t\tID\tPrice\tType\t\t\n\n";
	while (temp != NULL)
	{
		if(temp->seat.getReserved()) {
			cout << "\t\t\t\t\t" << temp->seat.getSeatID() << "\t" << temp->seat.getPrice() << "\t" << temp->seat.getType() << "\n\n";
		}
		temp = temp->next;
	}
	pressEsc();
}

void cancel_reservation(SeatNode* node) {
	display_text("Seats that you reserved so far", 12);
	SeatNode* temp = node;
	cout << "\n\n\n\t\t\t\t\tID\tPrice\tType\t\t\n\n";
	while (temp != NULL)
	{
		if (temp->seat.getReserved()) {
			cout << "\t\t\t\t\t" << temp->seat.getSeatID() << "\t" << temp->seat.getPrice() << "\t" << temp->seat.getType() << "\n\n";
		}
		temp = temp->next;
	}

	string id;
	cout << "\n\t\tEnter ID of the seat to cancel - "; cin >> id;
	boolean success = cancel_seat(node, id);
	if (success) {
		system("cls");
		display_text("\n\n\n\t\t\t\t\tC a n c e l l e d!", 12);
		Sleep(1500);
		return;
	}
	else {
		system("cls");
		display_text("\n\n\n\t\t\t\tNo such seat or it is already cancelled!", 12);
		Sleep(1500);
		return;
	}
	pressEsc();
}
void initialize_seats(SeatNode** head) {
	for (int i = 1; i <= 5; i++) {
		Seat seat;
		double price = 50.0; bool is_reserved = false;
		string seat_id = to_string(i), type = "Econom\t";

		seat.setType(type); seat.setSeatID(seat_id);
		seat.setPrice(price); seat.setReserved(is_reserved);

		add_seat(head, seat);
	}

	for (int i = 6; i <= 10; i++) {
		Seat seat;
		double price = 100.0; bool is_reserved = false;
		string seat_id = to_string(i), type = "Bussiness";

		seat.setType(type); seat.setSeatID(seat_id);
		seat.setPrice(price); seat.setReserved(is_reserved);

		add_seat(head, seat);
	}

}

int main()
{
	
	UserNode* user_head = NULL;
	SeatNode* seat_head = NULL;
	initialize_seats(&seat_head);

	greeting();
	display_text(menus[0], color = 12);
	display_text(Main_menu[0]);
	display_text(Main_menu[1]);
	Sleep(300);
	first_menu(&user_head, &seat_head);
	Sleep(10000);
	system("pause");
	return  0;

}

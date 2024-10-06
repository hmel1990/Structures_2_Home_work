#include <iostream>
#include <string>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Device
{

	string type;		// тип устройства
	string name;		// наименование
	string model;		//модель
	string brand;		//бренд
	int waranty_period;	//срок гарантии в месяцах
	double price;		//цена
	Date date;			//дата продажи
};

void start_randomize() {
	srand(time(0));
	rand();
}
/*
void Device_user_input(Device& d) {
	cout << "Please, enter type for Device: ";
	getline(cin, d.type);
	cout << "Please, enter name of Device: ";
	getline(cin, d.name);
	cout << "Please, enter model of Device: ";
	getline(cin, d.model);
	cout << "Please, enter brand of Device: ";
	getline(cin, d.brand);

	cout << "Please, enter waranty peirod (month): ";
	cin >> d.waranty_period;


	d.price = rand() % 1000 + (rand() % 10 / 10.0);

	cout << "Please, enter date (year) of sel: ";
	cin >> d.date.year;
	cout << "Please, enter date (month) of sel: ";
	cin >> d.date.month;
	cout << "Please, enter date (day) of sel: ";
	cin >> d.date.day;
	cin.ignore();
}
//-функция проверки на срок гарантии
void Device_waranty(Device& d)
{
	Device today;
	cout << "Please, enter date (year): ";
	cin >> today.date.year;
	cout << "Please, enter date (month): ";
	cin >> today.date.month;
	cout << "Please, enter date (day): ";
	cin >> today.date.day;
	int total_days_today = today.date.year*365 + today.date.month * 30 + today.date.day;
	int waranty = d.waranty_period * 30;
	int total_days_sel = d.date.year * 365 + d.date.month * 30 + d.date.day;
	int x = total_days_today - total_days_sel;
	
	if (x < waranty)
	{
		cout << "Гарантия действительна\n";
	}
	else
	{
		cout << "Гарантия недействительна\n";
	}
}
*/


void Device_input_for_sale(Device &d) //чтобы не заполнять все поля в каждом из элементов массива, заполним только нужные для заданых функций
{
	cout << "Please, enter name of Device: ";
	getline(cin, d.name);

	cout << "Please, enter type for Device: ";
	getline(cin, d.type);

	d.price = rand() % 1000 + (rand() % 10 / 10.0);
}

void Device_input_for_sale_array(Device* arr, int size)
{

	for (int i = 0; i < size; i++)
	{
		Device_input_for_sale(arr[i]);
	}
}

//- подсчёт количества продаж по имени устройства за указанный срок
void Device_name_sale(Device* arr, int size)
{		
	int count = 0;

	string device_name;
	cout << "Please, enter Device name: ";
	getline(cin, device_name);

	for (int i = 0; i < size; i++)
	{
		if (arr[i].name == device_name)
		{
			count++;
		}
	}
	cout << "количество продаж устройства " << device_name << " = " << count << "\n";
}

//- вывод всех типов изделий, которые продавались

void Device_type_sale(Device* arr, int size)
{

	string* arr_2 = new string[size]; // массив куда будут записываться уникальные типы проданых девайсов

	arr_2[0] = arr[0].type;

	int y = 0;

	for (int i = 1; i < size; i++)
	{
		bool Unique = true;
		for (int j = 0; j < y; j++)
		{	
			int count = 0;
			if (arr[i].type == arr_2[j]) //сравниваем есть ли очередной елемент уже в списке с типами проданых девайсов
			{
				Unique = false;
				break;
			}
		}
		if (Unique) // если тип уникальный добавляем его в созданый массив
		{
			arr_2[y] = arr[i].type;
			y++;
		}

	}
	cout << "типов изделий, которые продавались " << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr_2[i] << "\n";
	}
	
	delete[]arr_2;
}


//- подсчет суммы всех продаж за указанный период
void Device_price_sale(Device* arr, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		count+= arr[i].price;
	}
	cout << "суммы всех продаж = " << count << "\n";
}



int main()
{
	setlocale(0, "");
	start_randomize();
	int size = 5;

	/*
	Device iphone; //для подсчета срока гарантии для одного устройства
	Device_user_input(iphone);
	Device_waranty(iphone);
	*/

	Device* iphone_sold = new Device[size]{};
	Device_input_for_sale_array(iphone_sold, size);
	Device_name_sale(iphone_sold, size);
	
	Device_type_sale (iphone_sold, size);

	Device_price_sale (iphone_sold, size);

	delete[]iphone_sold;
}


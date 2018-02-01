#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
using namespace std;
int set1[110], set2[110];
int counter_set1, counter_set2;
void set_sort()
{
	bool sort_set1[110] = { 0 }, sort_set2[110] = { 0 };
	for (int i = 0; i < counter_set1; i++)
	{
		sort_set1[set1[i]] = 1;
	}
	int counter = 0;
	for (int i = 0; i<110; i++)
	{
		if (sort_set1[i])
		{
			set1[counter++] = i;
		}
	}
	for (int i = 0; i < counter_set2; i++)
	{
		sort_set2[set2[i]] = 1;
	}
	counter = 0;
	for (int i = 0; i<110; i++)
	{
		if (sort_set2[i])
		{
			set2[counter++] = i;
		}
	}
}
void input()
{
	cout << "Enter number of set1 elements: ";
	cin >> counter_set1;
	cout << "Enter elements between 0-100: ";
	for (int i = 0; i < counter_set1; i++)
		cin >> set1[i];
	cout << "Enter number of set2 elements: ";
	cin >> counter_set2;
	cout << "Enter elements between 0-100: ";
	for (int i = 0; i < counter_set2; i++)
		cin >> set2[i];
	set_sort();
}
void ejtema()
{
	int i = 0, j = 0;
	bool indicator[110] = { 0 };
	int set_ejtema[110];
	while (i < counter_set1)
		indicator[set1[i++]] = 1;
	while(j < counter_set2)
		indicator[set2[j++]] = 1;
	int counter_set_ejtema = 0;
	for (int i = 0; i < 110; i++)
		if (indicator[i])
			set_ejtema[counter_set_ejtema++] = i;
	cout << "Ejtema: ";
	for (int i = 0; i < counter_set_ejtema; i++)
		cout << set_ejtema[i] << setw(3);
	cout << endl;
}
void eshterak()
{
	int i = 0, j = 0;
	bool indicator1[110] = { 0 },indicator2[110] = { 0 };
	int set_eshterak[110];
	while (i < counter_set1)
		indicator1[set1[i++]] = 1;
	while (j < counter_set2)
		indicator2[set2[j++]] = 1;
	int max_counter = (set1[counter_set1 - 1]>set2[counter_set2 - 1] ? set1[counter_set1 - 1] : set2[counter_set2 - 1]);
	int counter_set_eshterak = 0;
	for (int i = 0; i < max_counter; i++)
		if (indicator1[i] && indicator2[i])
			set_eshterak[counter_set_eshterak++] = i;
	cout << "Eshterak: ";
	for (int i = 0; i < counter_set_eshterak; i++)
		cout << set_eshterak[i] << setw(3);
	cout << endl;
}
void tafazol()
{
	int i = 0, j = 0;
	bool indicator1[110] = { 0 }, indicator2[110] = { 0 };
	int set_tafazol[110];
	while (i < counter_set1)
		indicator1[set1[i++]] = 1;
	while (j < counter_set2)
		indicator2[set2[j++]] = 1;
	int counter_set_tafazol = 0;
	for (int i = 0; i < 110; i++)
		if (indicator1[i] && !indicator2[i])
			set_tafazol[counter_set_tafazol++] = i;
	cout << "Tafazol: ";
	for (int i = 0; i < counter_set_tafazol; i++)
		cout << set_tafazol[i] << setw(3);
	cout << endl;
}
void tafazol_motegharen()
{
	int i = 0, j = 0;
	bool indicator1[110] = { 0 }, indicator2[110] = { 0 };
	int set_tafazol_motegharen[110];
	while (i < counter_set1)
		indicator1[set1[i++]] = 1;
	while (j < counter_set2)
		indicator2[set2[j++]] = 1;
	int counter_set_tafazol_motegharen = 0;
	for (int i = 0; i < 110; i++)
		if ((indicator1[i] && !indicator2[i])|| (!indicator1[i] && indicator2[i]))
			set_tafazol_motegharen[counter_set_tafazol_motegharen++] = i;
	cout << "Tafazol motegharen: ";
	for (int i = 0; i < counter_set_tafazol_motegharen; i++)
		cout << set_tafazol_motegharen[i] << setw(3);
	cout << endl;
}
int main()
{
	string head(70, '*'), middle(25, '*');
	bool CONTINUE = 1;
	do
	{
		system("cls");
		cout << head << endl
			<< middle << " MAJMOUE HAYE RIAZI " << middle << endl
			<< head << endl;
		input();
		cout << head << endl;
		ejtema();
		cout << head << endl;
		eshterak();
		cout << head << endl;
		tafazol();
		cout << head << endl;
		tafazol_motegharen();
		cout << head << endl;
		cout << "You want to continue? (1=yes, 0=no) ";
		cin >> CONTINUE;
	} while (CONTINUE);
	return 0;
}
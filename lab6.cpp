#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;
struct Customer
{
	char fio[64];
	char address[64];
	char name[32];
	double serial_number;
};

struct List
{
	Customer customer; 
	List *pNext; 
};


void addFirst(List *& pF, List* p)
{
	p->pNext = pF;
	pF = p;
}

List * delFirst(List *&pF) 
{
	if (pF == 0) return 0;
	List *p = pF;
	pF = pF->pNext;
	return p;

}

bool add(List *&pF, List * pZad, List *p)
{
	
	if (pZad == pF) 
	{
		p->pNext = pF;
		pF = p;
		return true;
	}

	List *pPred = pF; 
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false;
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
}

List * del(List*& pF, List *p) 
{
	if (pF == 0) return 0;
	if (pF == p) 
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		List *pPred = pF;
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0) return 0; 
		pPred->pNext = p->pNext;
		return p;
	}
	while (delFirst(pF)); 
}

int main(void)
{
	List *pF = 0; 
	List *p;
	char Ch; 
	do
	{
		p = (List *)malloc(sizeof(List));
		cout << endl << "FIO: ";
		fflush(stdin); 
		cin >> p->customer.fio;
		cout << "Address: ";
		fflush(stdin); 
		cin >> p->customer.address;
		cout << "Name of booking: ";
		fflush(stdin); 
		cin >> p->customer.name;
		cout << "Serial number: ";
		fflush(stdin); 
		cin >> p->customer.serial_number;
		addFirst(pF, p);
		printf("For continue press Y or y else any key! ");
		Ch = _getche();
	} while (Ch == 'Y' || Ch == 'y');
	
	for (List *pi = pF; pi; pi = pi->pNext)
		cout << endl << pi->customer.fio << " " << pi->customer.address << " " << pi->customer.name << " " <<  pi->customer.serial_number;

	
	for (List *pi = pF; pi->pNext;)
	{
		
		double min = pi->customer.serial_number;
		List *pmin = pi;
		for (List *pj = pi->pNext; pj; pj = pj->pNext)
			if (pj->customer.serial_number<min)
			{
			min = pj->customer.serial_number;
			pmin = pj;
			}
		if (pi != pmin)
		{
			del(pF, pmin);
			add(pF, pi, pmin);
		}
		else pi = pi->pNext;
	}
	
	cout << endl << "Srting: ";
	for (List *pi = pF; pi; pi = pi->pNext) 
		cout << endl << pi->customer.fio << " " << pi->customer.address << " " << pi->customer.name << " " << pi->customer.serial_number;
	cout << endl << "For exit press any key ";
	_getch();
	return 0;
}

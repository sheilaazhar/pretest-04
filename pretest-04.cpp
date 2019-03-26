/*
Nama		: Sheila Azhar Almufarida
NPM			: 140810180001
Kelas		: A
Tanggal Buat: 26 Maret 2019
Nama Program: pretest-04
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct ElemtList{
	char npm[14];
	char nama[40];
	float ipk;
	ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer list;

void createList(list& first){
	first=NULL;
}

void createElement(pointer& pBaru){
	pBaru=new ElemtList;
	cout<<"NPM	: ";cin>>pBaru->npm;
	cout<<"Nama	: "; cin.ignore();cin.getline(pBaru->nama,40);
	cout<<"IPK	: ";cin>>pBaru->ipk;
	pBaru->next=NULL;
}

void insertSortNPM(list& first, pointer pBaru){
	pointer Last;
    if (first==NULL){
        first=pBaru;
    }
    else {
        Last=first;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void tranversal(list first){
	cout<<"\t Data Mahasiswa \t"<<endl;
	cout<<"\nNo\t"<<"\tNPM\t\t"<<"Nama\t\t"<<"IPK\t"<<endl;
    pointer pBantu;
    pBantu=first;
    int i=1;
    while(pBantu != NULL){
        cout<<i<<"\t\t"<<pBantu->npm<<"\t\t"<<pBantu->nama<<"\t\t"<<pBantu->ipk<<endl;
        pBantu=pBantu->next;
        i++;
    }
}

int main(){
	pointer p;
    list mhs;
    int pilih;

    createList(mhs);
    while(1){
        system("cls");
        cout<<"Menu Mahasiswa"<<endl;
        cout<<"1. Tambah Data Mahasiswa "<<endl;
        cout<<"2. Tampilkan Data Mahasiswa"<<endl;
        cout<<"3. Keluar"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilih;
        switch(pilih){
        case 1:
            createElement(p);
            insertSortNPM(mhs, p);
        break;

        case 2:
            tranversal(mhs);
        break;

        case 3:
            return 0;
            break;
        }
        system("pause");
    }
}

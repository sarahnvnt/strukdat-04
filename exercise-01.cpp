/*
Nama 		: Sarah Navianti 
NPM 		: 140810180021
Deskripsi 	: program ini membuat data pegawai menggunakan singly linked
Tahun 		: 2019
**********/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Pegawai{
    char nama[100];
    char bidang[50];
    int gaji;
    Pegawai* next;
};
typedef Pegawai* pointer;
typedef pointer List;

void createList(List& First);
void createElemt(pointer& pBaru);
void insertFirst (List& First, pointer pBaru);
void insertLast (List& First, pointer pBaru);
void traversal (List First);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast (List& First, pointer& pHapus);

main()
{
    pointer p;
    List pgwai;
    int pilih;

    createList(pgwai);
    while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Insert First "<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Delete First"<<endl;
        cout<<"4. Delete Last"<<endl;
        cout<<"5. Traversal"<<endl;
        cout<<"6. Exit"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilih;
        switch(pilih){
        case 1:
            createElemt(p);
            insertFirst(pgwai, p);
        break;

        case 2:
            createElemt(p);
            insertLast(pgwai,p);
        break;

        case 3:
            deleteFirst(pgwai,p);
        break;

        case 4:
            deleteLast(pgwai,p);
        break;

        case 5:
            traversal(pgwai);
        break;

        case 6:
            return 0;
            break;
        }
        system("pause");
    }
}


void createList(List& First){
    First = NULL;
    }

void createElemt(pointer& pBaru){
    pBaru = new Pegawai;
    cout<<"Nama               : "; cin.ignore();cin.getline(pBaru->nama,100);
    cout<<"Bidang		      : "; cin>>pBaru->bidang;
    cout<<"Gaji               : "; cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast(List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru; //sambungkan
    }
}
void traversal(List First){
    cout<<"\nNo\t"<<"\tNama\t\t"<<"\tBidang/divisi\t"<<"Gaji\t"<<endl;
    pointer pBantu;
    pBantu=First;
    int i=1;
    while(pBantu != NULL){
        cout<<i<<"\t"<<pBantu->nama<<"\t\t\t"<<pBantu->bidang<<"\t\t"<<pBantu->gaji<<endl;
        pBantu=pBantu->next;
        i++;
    }
}

void deleteFirst(List& First, pointer& pHapus){
    if(First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada  yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast(List& First, pointer& pHapus){
    pointer Last, precLast;
    if (First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        Last=First;
        precLast=NULL;
        while (Last->next!=NULL){
            precLast=Last;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}

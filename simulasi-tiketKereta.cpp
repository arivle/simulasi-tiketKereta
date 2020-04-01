#include <iostream> 
using namespace std; 

// Representation of a node 
struct Kereta { 
	int data; 
	Kereta* next; 
}; 
int kursi=0;

// Function to insert node 
void kasihNomor(Kereta** root, int nomor) 
{ 
	Kereta* temp = new Kereta; 
	Kereta* ptr; 
	temp->data = nomor; 
	temp->next = NULL; 

	if (*root == NULL) 
		*root = temp; 
	else { 
		if(temp < *root){
			temp->next=*root;
			*root=temp;
			} else{
				ptr = *root; 
				while ((ptr->next != NULL) && (ptr->next->data<=temp->data)) 
				{ptr = ptr->next;
				temp->next=ptr->next;} 
				ptr->next = temp; 
	} 
	}
} 

void kursiTerpilih(Kereta* root, int nomor){
	Kereta* ini = new Kereta;
	Kereta* itu;
	cout<<"\nAnda memilih kursi nomor "<< nomor<<"\n";
	if(root->data==nomor){
		ini=root;
		root=root->next;
		delete ini;
		}
		else{
			itu=root;
			while ((itu->next!=NULL) && (itu->next->data!=nomor)) itu=itu->next;
			if (itu->next==NULL) cout<<" data tidak ada"<<endl;
			else {
				 root=itu->next;
				 itu->next=root->next;
				 delete root;
       }}
       cout<<"\n";
	}

void display(Kereta* root) 
{ 
	while (root != NULL) { 
		cout << root->data << " "; 
		root = root->next; 
	}
	cout<<endl; 
} 

Kereta *initGerbong(int arr[], int n) 
{ 
	Kereta *root = NULL; 
	for (int i = 0; i < n; i++) 
		kasihNomor(&root, arr[i]); 
return root; 
} 

Kereta *gantiKursi(Kereta *root, int m) 
{ 
	kasihNomor(&root, m); 
	return root; 
} 

// Driver code 
int main() 
{ 
	int pilihan;
	int nomorKursi[] = { 1, 2, 3, 4, 5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
	int n = sizeof(nomorKursi) / sizeof(nomorKursi[0]); 
	Kereta* root = initGerbong(nomorKursi, n);
	do
	{
		cout<<"Selamat Datang di Simulasi tiket kereta\n";
		cout<<"1. Pilih Kursi\n";
		cout<<"2. Pindah Kursi\n";
		cout<<"3. Batalkan Pemesanan\n";
		cout<<"4. Keluar\n";
		cout<<"Pilihan Anda : ";
		cin>>pilihan;
		if (pilihan < 1 || pilihan > 3){
			return false;}

		cout<<endl;
		switch(pilihan){
			case 1: 
			cout<<"silakan pilih kursi yang diinginkan\n";
			display(root); 
			cout<<"Pilihan Anda : ";
			cin>>kursi;
			kursiTerpilih(root, kursi);
			display(root);
			break;
			
			case 2:
			if(kursi == 0){
				cout<<"Anda kan belum pesan apa apa\n";	
				}
				else {
					display(root);
					int temp = kursi;
					gantiKursi(root, temp);
					kursi = 0;
					cout<<"silakan pilih kursi lain : ";
					cin>>kursi;
					kursiTerpilih(root, kursi);
					display(root);
					} 
			break;
			
			case 3: 
			if (kursi==0)
			{
				cout<<"apa yang mau dibatalkan? kan Anda belum pesan";
			} else {
				gantiKursi(root, kursi);
				cout<<"Anda berhasil membatalkan pemesanan tiket kereta\n";
			}
			break;
			
			case 4:
			return false;

		}
	}while(pilihan>1||pilihan<3); 
}


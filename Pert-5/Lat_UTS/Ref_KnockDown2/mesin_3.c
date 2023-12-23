#include "bismillah.h"

void createListbaris(list *L)
{
	(*L).first = NULL;
}

//fungsi untuk menghitung banyak element yang memiliki isi
int countElementbaris(list L)
{
	int hasil = 0;
	//pengecekan jika list nya bukan list kosong
	if(L.first != NULL)
	{
		eBaris* bantu;
		bantu = L.first;
		//perulangan selama nilai pada variabel hitung bukan -1
		//karena jika -1 maka artinya selanjutnya atau next adalah NULL yang artinya element yang berisi cukup sampai di situ
		while(bantu != NULL)
		{
			//hasil akan bertambah satu dan nilai variabel hitung akan berisi next dari element saat ini
			hasil = hasil + 1;
			bantu = bantu->next;
		}
	}
	return hasil;
}

//fungsi untuk menghitung banyak element yang memiliki isi
int countElementkolom(eBaris L)
{
	int hasil = 0;
	//pengecekan jika list nya bukan list kosong
	if(L.col != NULL)
	{
		eKolom* bantu;
		bantu = L.col;
		//perulangan selama nilai pada variabel hitung bukan -1
		//karena jika -1 maka artinya selanjutnya atau next adalah NULL yang artinya element yang berisi cukup sampai di situ
		while(bantu != NULL)
		{
			//hasil akan bertambah satu dan nilai variabel hitung akan berisi next dari element saat ini
			hasil = hasil + 1;
			bantu = bantu->next_kol;
		}
	}
	return hasil;
}

void addFirstbaris(databaris data1, list *L)
{
		// printf("check addfirstbaris\n");
		eBaris* baru; // bikin pointer
		baru = (eBaris*) malloc (sizeof (eBaris));
		baru->kontainer = data1;
        baru->col = NULL;

		//addfirst jika elementnya kosong
		if((*L).first == NULL)
		{
			baru->next = NULL;
		}
		//addfirst jika ada elementnya (tidak kosong)
		else
		{
			baru->next = (*L).first;
		}
		(*L).first = baru;
		baru = NULL;
}

void addFirstkolom(datakolom data2, eBaris *L)
{

		eKolom* baru; // bikin pointer
		baru = (eKolom*) malloc (sizeof (eKolom));
		baru->kontainer_kol = data2;

		//addfirst jika elementnya kosong
		if((*L).col == NULL)
		{
			baru->next_kol = NULL;
		}
		//addfirst jika ada elementnya (tidak kosong)
		else
		{
			baru->next_kol = (*L).col;
		}
		(*L).col = baru;
		baru = NULL;
}

void addAfterbaris(eBaris* prev, databaris data1)
{
	eBaris* baru;
	baru = (eBaris*) malloc (sizeof(eBaris));
	baru->kontainer = data1;
    baru->col = NULL;

	//jika ditambah pada elemen terakhir
	if(prev->next == NULL)
	{
		baru->next = NULL;
	}
	//jika ditambah pada elemen tengah atau yang ditentukan
	else
	{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru = NULL;
}

void addAfterkolom(eKolom* prev_kol, datakolom data2)
{
	eKolom* baru;
	baru = (eKolom*) malloc (sizeof(eKolom));
	baru->kontainer_kol = data2;

	//jika ditambah pada elemen terakhir
	if(prev_kol->next_kol == NULL)
	{
		baru->next_kol = NULL;
	}
	//jika ditambah pada elemen tengah atau yang ditentukan
	else
	{
		baru->next_kol = prev_kol->next_kol;
	}
	prev_kol->next_kol = baru;
	baru = NULL;
}

void addLastbaris(databaris data1, list *L)
{
	//jika elementnya kosong makan sama saja seperti menjalankan addfirst
	if((*L).first == NULL)
	{
		// printf("check addlastbaris\n");
		addFirstbaris(data1, L);
	}
	else
	{
			eBaris* prev = (*L).first;
			while(prev->next != NULL)
			{
				prev = prev->next;
			}
			addAfterbaris(prev, data1);
		}
}

void addLastkolom(datakolom data2, eBaris *L)
{
	//jika elementnya kosong makan sama saja seperti menjalankan addfirst
	if((*L).col == NULL)
	{
		addFirstkolom(data2, L);
	}
	else
	{
			eKolom* prev_kol = (*L).col;
			while(prev_kol->next_kol != NULL)
			{
				prev_kol = prev_kol->next_kol;
			}
			addAfterkolom(prev_kol, data2);
		}
}

void delFirstkolom(eBaris *L)
{
	if((*L).col != NULL)
	{
		eKolom* hapus = (*L).col;
		if(countElementkolom(*L) == 1)
		{
			(*L).col = NULL;
		}
		else
		{
			(*L).col = (*L).col->next_kol;
			hapus->next_kol = NULL;
		}
		free(hapus);
	}
	else
	{
		printf("list kosong\n");
	}
}

void delAfterkolom(eKolom* prev_kol)
{
	eKolom* hapus = prev_kol->next_kol;
	if(hapus != NULL)
	{
		//menghapus elemen terakhir
		if(hapus->next_kol == NULL)
		{
			prev_kol->next_kol = NULL;
		}
		//menghapus elemen tengah atau yang ditentukan (bukan akhir)
		else
		{
			prev_kol->next_kol = hapus->next_kol;
			hapus->next_kol = NULL;
		}
		free(hapus);
	}
}

void delLastkolom(eBaris *L)
{
	if((*L).col != NULL)
	{
		//jika hanya ada satu elemen
		if(countElementkolom(*L) == 1)
		{
			delFirstkolom(L);
		}
		//jika ada lebih dari satu elemen
		else
		{
			eKolom* last_kol = (*L).col;
			eKolom* prev_kol;

			while(last_kol->next_kol != NULL)
			{
				prev_kol = last_kol;
				last_kol = last_kol->next_kol;
			}
			delAfterkolom(prev_kol);
		}
	}
}

void delAllkolom(eBaris *L)
{
	int i;
	for(i = countElementkolom(*L); i >= 1; i--)
	{
		delLastkolom(L);
	}
}

void delFirstbaris(list *L)
{
	if((*L).first != NULL)
	{
		eBaris* hapus = (*L).first;
        if(hapus->col != NULL)
        {
            delAllkolom(hapus);
        }
		if(countElementbaris(*L) == 1)
		{
			(*L).first = NULL;
		}
		else
		{
			(*L).first = (*L).first->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
	else
	{
		printf("list kosong\n");
	}
}

void delAfterbaris(eBaris* prev, list *L)
{
	eBaris* hapus = prev->next;
	if(hapus != NULL)
	{
        if(hapus->col != NULL)
        {
            delAllkolom(hapus);
        }
		//menghapus elemen terakhir
		if(hapus->next == NULL)
		{
			prev->next = NULL;
		}
		//menghapus elemen tengah atau yang ditentukan (bukan akhir)
		else
		{
			prev->next = hapus->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

void delLastbaris(list *L)
{
	if((*L).first != NULL)
	{
		//jika hanya ada satu elemen
		if(countElementbaris(*L) == 1)
		{
			delFirstbaris(L);
		}
		//jika ada lebih dari satu elemen
		else
		{
			eBaris* last = (*L).first;
			eBaris* prev;

			while(last->next != NULL)
			{
				prev = last;
				last = last->next;
			}
			delAfterbaris(prev, L);
		}
	}
}

void delAllbaris(list *L)
{
	int i;
	for(i = countElementbaris(*L); i >= 1; i--)
	{
		delLastbaris(L);
	}
}

void printElement(list L) 
{
	// printf("check printelement\n");
  if(L.first != NULL) {
    // Jika list tidak kosong
    // Inisialisasi
    eBaris* bantu = L.first;
    int i = 1;

    while (bantu != NULL) {
      // Proses
      printf("%s\n", bantu->kontainer.nama);
      eKolom* bantu_kol = bantu->col;
      while(bantu_kol != NULL) {
        printf("- %s %d\n", bantu_kol->kontainer_kol.menu, bantu_kol->kontainer_kol.harga);
        bantu_kol = bantu_kol->next_kol;
      }
      printf("==================\n");
      // iterasi
      bantu = bantu->next;
      i += 1;

    }
  }else 
    // Proses jika list kosong
    printf("list kosong\n");
}

void sorting(list *L)
{
	int i, tukar;
	eBaris* prev;
	eBaris* tunjuk;
	eBaris* asoy;

	do{
                tukar = 0;
                prev = (*L).first; // deklarasi variabel now untuk ekemen pertama
                tunjuk = prev->next; //- deklarasi variabel after untuk elemen setelah now
				asoy = prev;
                for(i = 0; i < countElementbaris(*L)-1; i++)
				{
                    if(strcmp(prev->kontainer.nama, tunjuk->kontainer.nama)>0)
					{
						tukar = 1;
						
                        if(prev == (*L).first)
						{
							// printf("check 1\n");
							// printElement(*L);
							// kondisi kalo dua elemen doang
							if(tunjuk->next == NULL)
							{
								// printf("check 1.1\n");
								tunjuk->next = prev;
								prev->next = NULL;
								(*L).first = tunjuk;
								prev = tunjuk;
								tunjuk = tunjuk->next;
							}
							// kondisi jika banyak elemen
							else
							{
								// printf("check 1.2\n");
								prev->next = tunjuk->next;
								tunjuk->next = prev;
								(*L).first = tunjuk;
								// printElement(*L);
								asoy = tunjuk;
								prev = tunjuk;
								tunjuk = tunjuk->next;
							}
                        }
						else
						{
							// printf("check 2\n");
							asoy->next = tunjuk;
							prev->next = tunjuk->next;
							tunjuk->next = prev;

							prev = tunjuk;
							tunjuk = tunjuk->next;
						}
					} 
						if(prev == (*L).first)
						{
							// printf("check 3\n");
							prev = prev->next;
							tunjuk = tunjuk->next;
						}
						else 
						{
							// printf("check 4\n");
							asoy = asoy->next;
							prev = prev->next;
							tunjuk = tunjuk->next;
						}
                }
            }while(tukar == 1);
}

eBaris *getBaris(list L, char label[])
{
  eBaris *bantu = L.first;
  while(bantu != NULL)
  {
    if(strcmp(bantu->kontainer.nama, label) == 0)
    {
      return bantu;
    }
    bantu = bantu->next;
  }
  return 0;
}

eKolom *getKolom(list L, char label_baris[], char label_kolom[])
{
  eBaris *bantu1 = L.first;
  eKolom *bantu2;
  while(bantu1 != NULL)
  {
    if(strcmp(bantu1->kontainer.nama, label_baris) == 0)
    {
		bantu2 = bantu1->col;
		while(bantu2 != NULL)
		{
			if(strcmp(bantu2->kontainer_kol.menu, label_kolom) == 0)
			{
				return bantu2;
			}
			bantu2 = bantu2->next_kol;
		}
    }
    bantu1 = bantu1->next;
  }
  return NULL;
}

//getKolom(gerbaris(L, label))
// eKolom *getKolom(eBaris *L, char nama[])
// {
//   eKolom *bantu = (*L).first_col;
//   int ketemu = 0;
//   while((bantu != NULL) && (ketemu == 0))
//   {
//     if(strcmp(bantu->kontainer_col.nama, nama) == 0)
//     {
//       ketemu = 1;
//       return bantu;
//     }
//     bantu = bantu->next_col;
//   }
//   return 0;
// }

eKolom *getLastKolom(eBaris *L)
{
  eKolom *tunjuk= (*L).col; // -> tunjuknull
  eKolom *prev = tunjuk; // -> prev null
  while(tunjuk!= NULL) // -> kondisi jika tunjukngga null
  {
	prev = tunjuk;// -> berarti 
    tunjuk= tunjuk->next_kol;
  }
  return prev; // -> kalo tunjuknya null maka return last
}

void printkolom(list L, char label[])
{
	eBaris* tempe = getBaris(L, label);
	printf("%s\n", tempe->kontainer.nama);
      eKolom* bantu_kol = tempe->col;
      while(bantu_kol != NULL) {
        printf("- %s %d\n", bantu_kol->kontainer_kol.menu, bantu_kol->kontainer_kol.harga);
        bantu_kol = bantu_kol->next_kol;
      }
}

void sortingkolom(list *L, char label[])
{
	int tukar;
	eBaris* tempik = getBaris(*L, label);
	eKolom* prev_kol;
	eKolom* tunjuk_kol;
	eKolom* asoy_kol;
	do{
		tukar = 0;
		prev_kol = tempik->col; // deklarasi variabel now untuk ekemen pertama
		tunjuk_kol = prev_kol->next_kol; //- deklarasi variabel after untuk elemen setelah now
		asoy_kol = prev_kol;
		for(int i = 0; i < countElementkolom(*tempik)-1; i++)
		{
			if(strcmp(prev_kol->kontainer_kol.menu, tunjuk_kol->kontainer_kol.menu)>0)
			{
				tukar = 1;
				
				if(prev_kol == tempik->col)
				{
					// printf("check 1\n");
					// printElement(*L);
					// kondisi kalo dua elemen doang
					if(tunjuk_kol->next_kol == NULL)
					{
						// printf("check 1.1\n");
						tunjuk_kol->next_kol = prev_kol;
						prev_kol->next_kol = NULL;
						tempik->col = tunjuk_kol;
						prev_kol = tunjuk_kol;
						tunjuk_kol = tunjuk_kol->next_kol;
					}
					// kondisi jika banyak elemen
					else
					{
						// printf("check 1.2\n");
						prev_kol->next_kol = tunjuk_kol->next_kol;
						tunjuk_kol->next_kol = prev_kol;
						tempik->col = tunjuk_kol;
						// printElement(*L);
						asoy_kol = tunjuk_kol;
						prev_kol = tunjuk_kol;
						tunjuk_kol = tunjuk_kol->next_kol;
					}
				}
				else
				{
					// printf("check 2\n");
					asoy_kol->next_kol = tunjuk_kol;
					prev_kol->next_kol = tunjuk_kol->next_kol;
					tunjuk_kol->next_kol = prev_kol;

					prev_kol = tunjuk_kol;
					tunjuk_kol = tunjuk_kol->next_kol;
				}
			} 
				if(prev_kol == tempik->col)
				{
					// printf("check 3\n");
					prev_kol = prev_kol->next_kol;
					tunjuk_kol = tunjuk_kol->next_kol;
				}
				else 
				{
					// printf("check 4\n");
					asoy_kol = asoy_kol->next_kol;
					prev_kol = prev_kol->next_kol;
					tunjuk_kol = tunjuk_kol->next_kol;
				}
		}
	}while(tukar == 1);
}
void sortingkolomall(list *L)
{
	eBaris* tunjuk_row = (*L).first;
		while(tunjuk_row != NULL)
		{
			if(tunjuk_row->col != NULL)
			{
				sortingkolom(L, tunjuk_row->kontainer.nama);
			}
			else
			{
				// printf("ga punya kolom jadi mau sorting apa?\n");
			}
			tunjuk_row = tunjuk_row->next;
		}
}

void tukarLast(char labelA[], char labelB[], char namaTukar[], list *L)
{
	// inisialisasi pointer buat nyari baris mana yang mau dituer
  eBaris *barissatu = getBaris(*L, labelA); // baris asal
  eBaris *barisdua = getBaris(*L, labelB); // baris tujuan

	// pointer buatnyari kolom terakhir dibaris tujuan
  eKolom *lastKolomTokoB = getLastKolom(barisdua);
  if(lastKolomTokoB == NULL)
  {
	tukarFirst(labelA,labelB, namaTukar, L);
  }
  else
  {
		// pointer di kolom baris asal
	eKolom *tunjuk = barissatu->col;
	eKolom *prev = barissatu->col;

	int i = 1, ketemu = 0;
	while((tunjuk != NULL) && (ketemu == 0))
	{
		if(strcmp(tunjuk->kontainer_kol.menu, namaTukar) == 0 && i == 1)
		{
			// firstnya kolom di baris asal jadi tunjuk next
		barissatu->col = tunjuk->next_kol;
			// nexttnya kolom terakhir di baris tujuan jadi tunjuk
		lastKolomTokoB->next_kol = tunjuk;
		tunjuk->next_kol = NULL;
		ketemu = 1;
		}
		else if(strcmp(tunjuk->kontainer_kol.menu, namaTukar) == 0 && i != 1)
		{
		prev->next_kol = tunjuk->next_kol;
		lastKolomTokoB->next_kol = tunjuk;
		tunjuk->next_kol = NULL;
		ketemu = 1;
		}

		if(ketemu == 0)
		{
		prev = tunjuk;
		tunjuk = tunjuk->next_kol;
		i++;
		}
	}
  }
}

void tukarFirst(char labelA[], char labelB[], char namaTukar[], list *L)
{
	// inisialisasi pointer buat nyari baris mana yang mau dituer
  eBaris *barissatu = getBaris(*L, labelA); // baris asal
  eBaris *barisdua = getBaris(*L, labelB); // baris tujuan

	// pointer buatnyari kolom awal dibaris tujuan
  eKolom *firstKolomTokoB = barisdua->col;

	// pointer di kolom baris asal
  eKolom *tunjuk = barissatu->col;
  eKolom *prev = barissatu->col;

  int i = 1, ketemu = 0;
  while((tunjuk != NULL) && (ketemu == 0))
  {
	// kondisi kalo isi kolom sama inputan sama
    if(strcmp(tunjuk->kontainer_kol.menu, namaTukar) == 0 && i == 1)
    {
		// firstnya kolom di baris asal jadi tunjuk next
		// mindahin first ke nextnya
      barissatu->col = tunjuk->next_kol;
	  	// nexttnya kolom terakhir di baris tujuan jadi tunjuk
	  tunjuk->next_kol = firstKolomTokoB;
	  barisdua->col = tunjuk;
      ketemu = 1;
    }
    else if(strcmp(tunjuk->kontainer_kol.menu, namaTukar) == 0 && i != 1)
    {
      prev->next_kol = tunjuk->next_kol;
	  tunjuk->next_kol = firstKolomTokoB;
	  barisdua->col = tunjuk;
      ketemu = 1;
    }
    if(ketemu == 0)
    {
      prev = tunjuk;
      tunjuk = tunjuk->next_kol;
      i++;
    }
  }
}

void tukarAfter(char labelA[], char labelB[], char namaTukar1[], char namaTukar2[], list *L)
{
	// inisialisasi pointer buat nyari baris mana yang mau dituer
  eBaris *barissatu = getBaris(*L, labelA); // baris asal
  eBaris *barisdua = getBaris(*L, labelB); // baris tujuan

	// pointer buatnyari kolom awal dibaris tujuan
//   eKolom *firstKolomTokoA = getKolom(*L, labelA, namaTukar1);
  eKolom *kolomtujuan = getKolom(*L, labelB, namaTukar2);

	// pointer di kolom baris asal
  eKolom *tunjuk = barissatu->col;
  eKolom *prev = barissatu->col;

  int i = 1, ketemu = 0;
  if(kolomtujuan != NULL)
  {
	while((tunjuk != NULL) && (ketemu == 0))
	{
		// // kondisi kalo isi kolom sama inputan sama
		if(strcmp(tunjuk->kontainer_kol.menu, namaTukar1) == 0 && i == 1)
		{
			barissatu->col = tunjuk->next_kol;
			tunjuk->next_kol = kolomtujuan->next_kol;
			kolomtujuan->next_kol = tunjuk;
		ketemu = 1;
		}
		// kondisi yang di tuker bukan elemen pertama
		else if(strcmp(tunjuk->kontainer_kol.menu, namaTukar1) == 0 && i != 1)
		{
		prev->next_kol = tunjuk->next_kol;
		tunjuk->next_kol = kolomtujuan->next_kol;
		kolomtujuan->next_kol = tunjuk;
		ketemu = 1;
		}
		if(ketemu == 0)
		{
		prev = tunjuk;
		tunjuk = tunjuk->next_kol;
		i++;
		}
	}
  }
}

void tukarbeneran(char labelA[], char labelB[], char namaTukar1[], char namaTukar2[], list *L)
{
	eBaris *barissatu = getBaris(*L, labelA); // baris asal
	eBaris *barisdua = getBaris(*L, labelB); // baris tujuan

	// pointer buatnyari kolom awal dibaris tujuan
	//eKolom *firstKolomTokoA = getKolom(*L, labelA, namaTukar1);
  	eKolom *kolomtujuan1 = getKolom(*L, labelA, namaTukar1);
  	eKolom *kolomtujuan2 = getKolom(*L, labelB, namaTukar2);

	// pointer di kolom baris asal
	// printf(">%s", kolomtujuan1->kontainer_kol.kk);
	// printf(" %s<\n", kolomtujuan2->kontainer_kol.kk);
	// printf(">%s", barissatu->col->kontainer_kol.kk);
	// printf(" %s<\n", barisdua->col->kontainer_kol.kk);
  	eKolom *tunjuk1 = barissatu->col;
	eKolom *prev1 = barissatu->col;
	char temp[100];
	int i = 1, ketemu = 0;
	while((tunjuk1 != NULL) && (ketemu == 0))
		{
  			eKolom *tunjuk2 = barisdua->col;
			eKolom *prev2 = barisdua->col;
			while ((tunjuk2 != NULL) && (ketemu == 0))
			{
				printf("%d", ketemu);
				// printf("%s", tunjuk2->kontainer_kol.kk);
					strcpy(temp, prev2->kontainer_kol.menu);
					// printf(">>%s<<", temp);
				// kondisi kalo si asal ada di kolom ke 1
				if(strcmp(kolomtujuan1->kontainer_kol.menu, barissatu->col->kontainer_kol.menu) == 0)
				{
					// kondisi kalo si tujuan ada di kolom ke 1
					if(strcmp(kolomtujuan2->kontainer_kol.menu, barisdua->col->kontainer_kol.menu) == 0)
					{
						printf("check satu\n");
						tukarFirst(labelA, labelB, namaTukar1, L);
						tukarFirst(labelB, labelA, namaTukar2, L);
						ketemu = 1;
					}
					else
					{
						printf("check dua\n");
						tukarAfter(labelA, labelB, namaTukar1, namaTukar2, L);
						tukarFirst(labelB, labelA, namaTukar2, L);
						ketemu = 1;
					}
				}
				else
				{
					if(strcmp(kolomtujuan2->kontainer_kol.menu, barisdua->col->kontainer_kol.menu) == 0)
					{
						printf("check tiga\n");

						// printf("check\n");
						//         box_makanan || box_baju || roti_bakar || kemeja
						tukarAfter(labelB, labelA, namaTukar2, namaTukar1, L);
						//         box_makanan || box_baju || roti_bakar
						tukarFirst(labelA, labelB, namaTukar1, L);
						ketemu = 1;
					}
					else if(strcmp(kolomtujuan2->kontainer_kol.menu, tunjuk2->kontainer_kol.menu) == 0)
					{
						printf("check empat\n");
						// printf("check else yang eror\n");
						printf(">%s<\n", temp);
						//       box_baju || box_makanan || bikini || moci
						tukarAfter(labelB, labelA, namaTukar2, namaTukar1, L); 
						//       box_makanan || box_baju || moci || moci
						tukarAfter(labelA, labelB, namaTukar1, temp, L); 
						ketemu = 1;
					}
				}
				if(ketemu == 0)
				{
					// printf("<%d>\n",i);
					// printf(">> %s\n",tunjuk2->kontainer_kol.kk);
					prev2 = tunjuk2;
					tunjuk2 = tunjuk2->next_kol;
					i++;
				}
			}	
			if(ketemu == 0)
			{
				prev1 = tunjuk1;
				tunjuk1 = tunjuk1->next_kol;
				// i++;
			}
		}
}
/*
	2
	box_makanan bm1
	roti
	meki
	telor
	nasi
	moci
	end
	box_baju bb1
	kemeja
	barongsai
	bikini
	cangcut
	singlet
	end

	box_makanan roti
	box_baju kemeja

	box_makanan roti
	box_baju bikini

	box_makanan roti
	box_baju singlet

	box_makanan telor
	box_baju kemeja

	box_makanan telor (eror)
	box_baju bikini 

	box_makanan telor (eror)
	box_baju singlet 

	box_makanan moci
	box_baju kemeja

	box_makanan moci
	box_baju bikini

	box_makanan moci (eror)
	box_baju singlet
*/
 
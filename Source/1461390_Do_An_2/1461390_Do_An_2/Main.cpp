#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <conio.h>
#include <string.h> 
#include "Quan_Li_Doc_Gia.h"
#include "Quan_Li_Sach.h"
#include "Muon_Tra_Sach.h"

// Khai báo số lượng tĩnh cho dộc giả và sách:
#define MaxDG 1000
#define MaxSach 10000



/*
gsdgjashdjwujshdjshadkshkdhsjfhjsdsjhsdsshajkfhhjaskhdkjsadsjkahns,ahdkdsfsgdfgrgre55dsfdsfreffgdsscxvfdggfdvcvcvcx
ll;jlkhjklhj
*/
// Hàm Main:
void main()
 {
	printf("\n\t\t\tDo an 1 - Quan Ly Thu Vien");
	printf("\n\t\t\t\t\t\tTac gia: Vu Manh Hung. \n\t\t\t\t\t\tMSSV: 1461390\n");
	// Menu lệnh điều khiển chương trình.
	while (1)
	{
		printf("\n--------------------------Menu lenh Quan li Thu vien----------------------------\n");
		printf(" \t0.Thoat .\n");

		//Menu lệnh quản lí độc giả:
		printf(" \t11.Xem thong tin doc gia.\n");
		printf(" \t12.Cap nhat thong tin doc gia.\n");
		printf(" \t13.Chinh sua thong tin mot doc gia.\n");
		printf(" \t14.Xoa thong tin mot doc gia.\n");
		printf(" \t15.Tim doc gia theo CMND.\n");
		printf(" \t16.Tim doc gia theo Ho va Ten.\n");
		printf(" \t17.Thong ke so luong doc gia trong thu vien.\n");
		printf(" \t18.Thong ke so luong doc gia theo gioi tinh trong thu vien.\n");
		printf(" \t19.Thong ke so luong doc gia tre han.\n");
		printf("\n");

		//Menu lệnh quản lí sách:
		printf(" \t21.Xem thong tin sach.\n");
		printf(" \t22.Cap nhat thong tin sach.\n");
		printf(" \t23.Chinh sua thong tin sach.\n");
		printf(" \t24.Xoa thong tin mot quyen sach.\n");
		printf(" \t25.Tim sach theo ISBN.\n");
		printf(" \t26.Tim sach theo ten sach.\n");
		printf(" \t27.Thong ke so luong sach trong thu vien.\n");
		printf(" \t28.Thong ke so luong sach theo the loai trong thu vien.\n");
		printf(" \t29.Thong ke so luong sach duoc muon trong thu vien.\n");
		printf("\n");

		//Menu lệnh quản lí mượn trả sách:
		printf(" \t3.Lap phieu muon tra sach.\n");

		printf("\n--------------------------------------------------------------------------------");

		int chon;
		printf("\n\nChon: ");
		scanf_s("%d", &chon);

		if (chon == 0)
			break;
	
		switch (chon)
		{
		case 11:
			XemDG();
			printf("\n");
			break;
		case 12:
			ThemDG();
			printf("\n");
			break;
		case 13:
			int k;
			printf("Nhap so thu tu cua doc gia can chinh sua: ");
			scanf_s("%d", &k);
			MenuSua(k);
			break;
		case 14:
			int d;
			printf("Nhap so thu tu cua doc gia can xoa: ");
			scanf_s("%d", &d);
			XoaDG(d);
			break;
		case 15:
			char CM[10];
			printf("Nhap so CMND cua doc gia can tim: ");
			fflush(stdin);
			gets_s(CM);
			TimCMND(CM);
			break;
		case 16:
			char HT[25];
			printf("Nhap Ho va Ten cua doc gia can tim: ");
			fflush(stdin);
			gets_s(HT);
			TimTen(HT);
			break;
		case 17:
			printf("So luong doc gia trong thu vien la: %d", TKDGTV());
			break;
		case 18:
			TKDGGT();
			printf("\n");
			break;
		case 19:
			printf("So luong doc gia tra sach tre han la: %d", TKDGTreHan());
			printf("\n");
			break;
			
		

		
		case 21:
			XemSach();
			printf("\n");
			break;
		case 22:
			ThemSach();
			printf("\n");
			break;
		case 24:
			int ds;
			printf("Nhap so thu tu cua quyen sach can xoa: ");
			scanf_s("%d", &ds);
			XoaSach(ds);
			break;
		case 23:
			int h;
			printf("Nhap so thu tu cua quyen sach can chinh sua: ");
			scanf_s("%d", &h);
			MenuSuaSach(h);
			break;
		case 25:
			char IS[25];
			printf("Nhap ISBN cua quyen sach can tim: ");
			fflush(stdin);
			gets_s(IS);
			TimISBN(IS);
			break;
		case 26:
			char Sach[25];
			printf("Nhap Ten cua quyen sach can tim: ");
			fflush(stdin);
			gets_s(Sach);
			TimTenSach(Sach);
			break;
		case 27:
			printf("So luong sach trong thu vien la: %d", TKSachTV());
			break;
		case 28:
			TKSachTL();
			printf("\n");
			break;
		case 29:
			printf("So luong sach duoc muon la: %d", TKSachMuon());
			printf("\n");
			break;


		case 3:
			LapPhieuMuonTra();
			printf("\n");
			break;

		default:
			printf("Chuc nang khong ton tai. Vui long chon lai lenh khac!!!");
			break;
		}
	}
}
	
	
	


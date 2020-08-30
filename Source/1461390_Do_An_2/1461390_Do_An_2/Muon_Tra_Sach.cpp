#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include"Muon_Tra_Sach.h"
#include"Quan_Li_Doc_Gia.h"
#include"Quan_Li_Sach.h"

// Khai báo tĩnh số lượng sách và độc giả lớn nhất.
#define MaxSach 10000
#define MaxDG 1000

struct NGAY
{
	int ngay;
	int thang;
	int nam;
};

struct MUON
{
	char MSMuon[10];
	char ISBNMuon[10];
	NGAY ngaymuon;
	NGAY ngaytraDK;
};

struct TRA
{
	char MStra[10];
	NGAY ngaytraTT;
};
// Khai báo thông tin mượn trả sách.

NGAY NM[MaxDG];
NGAY NDK[MaxDG];
NGAY NTT[MaxDG];
MUON M[MaxDG];
TRA T[MaxDG];

int n; // Bien so luong phieu muon sach duoc lap 
int h; // Bien so luong phieu tra sach duoc lap
int demmuon = 0; // Bien dem so luong sach duoc muon
int sl[MaxSach]; // Bien so luong sach duoc muon boi mot doc gia trong mot lan



//------------------------------------------------ Hàm nhập thông tin cho phiếu mượn sách -------------------------------------------------
/*
Nhận vào: NM[MaxDG]; NDK[MaxDG]; M[MaxDG]; T[MaxDG]; int n
Trả về: Thông tin phiếu mượn.
*/
void NhapPhieuMuon()
{
	while (1)
	{
		if (n >= MaxDG)
			printf("Bo nho khong du. Vui long ngung nhap!!!");
		else
		while (n < MaxDG)
		{
			// Nhap ma doc gia:
			fflush(stdin);
			printf("\n Nhap ma doc gia muon sach: ");
			gets_s(M[n].MSMuon);

			// Nhap ngay muon sach:
			printf(" Nhap thoi diem muon sach:\n");
			printf("	Vui long nhap dung theo quy tac ngay thang nam!!!!\n");

			printf(" \tNhap ngay muon sach: ");
			scanf_s("%d", &NM[n].ngay);

			printf(" \tNhap thang muon sach: ");
			scanf_s("%d", &NM[n].thang);

			printf(" \tNhap nam muon sach: ");
			scanf_s("%d", &NM[n].nam);

			M[n].ngaymuon = NM[n];

			// Nhap ISBN danh sach cac sach ma doc gia muon:
			printf(" Nhap so luong sach doc gia muon: ");
			scanf_s("%d", &sl[n]);

			for (int j = 0; j < sl[n]; j++)
			{
				fflush(stdin);
				printf(" Nhap ISBN cua quyen sach thu %d: ", j + 1);
				gets_s(M[j].ISBNMuon);
				demmuon++;
			}
			n++;
			break;
		}
		break;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------ Hàm nhập thông tin cho phiếu trả sách ---------------------------------------------
/*
Nhận vào: NM[MaxDG]; NDK[MaxDG]; NTT[MaxDG]; M[MaxDG]; T[MaxDG]; int n
Trả về: Thông tin mã số độc giả mượn sách.
*/
void NhapPhieuTra()
{
	while (1)
	{
		if (h >= MaxSach)
			printf("Bo nho khong du. Vui long ngung nhap!!!");
		else
		while (h < MaxSach)
		{

			// Nhap ma doc gia tra sach:
			fflush(stdin);
			printf("\n Nhap ma doc gia tra sach: ");
			gets_s(T[h].MStra);
			
			// Nhập thời điểm trả sách thực tế:
			printf(" Vui long nhap dung theo quy tac ngay thang nam. Cam on!!!!\n");

			printf(" Nhap ngay tra sach thuc te : ");
			scanf_s("%d", &NTT[h].ngay);
			
			printf(" Nhap thang tra sach thuc te: ");
			scanf_s("%d", &NTT[h].thang);
			
			printf(" Nhap nam tra sach thuc te: ");
			scanf_s("%d", &NTT[h].nam);
			
			h++;
			break;
		}
		break;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------


//......................................................Tinh thoi gian tra sach du kien..............................................
void TraDuKien()
{
	//....................................... Xac dinh so ngay trong thang (SNTT) ..............................................
	int SNTT;
	switch (NM[n-1].thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		SNTT = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		SNTT = 30;
		break;
	case 2:
		if (NM[n-1].nam % 400 == 0)
			SNTT = 29;
		else
			SNTT = 28;
	}
	//..................................................................................................................

	//.............................................. Xac dinh ngay tra du kien .............................................
	
	// Xu ly cac ngay thuong:
	if (NM[n-1].ngay == SNTT)
	{
		NDK[n - 1].ngay = 6;
		NDK[n - 1].thang = NM[n - 1].thang + 1;
		NDK[n - 1].nam = NM[n - 1].nam;
	}
	else
	{
		NDK[n-1].ngay = NM[n-1].ngay + 6;
		if (NDK[n-1].ngay > SNTT)
		{
			NDK[n-1].ngay = NDK[n-1].ngay - SNTT;
			NDK[n-1].thang = NDK[n-1].thang + 1;

			if (NDK[n-1].ngay == 0)
			{
				NDK[n-1].ngay = SNTT;
				NDK[n-1].thang = NDK[n-1].thang;
			}
				
		}
		NDK[n-1].thang = NM[n-1].thang;
		NDK[n-1].nam = NM[n-1].nam;
	}

	// Xu ly nhung ngay cuoi nam
	if (NDK[n-1].thang > 12)
	{
		NDK[n-1].thang = 1;
		NDK[n-1].nam = NM[n-1].nam + 1;
	}

	//........................................................................................................................................
}
//-------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------- Xuat thong tin muon sach ------------------------------------------------------------------
/*
Nhận vào: NM[MaxDG]; NDK[MaxDG]; M[MaxDG]; T[MaxDG]; int n
Trả về: Thông tin phiếu mượn.
*/
void XuatPhieuMuon()
{

	printf("\n***************************** Phieu muon sach *********************************\n\n");
	// Xuat ma so doc gia muon sach:
	printf(" Ma so doc gia muon sach: ");
	puts(M[n-1].MSMuon);
	// Xuat thoi diem muon sach :
	NGAY muon = M[n-1].ngaymuon;
	printf(" Thoi diem muon sach cua do gia ma so %s la %d/%d/%d: ", M[n-1].MSMuon, muon.ngay, muon.thang, muon.nam);

	// Xuat thoi diem tra sach du kien:
	NGAY dk = M[n-1].ngaytraDK;
	printf("\n Thoi diem tra sach du kien cua doc gia co ma so %s la %d/%d/%d: ", M[n-1].MSMuon, dk.ngay, dk.thang, dk.nam);

	// Xuat danh sach cac sach duoc muon:
	printf("\n Danh sach ISBN cac sach duoc muon la:\n");
	for (int j = 0; j < sl[n-1]; j++)
	{
		printf(" \tISBN cua quyen sach thu %d: ", j + 1);
		puts(M[j].ISBNMuon);
	}

	// Xuat canh bao neu mat sach va tra sach tre:
	printf("\n Luu y: ");
	printf("\n Se phat 5000 dong/ngay neu tra sach qua han (Han muon sach la: 7 ngay)");
	printf("\n Neu mat sach se phai boi thuong 200%% gia sach.");

	printf("\n*******************************************************************************");
}
//-------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------ Tính khoảng cách giữa hai ngày -------------------------------------------

//......................... Xac dinh so ngay trong thang ........................................................
int SNTT(int thang, int nam)
{
	int SN;
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		SN = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		SN = 30;
		break;
	case 2:
		if (nam % 4 == 0 && nam % 100 != 0)
			SN = 29;
		else
			SN = 28;
	}
	return SN;
}
//..................................................................................................................

// Xac dinh so luong cac nam nhuan giua 1 nam bat ki va nam cong nguyen (nam 0):
int namnhuan(int nam)
{
	int dem = 0;
	for (int i = 0; i < nam; i++)
	{
		if (i % 4 == 0 && i % 100 != 0)
			dem++;
	}
	return dem;
}
//..................................................................................................................

// Xac dinh so luong cac thang co 30 ngay dung truoc mot thang bat ki trong 12 thang.
int thang30(int thang, int nam)
{
	int dem = 0;
	for (int i = 1; i < thang; i++)
	{

		if (SNTT(i, nam) == 30)
			dem++;
	}
	return dem;
}
//..................................................................................................................

// Xac dinh so luong cac thang co 31 ngay dung truoc mot thang bat ki trong 12 thang.
int thang31(int thang, int nam)
{
	int dem = 0;
	for (int i = 1; i < thang; i++)
	{

		if (SNTT(i, nam) == 31)
			dem++;
	}
	return dem;
}
//..................................................................................................................

//Tính khoảng cách một ngày dạng ngày, tháng, năm so với ngày, tháng, năm công nguyên. 
int ChuyenDoi(int ngay, int thang, int nam)
{
	int hthang, hnam;

	// Xac dinh so luong cac ngay giua 1 nam bat ki voi nam cong nguyen:
	hnam = (nam - 1) * 365 + namnhuan(nam);

	// Xac dinh so luong cac ngay giua 1 thang bat ki voi thang 0 co 0 ngay:
	if (thang == 1)
		hthang = 31;

	if (thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		if (nam % 4 == 0 && nam % 100 != 0)
			hthang = (thang - 1) * 31 - thang30(thang, nam) - 2;
		else
			hthang = (thang - 1) * 31 - thang30(thang, nam) - 3;
	}

	if (thang == 2)
	{
		if (nam % 100 != 0 && nam % 4 == 0)
			hthang = 29;
		else
			hthang = 28;
	}
	else
	{
		if (nam % 4 == 0 && nam % 100 != 0)
			hthang = (thang - 1) * 30 + thang31(thang, nam) - 1;
		else
			hthang = (thang - 1) * 30 + thang31(thang, nam) - 2;
	}
	int CD = ngay + hthang + hnam;
	return CD;
}
//..................................................................................................................

//--------------------------------------------------------------------------------------------------------------------------

//Tính tiền phải trả khi trả sách trễ hạn
int TienTre(int ngaytraTT, int thangtraTT, int namtraTT, int ngaytraDK, int thangtraDK, int namtraDK)
{
	int Tien;
	int KC = ChuyenDoi(ngaytraTT, thangtraTT, namtraTT) - ChuyenDoi(ngaytraDK, thangtraDK, namtraDK);
	if (KC <= 0)
		Tien = 0;
	else
		Tien = KC * 5000;
	return Tien;
}
//..................................................................................................................



//--------------------------------------------- Xuất thông tin trả sách --------------------------------------------------------
/*
Nhận vào: NM[MaxDG]; NDK[MaxDG]; NTT[MaxDG]; M[MaxDG]; T[MaxDG]; int n
Trả về: Thông tin phiếu trả sách
*/
void XuatPhieuTra()
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(M[i].MSMuon, T[h-1].MStra) == 0)
		{
			printf("\n***************************** Phieu tra sach *********************************\n\n");

			// Xuat ma so doc gia tra sach:
			printf(" Ma so doc gia tra sach: ");
			puts(M[i].MSMuon);

			// Xuat thoi diem muon sach:
			NGAY muon = M[i].ngaymuon;
			printf(" Thoi diem muon sach cua do gia ma so %s la %d/%d/%d: ", M[i].MSMuon, muon.ngay, muon.thang, muon.nam);

			// Xuat thoi diem tra sach du kien:
			NGAY dk = M[i].ngaytraDK;
			printf("\n Thoi diem tra sach du kien cua doc gia co ma so %s la %d/%d/%d: ", M[i].MSMuon, dk.ngay, dk.thang, dk.nam);

			// Xuat thoi diem tra sach thuc te:
			NGAY tt = T[i].ngaytraTT;
			printf("\n Thoi diem tra sach thuc te cua doc gia co ma so %s la %d/%d/%d: ", M[i].MSMuon, tt.ngay, tt.thang, tt.nam);

			// Xuat danh sach cac sach duoc muon:
			printf("\n Danh sach ISBN cac sach duoc muon la:\n");
			for (int j = 0; j < sl[i]; j++)
			{
				printf(" \tISBN cua quyen sach thu %d: ", j + 1);
				puts(M[j].ISBNMuon);
			}

			// Xuat so tien bi phat neu tra sach tre
			printf(" So tien phat khi tra sach tre la: %d dong", TienTre(tt.ngay, tt.thang, tt.nam, dk.ngay, dk.thang, dk.nam));

			printf("\n*******************************************************************************");

			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("Khong co thong tin doc gia tra sach!!!");
}
//-------------------------------------------------------------------------------------------------------------------------------------


/*********************************************************** Lập phiếu mượn trả sách *************************************************/
void LapPhieuMuonTra()
{
	while (1)
	{
		printf("\n\t------------------Menu lenh Lap phieu muon tra sach-----------------\n");
		printf(" \t\t30.Thoat lap phieu .\n");
		printf(" \t\t31.Lap phieu muon sach.\n");
		printf(" \t\t32.Lap phieu tra sach.\n");
		printf("\n\t--------------------------------------------------------------------");

		int chon;
		printf("\n\nChon: ");
		scanf_s("%d", &chon);

		if (chon == 30)
			break;

		switch (chon)
		{
		case 31:
			NhapPhieuMuon();
			TraDuKien();
			XuatPhieuMuon();
			break;
		case 32:
			NhapPhieuTra();
			TraDuKien();
			XuatPhieuTra();
			break;
		default:
			printf("Chuc nang khong ton tai. Vui long chon chuc nang khac!!!");
			break;
		}
	}
}
/********************************************************************************************************************************/



/*************************************** Thong ke doc gia tra sach tre han ****************************************/
/*
Nhận vào: NM[MaxDG]; NDK[MaxDG]; NTT[MaxDG]; M[MaxDG]; T[MaxDG]; int n
Trả về : Số lượng độc giả trả sách trễ hạn
*/
int TKDGTreHan()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (NTT[i].ngay > NDK[i].ngay || NTT[i].thang > NDK[i].thang || NTT[i].nam > NDK[i].nam)
			dem++;
	}
	return dem;
}
/********************************************************************************************************************************/




/*************************************** Thống kê số lượng sách được mượn ****************************************/
/* 
Trả về : Số lượng sách được mượn
*/
int TKSachMuon()
{
	return demmuon;
}
/********************************************************************************************************************************/

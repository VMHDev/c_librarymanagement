#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include"string.h"
#include"Quan_Li_Doc_Gia.h"

// Khai báo tĩnh số lượng lớn nhất của độc giả:
#define MaxDG 1000

// Dinh nghĩa cấu trúc dữ liệu thông tin quản lí sách:
struct NGAY
{
	int ngay;
	int thang;
	int nam;
};

struct DOCGIA
{
	char MS[10];
	char Ten[25];
	char CMND[10];
	char Sinh[11];
	char Gioi[4];
	char Email[20];
	char DiaChi[30];
	NGAY ngaylap;
	NGAY ngayhet;
};

// Khởi tạo biến đếm số luọng độc giả:
int m;

// Khởi tạo các mảng chứa thông tin quản lí sách:
DOCGIA DG[MaxDG];
NGAY NL[MaxDG];
NGAY NH[MaxDG];


//***************************************************** Hàm nhập thời gian lập thẻ *******************************************************
/*
Nhận vào: NL[MaxDG];
Trả về: Ngày, tháng, năm lập thẻ mượn sách.
*/
void NgayLap()
{
	printf(" \n  Vui long nhap dung theo quy tac ngay thang nam!!!!\n");

	printf(" \tNhap ngay lap the: ");
	scanf_s("%d", &NL[m].ngay);

	printf(" \tNhap thang lap the: ");
	scanf_s("%d", &NL[m].thang);

	printf(" \tNhap nam lap the: ");
	scanf_s("%d", &NL[m].nam);

	DG[m].ngaylap = NL[m];
}
//**************************************************************************************************************************************


//************************************************ Hàm xác định thời gian hết hạn của thẻ **********************************************
/*
Nhận vào: NL[MaxDG]; NH[MaxDG];
Trả về: Ngày, tháng, năm hết hạn thẻ mượn sách
*/
void NgayHet()
{
	NH[m].ngay = NL[m].ngay;
	NH[m].thang = NL[m].thang;
	NH[m].nam = NL[m].nam + 4;

	DG[m].ngayhet = NH[m];
}
//**************************************************************************************************************************************


/*************************************************** Hàm đọc file thông tin của độc giả ******************************************************/
/*
Nhận vào: DG[MaxDG]; NL[MaxDG]; NH[MaxDG];
Trả về: Thông tin file độc giả
*/
void Docfile()
{
	int i = 0;
	FILE*fp = fopen("DocGia.txt", "rt");
	if (fp == NULL)
		return;
	else
	{
		int c;
		while ((c=fgetc(fp))!=EOF)
		{
			fscanf(fp, "%d-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%d/%d/%d-%d/%d/%d.", &m, &DG[i].MS, &DG[i].Ten, &DG[i].CMND, &DG[i].Sinh, &DG[i].Gioi, &DG[i].Email, &DG[i].DiaChi, &NL[i].ngay, &NL[i].thang, &NL[i].nam, &NH[i].ngay, &NH[i].thang, &NH[i].nam);
			i++;
		}
	}
	fclose(fp);
}

/*************************************************** Hàm ghi file thông tin của độc giả ******************************************************/
/*
Nhận vào : DG[MaxDG]; NL[MaxDG]; NH[MaxDG];
Trả về : Cập nhật thông tin file độc giả
*/
void Ghifile()
{
	FILE*fp = fopen("DocGia.txt", "wt");
	if (fp == NULL)
		return;
	else
	{
		Docfile();
		fprintf(fp, "%d\n", 0);
		for (int i = 0; i < m; i++)
		{
			fprintf(fp, "%d-%s-%s-%s-%s-%s-%s-%s-%d/%d/%d-%d/%d/%d.\n", i + 1, DG[i].MS, DG[i].Ten, DG[i].CMND, DG[i].Sinh, DG[i].Gioi, DG[i].Email, DG[i].DiaChi, NL[i].ngay, NL[i].thang, NL[i].nam, NH[i].ngay, NH[i].thang, NH[i].nam);
		}
	}
	fclose(fp);
}

/***************************************************** Hàm xem thông tin của độc giả ******************************************************/
/*
Nhận vào : DG[MaxDG]; NL[MaxDG]; NH[MaxDG]; int m
Trả về : Thông tin của  tất cả các độc giả.
*/
void XemDG()
{
	Docfile();
	if (m <= 0)
	{
		printf("Danh sach doc gia trong. Hay tien hanh cap nhat!!!");
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			printf("\nThong tin doc gia thu %d: \n", i + 1);

			// Xem ma so cua doc gia:
			printf("\n Ma so doc gia thu %d: ", i + 1);
			puts(DG[i].MS);

			// Xem ten cua doc gia:
			printf(" Ten doc gia thu %d: ", i + 1);
			puts(DG[i].Ten);

			// Xem so CMND cua doc gia:
			printf(" So CMND doc gia thu %d: ", i + 1);
			puts(DG[i].CMND);

			// Xem ngay, thang, nam sinh cua doc gia:
			printf(" Ngay thang nam sinh cua doc gia thu %d: ", i + 1);
			puts(DG[i].Sinh);

			// Xem gioi tinh cua doc gia:
			printf(" Gioi tinh doc gia thu %d: ", i + 1);
			puts(DG[i].Gioi);

			// Xem Dia chi email cua doc gia:
			printf(" Dia chi email cua doc gia thu %d: ", i + 1);
			puts(DG[i].Email);

			// Xem Dia Chi cua doc gia:
			printf(" Dia chi cua doc gia thu %d: ", i + 1);
			puts(DG[i].DiaChi);

			// Xem ngay lap the cua doc gia:
			DG[i].ngaylap=NL[i];
			printf(" Thoi gian lap the cua doc gia thu %d la: %d/%d/%d ", i + 1, NL[i].ngay, NL[i].thang, NL[i].nam);

			// Xem ngay het han the cua doc gia:
			DG[i].ngayhet=NH[i];
			printf("\n Thoi gian het han the cua doc gia thu %d la: %d/%d/%d \n", i + 1, NH[i].ngay, NH[i].thang, NH[i].nam);
		}
	}
}
/********************************************************************************************************************************/


/*********************************************************** Hàm thêm độc giả ******************************************************/
/*
Nhận vào: DG[MaxDG]; NL[MaxDG]; NH[MaxDG]; int m
Trả về: Cập nhật thông tin file độc giả
*/
void ThemDG()
{
	while (1)
	{
		printf("\n\t------------------Menu lenh Cap nhat Thong tin doc gia--------------\n");
		printf(" \t\t120.Thoat cap nhat .\n");
		printf(" \t\t121.Cap nhat thong tin doc gia.\n");
		printf("\n\t--------------------------------------------------------------------");

		int chon;
		printf("\n\nChon: ");
		scanf_s("%d", &chon);
		if (chon != 120 && chon != 121)
			printf("Chuc nang khong ton tai. Vui long chon chuc nang khac!!!");

		if (chon == 120)
			break;

		if (chon == 121)
		{
			FILE *fp;
			fp = fopen("DocGia.txt", "at");
			if (fp != NULL)
			{
				Docfile();
				if (m >= MaxDG)
					printf("Bo nho khong du. Vui long ngung cap nhat doc gia!!!");
				else
				{
					while (m < MaxDG)
					{

						printf("Thong tin doc gia thu %d: \n", m + 1);
						fflush(stdin);

						// Them Ma so doc gia:
						printf(" Ma so doc gia thu %d: ", m + 1);
						fflush(stdin);
						gets_s(DG[m].MS);

						// Them Ten doc gia:
						printf(" Ten doc gia thu %d: ", m + 1);
						fflush(stdin);
						gets_s(DG[m].Ten);

						// Them CMND doc gia:
						printf(" So CMND doc gia thu %d: ", m + 1);
						fflush(stdin);
						gets_s(DG[m].CMND);

						// Them ngay, thang, nam sinh cua doc gia:
						printf(" Ngay thang nam sinh cua doc gia thu %d: ", m + 1);
						fflush(stdin);
						gets_s(DG[m].Sinh);

						// Them gioi tinh cua doc gia:
						printf(" Gioi tinh doc gia thu %d: ", m + 1);
						fflush(stdin);
						gets_s(DG[m].Gioi);

						// Them dia chi email doc gia:
						printf(" Dia chi email cua doc gia thu %d: ", m + 1);
						fflush(stdin);
						gets_s(DG[m].Email);

						// Them Dia Chi cua doc gia:
						printf(" Dia chi cua doc gia thu %d: ", m + 1);
						fflush(stdin);
						gets_s(DG[m].DiaChi);

						// Them ngay lap the cua doc gia:
						printf(" Nhap thoi gian lap the cua doc gia thu %d: ", m + 1);
						NgayLap();

						// Tu dong them ngay het han the cua doc gia:
						NgayHet();

						DG[m].ngaylap = NL[m];
						DG[m].ngayhet = NH[m];

						fprintf(fp, "%d-%s-%s-%s-%s-%s-%s-%s-%d/%d/%d-%d/%d/%d.\n", m + 1, DG[m].MS, DG[m].Ten, DG[m].CMND, DG[m].Sinh, DG[m].Gioi, DG[m].Email, DG[m].DiaChi, NL[m].ngay, NL[m].thang, NL[m].nam, NH[m].ngay, NH[m].thang, NH[m].nam);
					
						break;
					}
				}
			}
			fclose(fp);
		}
	}
}
/********************************************************************************************************************************/


/****************************************************** Hàm sửa thông tin độc giả ******************************************************/
/*
Nhận vào: DG[MaxDG]; NL[MaxDG]; NH[MaxDG]; int m; int k (Số thứ tự của độc giả cần chỉnh sửa)
Trả về: Thông tin của độc giả sau khi được chỉnh sửa.
*/
void SuaDG(int k)
{
	Docfile();
	if (k >= 0 && k <= m)
	{
		printf("\n\t---------------Menu lenh con Chinh Sua Thong tin doc gia-------------\n");

		printf(" \t\t1311.Chinh sua ma so doc gia.\n");
		printf(" \t\t1312.Chinh sua ten doc gia.\n");
		printf(" \t\t1313.Chinh sua CMND cua gia.\n");
		printf(" \t\t1314.Chinh sua ngay, thang, nam sinh cua doc gia.\n");
		printf(" \t\t1315.Chinh sua gioi tinh cua doc gia.\n");
		printf(" \t\t1316.Chinh sua email cua doc gia.\n");
		printf(" \t\t1317.Chinh sua dia chi doc gia.\n");
		printf(" \t\t1318.Chinh sua thoi gian lap the cua doc gia.\n");

		printf("\n\t--------------------------------------------------------------------");

		int chon;
		printf("\n\nChon muc can chinh sua cua doc gia thu %d trong menu lenh con: ", k);
		scanf_s("%d", &chon);

		if (chon == 1318)
		{
			int suangay, suathang, suanam;
		
			printf("Nhap noi dung can sua: \n");
			printf("Ngay lap the: ");
			scanf_s("%d", &suangay);
			printf("Thang lap the: ");
			scanf_s("%d", &suathang);
			printf("Nam lap the: ");
			scanf_s("%d", &suanam);

			NL[k - 1].ngay = suangay;
			NL[k - 1].thang = suathang;
			NL[k - 1].nam = suanam;
			
			DG[k - 1].ngaylap = NL[k - 1];

			NH[k - 1].ngay = suangay;
			NH[k - 1].thang = suathang;
			NH[k - 1].nam = suanam + 4;

			DG[k - 1].ngayhet = NH[k - 1];

		}
		else
		{
			fflush(stdin);
			char sua[30];
			printf("Nhap noi dung chinh sua: ");
			gets_s(sua);

			switch (chon)
			{
			case 1311:
				strcpy_s(DG[k - 1].MS, sua);
				break;
			case 1312:
				strcpy_s(DG[k - 1].Ten, sua);
				break;
			case 1313:
				strcpy_s(DG[k - 1].CMND, sua);
				break;
			case 1314:
				strcpy_s(DG[k - 1].Sinh, sua);
				break;
			case 1315:
				strcpy_s(DG[k - 1].Gioi, sua);
				break;
			case 1316:
				strcpy_s(DG[k - 1].Email, sua);
				break;
			case 1317:
				strcpy_s(DG[k - 1].DiaChi, sua);
				break;
			default:
				printf("Noi dung chinh sua khong ton tai vui long chon chuc nang khac!!!");
				break;
			}
		}
		Ghifile();
	}
	else
		printf("Du lieu thong tin doc gia can chinh sua khong co!\n Vui long thoat va chon lai so thu tu cua doc gia!");
}
/********************************************************************************************************************************/



/********************************************** Hàm xem thông tin độc giả sau khi sửa******************************************************/
/*
Nhận vào: DG[MaxDG]; NL[MaxDG]; NH[MaxDG]; int m; int k (Số thứ tự của độc giả cần  xem chỉnh sửa)
Trả về: Thông tin của độc giả sau khi được chỉnh sửa.
*/
void XemSuaDG(int k)
{
	Docfile();
	printf("\nThong tin doc gia thu %d sau khi duoc chinh sua la: \n", k);

	// Xem ma so cua doc gia:
	printf("\n Ma so doc gia thu %d: ", k);
	puts(DG[k - 1].MS);

	// Xem ten cua doc gia:
	printf(" Ten doc gia thu %d: ", k);
	puts(DG[k - 1].Ten);

	// Xem so CMND cua doc gia:
	printf(" So CMND doc gia thu %d: ", k);
	puts(DG[k - 1].CMND);

	// Xem ngay, thang, nam sinh cua doc gia:
	printf(" Ngay thang nam sinh cua doc gia thu %d: ", k);
	puts(DG[k - 1].Sinh);

	// Xem gioi tinh cua doc gia:
	printf(" Gioi tinh doc gia thu %d: ", k);
	puts(DG[k - 1].Gioi);

	// Xem Dia chi email cua doc gia:
	printf(" Dia chi email cua doc gia thu %d: ", k);
	puts(DG[k - 1].Email);

	// Xem Dia Chi cua doc gia:
	printf(" Dia chi cua doc gia thu %d: ", k);
	puts(DG[k - 1].DiaChi);

	// Xem ngay lap the cua doc gia:
	DG[k - 1].ngaylap = NL[k - 1];
	printf(" Thoi gian lap the cua doc gia thu %d la: %d/%d/%d", k, NL[k-1].ngay, NL[k-1].thang, NL[k-1].nam);

	// Xem ngay het han the cua doc gia:
	DG[k - 1].ngayhet = NH[k - 1];
	printf("\n Thoi gian het han the cua doc gia thu %d la: %d/%d/%d", k , NH[k-1].ngay, NH[k-1].thang, NH[k-1].nam);

}
/********************************************************************************************************************************/



/**************************************************** Hàm menu lệnh sửa *********************************************************/
/*
Nhận vào:  Số thứ tự của độc giả cần chỉnh sửa (k)
Trả về: Quản lí quá trình chỉnh sửa
*/
void MenuSua(int k)
{
	while (1)
	{
		printf("\n\t-----------Menu lenh main Chinh Sua Thong tin doc gia--------------\n");

		printf(" \t\t130.Thoat chinh sua .\n");
		printf(" \t\t131.Tiep tuc chinh sua thong tin doc gia thu %d.\n", k);
		printf(" \t\t132.Xem thong tin doc gia sau khi chinh sua.\n");

		printf("\n\t--------------------------------------------------------------------");

		int chon;
		printf("\n\nChon lenh trong menu main chinh sua: ");
		scanf_s("%d", &chon);

		if (chon == 130)
			break;

		switch (chon)
		{
		case 131:
			SuaDG(k);
			break;
		case 132:
			XemSuaDG(k);
			break;
		default:
			printf("Chuc nang khong ton tai. Vui long chon lenh khac!!!");
			break;
		}
	}
}
/********************************************************************************************************************************/

/***************************************************** Hàm Xóa độc giả **********************************************************/
/*
Nhận vào: DG[MaxDG]; NL[MaxDG]; NH[MaxDG]; int m; int d (Vị độc giả cần xóa)
Trả về: Xóa một độc giả trong thư viện
*/
void XoaDG(int d)
{
	Docfile();
	int flag = 0;
	if (d > 0 && d <= m)
	{
		for (int i = d-1; i < m - 1; i++)
		{
			// Tien hanh sao chep thong tin cua cac doc gia sau vao cac doc gia truoc tai vi tri doc gia bi xoa

			strcpy_s(DG[i].MS, DG[i + 1].MS);

			strcpy_s(DG[i].Ten, DG[i + 1].Ten);

			strcpy_s(DG[i].CMND, DG[i + 1].CMND);

			strcpy_s(DG[i].Sinh, DG[i + 1].Sinh);

			strcpy_s(DG[i].Gioi, DG[i + 1].Gioi);

			strcpy_s(DG[i].Email, DG[i + 1].Email);

			strcpy_s(DG[i].DiaChi, DG[i + 1].DiaChi);

			NL[i].ngay = NL[i + 1].ngay;
			NL[i].thang = NL[i + 1].thang;
			NL[i].nam = NL[i + 1].nam;

			DG[i].ngaylap = NL[i];

			NH[i].ngay = NH[i + 1].ngay;
			NH[i].thang = NH[i + 1].thang;
			NH[i].nam= NH[i + 1].nam;

			DG[i].ngayhet = NH[i];
		}
		m--;
		flag = 1;
	}
	if (flag == 1)
	{
		printf("\n Danh sach doc gia sau khi duoc xoa la:\n");
		Ghifile();
		XemDG();
	}
	else
		printf("Khong the thuc hien xoa. Vui long chon doc gia can xoa khac!!!");
}
/**********************************************************************************************************************************************/


/********************************************** Hàm tìm kiếm thông tin độc giả theo CMND ******************************************************/
/* 
Nhận vào: DG[MaxDG]; NL[MaxDG]; NH[MaxDG]; int m; char CM[] (Số CMND của độc giả cần tìm)
Trả về: Thông tin của độc giả cần tim
*/
void TimCMND(char CM[10])
{
	Docfile();
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		if (strcmp(DG[i].CMND, CM) == 0)
		{
			printf("\nThong tin cua doc gia can tim la:");
			// Xem ma so cua doc gia:
			printf("\n Ma so doc gia thu %d: ", i + 1);
			puts(DG[i].MS);

			// Xem ten cua doc gia:
			printf(" Ten doc gia thu %d: ", i + 1);
			puts(DG[i].Ten);

			// Xem so CMND cua doc gia:
			printf(" So CMND doc gia thu %d: ", i + 1);
			puts(DG[i].CMND);

			// Xem ngay, thang, nam sinh cua doc gia:
			printf(" Ngay thang nam sinh cua doc gia thu %d: ", i + 1);
			puts(DG[i].Sinh);

			// Xem gioi tinh cua doc gia:
			printf(" Gioi tinh doc gia thu %d: ", i + 1);
			puts(DG[i].Gioi);

			// Xem Dia chi email cua doc gia:
			printf(" Dia chi email cua doc gia thu %d: ", i + 1);
			puts(DG[i].Email);

			// Xem Dia Chi cua doc gia:
			printf(" Dia chi cua doc gia thu %d: ", i + 1);
			puts(DG[i].DiaChi);

			// Xem ngay lap the cua doc gia:
			DG[i].ngaylap = NL[i];
			printf(" Thoi gian lap the cua doc gia thu %d la %d/%d/%d: ", i + 1, NL[i].ngay, NL[i].thang, NL[i].nam);

			// Xem ngay het han the cua doc gia:
			DG[i].ngayhet = NH[i];
			printf("\n Thoi gian het han the cua doc gia thu %d la %d/%d/%d: \n", i + 1, NH[i].ngay, NH[i].thang, NH[i].nam);

			flag = 1;
		}
	}
	if (flag != 1)
		printf("\nKhong tim thay!!!");
}
/***************************************************************************************************************************************/


/****************************************** Hàm tìm kiếm thông tin độc giả theo họ và tên**********************************************/
/*
Nhận vào: G[MaxDG]; NL[MaxDG]; NH[MaxDG]; int m; char HT[] (Họ và tên độc giả cần tìm kiếm)
Trả về: Thông tin của độc giả cần tìm kiếm.
*/
void TimTen(char HT[25])
{
	Docfile();
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		if (strcmp(DG[i].Ten, HT) == 0)
		{
			
			printf("\nThong tin cua doc gia can tim la:");
			// Xem ma so cua doc gia:
			printf("\n Ma so doc gia thu %d: ", i + 1);
			puts(DG[i].MS);

			// Xem ten cua doc gia:
			printf(" Ten doc gia thu %d: ", i + 1);
			puts(DG[i].Ten);

			// Xem so CMND cua doc gia:
			printf(" So CMND doc gia thu %d: ", i + 1);
			puts(DG[i].CMND);

			// Xem ngay, thang, nam sinh cua doc gia:
			printf(" Ngay thang nam sinh cua doc gia thu %d: ", i + 1);
			puts(DG[i].Sinh);

			// Xem gioi tinh cua doc gia:
			printf(" Gioi tinh doc gia thu %d: ", i + 1);
			puts(DG[i].Gioi);

			// Xem Dia chi email cua doc gia:
			printf(" Dia chi email cua doc gia thu %d: ", i + 1);
			puts(DG[i].Email);

			// Xem Dia Chi cua doc gia:
			printf(" Dia chi cua doc gia thu %d: ", i + 1);
			puts(DG[i].DiaChi);

			// Xem ngay lap the cua doc gia:
			DG[i].ngaylap = NL[i];
			printf(" Thoi gian lap the cua doc gia thu %d la %d/%d/%d: ", i + 1, NL[i].ngay, NL[i].thang, NL[i].nam);

			// Xem ngay het han the cua doc gia:
			DG[i].ngaylap = NH[i];
			printf("\n Thoi gian het han the cua doc gia thu %d la %d/%d/%d: \n", i + 1, NH[i].ngay, NH[i].thang, NH[i].nam);

			flag = 1;
		}
	}
	if (flag != 1)
		printf("\nKhong tim thay!!!");
}
/********************************************************************************************************************************/



/****************************************** Hàm thống kê số lượng độc giả trong thư viện **********************************************/
/*
Nhận vào: int m
Trả về: Số lượng độc giả trong thư viện
*/
int TKDGTV()
{
	Docfile();
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		dem++;
	}
	return dem;
}
/********************************************************************************************************************************/



/****************************************** Hàm thống kê số lượng độc giả theo giới tính **********************************************/
/* 
Nhận vào: int m
Trả về: Số lượng độc giả theo giới tính trong thư viện
*/
void TKDGGT()
{
	Docfile();
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		dem = 0;
		for (int j = 0; j < m; j++)
		{
			if (strcmp(DG[i].Gioi, DG[j].Gioi) == 0)
			{
				if (i <= j)
					dem++;
				else
					break;
			}
		}
		if (dem != 0)
			printf("Gioi tinh %s co so luong doc gia la %d\n", DG[i].Gioi, dem);
	}

}
/********************************************************************************************************************************/

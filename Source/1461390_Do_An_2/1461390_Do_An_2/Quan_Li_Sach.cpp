#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include"string.h"
#include"Quan_Li_Sach.h"

// Khai báo tĩnh số lượng độc giả trong thư viện
#define MaxSach 10000

// Khởi tạo dữ liệu cấu trúc sách:
struct SACH
{
	char ISBN[10];
	char TenSach[50];
	char TacGia[20];
	char NhaXB[40];
	char NamXB[5];
	char TheLoai[15];
	char GiaSach[10];
	int SoLuong;
};

// Khai báo các thông tin quản lí sách
SACH SA[MaxSach];
int s; //Biến đếm số lượng sách trong thư viện.

/********************************************** Hàm đọc file thông tin của sách ******************************************************/
/*
Nhận vào: SA[MaxSach]; int s;
Trả về: Thông tin file sách
*/
void DocfileS()
{
	int i = 0;
	FILE*fp = fopen("Sach.txt", "rt");
	if (fp == NULL)
		return;
	else
	{
		int c;
		while ((c = fgetc(fp)) != EOF)
		{
			fscanf(fp, "%d-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%d.", &s, &SA[i].ISBN, &SA[i].TenSach, &SA[i].TacGia, &SA[i].NhaXB, &SA[i].NamXB, &SA[i].TheLoai, &SA[i].GiaSach, &SA[i].SoLuong);
			i++;
		}
	}
	fclose(fp);
}
/********************************************************************************************************************************/

/********************************************** Hàm ghi file thông tin của sách ******************************************************/
/*
Nhận vào: SA[MaxSach]; int s;
Trả về: Cập nhật thông tin file sách
*/
void GhifileS()
{
	FILE*fp = fopen("Sach.txt", "wt");
	if (fp == NULL)
		return;
	else
	{
		DocfileS();
		fprintf(fp, "%d\n", 0);
		for (int i = 0; i < s; i++)
		{
			fprintf(fp, "%d-%s-%s-%s-%s-%s-%s-%s-%d.\n", i + 1, SA[i].ISBN, SA[i].TenSach, SA[i].TacGia, SA[i].NhaXB, SA[i].NamXB, SA[i].TheLoai, SA[i].GiaSach, SA[i].SoLuong);
		}
	}
	fclose(fp);
}
/********************************************************************************************************************************/

/***************************************************** Hàm xem thông tin sách ******************************************************/
/*
Nhận vào: SA[MaxSach]; int s;
Trả về: Thông tin độc giả
*/
void XemSach()
{
	DocfileS();
	if (s <= 0)
	{
		printf("Danh sach cac quyen sach trong. Hay tien hanh cap nhat!!!");
	}
	else
	{
		int i = 0;
		while (i < s)
		{
			printf("\nThong tin quyen sach thu %d: \n", i + 1);

			// Xem ISBN cua sach:
			printf("\n ISBN cua quyen sach thu %d: ", i + 1);
			puts(SA[i].ISBN);

			// Xem ten cua quyen sach:
			printf(" Ten cua quyen sach thu %d: ", i + 1);
			puts(SA[i].TenSach);

			// Xem ten cua tac gia:
			printf(" Ten tac gia cua quyen sach thu %d: ", i + 1);
			puts(SA[i].TacGia);

			// Xem nha xuat ban cua quyen sach:
			printf(" Nha xuat ban cua quyen sach thu %d: ", i + 1);
			puts(SA[i].NhaXB);

			// Xem nam xuat ban cua quyen sach:
			printf(" Nam xuat ban cua quyen sach thu %d: ", i + 1);
			puts(SA[i].NamXB);

			// Xem the loai cua quyen sach:
			printf(" The loai cua quyen sach thu %d: ", i + 1);
			puts(SA[i].TheLoai);

			// Xem gia cua quyen sach:
			printf(" Gia cua quyen sach thu %d: ", i + 1);
			puts(SA[i].GiaSach);

			// Xem so luong cua quyen sach:
			printf(" So luong cua quyen sach thu %d la: %d", i + 1, SA[i].SoLuong);
			
			i++;
		}
	}
}
/********************************************************************************************************************************/


/******************************************************** Hàm thêm sách ******************************************************/
/*
Nhận vào: SA[MaxSach]; int s;
Trả về: Cập nhật thông tin sách
 */
void ThemSach()
{
	while (1)
	{
		printf("\n\t------------------Menu lenh Cap nhat Thong tin sach--------------\n");
		printf(" \t\t220.Thoat cap nhat .\n");
		printf(" \t\t221.Cap nhat thong tin sach.\n");
		printf("\n\t-----------------------------------------------------------------");

		int chon;
		printf("\n\nChon: ");
		scanf_s("%d", &chon);
		if (chon != 220 && chon != 221)
			printf("Chuc nang khong ton tai. Vui long chon chuc nang khac!!!");

		if (chon == 220)
			break;

		if (chon == 221)
		{
			FILE *fp;
			fp = fopen("Sach.txt", "at");
			if (fp != NULL)
			{
				DocfileS();
				if (s >= MaxSach)
					printf("Bo nho khong du. Vui long ngung cap nhat doc gia!!!");
				while (s < MaxSach)
				{

					printf("Thong tin quyen sach thu %d: \n", s + 1);
					fflush(stdin);

					// Them ISBN cua quyen sach:
					printf(" ISBN quyen sach thu %d: ", s + 1);
					gets_s(SA[s].ISBN);

					// Them ten quyen sach:
					printf(" Ten quyen sach thu %d: ", s + 1);
					gets_s(SA[s].TenSach);

					// Them ten tac gia cua quyen sach:
					printf(" Ten tac gia cua quyen sach thu %d: ", s + 1);
					gets_s(SA[s].TacGia);

					// Them nha xuat ban cua quyen sach:
					printf(" Nha xuat ban cua quyen sach thu %d: ", s + 1);
					gets_s(SA[s].NhaXB);

					// Them nam xuat ban cua quyen sach:
					printf(" Nam xuat ban cua quyen sach thu %d: ", s + 1);
					gets_s(SA[s].NamXB);

					// Them the loai cua quyen sach:
					printf(" The loai cua quyen sach thu %d: ", s + 1);
					gets_s(SA[s].TheLoai);

					// Them gia sach cua quyen sach:
					printf(" Gia sach cua quyen sach thu %d: ", s + 1);
					gets_s(SA[s].GiaSach);

					// Them so luong cua quyen sach:
					printf(" So luong cua quyen sach thu %d: ", s + 1);
					scanf_s("%d", &SA[s].SoLuong);

					fprintf(fp, "%d-%s-%s-%s-%s-%s-%s-%s-%d.\n", s + 1, SA[s].ISBN, SA[s].TenSach, SA[s].TacGia, SA[s].NhaXB, SA[s].NamXB, SA[s].TheLoai, SA[s].GiaSach, SA[s].SoLuong);

					break;
				}
			}
			fclose(fp);
		}
	}
}
/********************************************************************************************************************************/

/*************************************************** Hàm sửa thông tin sách ******************************************************/

	//---------------------------------------------- Hàm sửa thông tin sách ------------------------------------------
/*
Nhận vào: Số thứ tự của quyển sách cần chỉnh sửa: h
Trả về: Thông tin sửa sách
*/
void SuaSach(int h)
{
	DocfileS();
	if (h >= 0 && h <= s)
	{
		printf("\n\t---------------Menu lenh con Chinh Sua Thong tin doc gia-------------\n");

		printf(" \t\t2311.Chinh sua ISBN cua quyen sach.\n");
		printf(" \t\t2312.Chinh sua ten sach.\n");
		printf(" \t\t2313.Chinh sua tac gia cua quyen sach.\n");
		printf(" \t\t2314.Chinh sua nha xuat ban cua quyen sach.\n");
		printf(" \t\t2315.Chinh sua nam xuat ban cua quyen sach.\n");
		printf(" \t\t2316.Chinh sua the loai cua quyen sach.\n");
		printf(" \t\t2317.Chinh sua gia ban cua quyen sach.\n");
		printf(" \t\t2318.Chinh sua so luong cua moi quyen sach.\n");

		printf("\n\t--------------------------------------------------------------------");

		int chon;
		printf("\n\nChon muc can chinh sua cua quyen sach thu %d trong menu lenh con: ", h);
		scanf_s("%d", &chon);

		if (chon == 2318)
		{
			int suaSL;
			printf("Nhap noi dung chinh sua: ");
			scanf_s("%d", &suaSL);
			SA[h - 1].SoLuong = suaSL;
		}
		else
		{
			fflush(stdin);
			char sua[30];
			printf("Nhap noi dung chinh sua: ");
			gets_s(sua);

			switch (chon)
			{
			case 2311:
				strcpy_s(SA[h - 1].ISBN, sua);
				break;
			case 2312:
				strcpy_s(SA[h - 1].TenSach, sua);
				break;
			case 2313:
				strcpy_s(SA[h - 1].TacGia, sua);
				break;
			case 2314:
				strcpy_s(SA[h - 1].NhaXB, sua);
				break;
			case 2315:
				strcpy_s(SA[h - 1].NamXB, sua);
				break;
			case 2316:
				strcpy_s(SA[h - 1].TheLoai, sua);
				break;
			case 2317:
				strcpy_s(SA[h - 1].GiaSach, sua);
				break;
			default:
				printf("Muc chinh sua khong ton tai!!!");
				break;
			}
		}
		GhifileS();
	}
	else
		printf("Du lieu thong tin sach can chinh sua khong co!\nVui long thoat, thuc hien lai lenh chinh sua va chon lai so thu tu cua sach!");
}

	//--------------------------------------- Xem thông tin sách sau khi chỉnh sửa ------------------------------------
/*
Nhận vào: Số thứ tụ quyển sách cần chỉnh sửa: h
Trả về: Thông tin quyển sách sau khi chỉnh sửa
*/
void XemSuaSach(int h)
{
	DocfileS();
	printf("\nThong tin quyen sach thu %d sau khi duoc chinh sua la: \n", h);

	// Xem ISBN cua sach:
	printf("\n ISBN cua quyen sach thu %d: ", h);
	puts(SA[h - 1].ISBN);

	// Xem ten cua quyen sach:
	printf(" Ten cua quyen sach thu %d: ", h);
	puts(SA[h - 1].TenSach);

	// Xem ten cua tac gia:
	printf(" Ten tac gia cua quyen sach thu %d: ", h);
	puts(SA[h - 1].TacGia);

	// Xem nha xuat ban cua quyen sach:
	printf(" Nha xuat ban cua quyen sach thu %d: ", h);
	puts(SA[h - 1].NhaXB);

	// Xem nam xuat ban cua quyen sach:
	printf(" Nam xuat ban cua quyen sach thu %d: ", h);
	puts(SA[h - 1].NamXB);

	// Xem the loai cua quyen sach:
	printf(" The loai cua quyen sach thu %d: ", h);
	puts(SA[h - 1].TheLoai);

	// Xem gia cua quyen sach:
	printf(" Gia ban cua quyen sach thu %d: ", h);
	puts(SA[h - 1].GiaSach);

	// Xem so luong cua quyen sach:
	printf(" So luong cua quyen sach thu %d la: %d ", h, SA[h - 1].SoLuong);
}

	// ------------------------------------------------- Menu lệnh sửa ------------------------------------------------
/*
Nhận vào: Số thứ tự của độc giả cần sửa thông tin: h
Trả về: Menu lệnh quản lí sửa.
*/
void MenuSuaSach(int h)
{
	while (1)
	{
		printf("\n\t-----------Menu lenh main Chinh Sua Thong tin quyen sach--------------\n");

		printf(" \t\t230.Thoat chinh sua .\n");
		printf(" \t\t231.Tiep tuc chinh sua thong tin quyen sach thu %d.\n", h);
		printf(" \t\t232.Xem thong tin quyen sach sau khi chinh sua.\n");

		printf("\n\t--------------------------------------------------------------------");

		int chon;
		printf("\n\nChon lenh trong menu main chinh sua: ");
		scanf_s("%d", &chon);

		if (chon == 230)
			break;

		switch (chon)
		{
		case 231:
			SuaSach(h);
			break;
		case 232:
			XemSuaSach(h);
			break;
		default:
			printf("Chuc nang khong ton tai. Vui long chon lenh khac!!!");
			break;
		}
	}
}

/********************************************************************************************************************************/


/********************************************************** Xóa sách ***********************************************************/
/*
Nhận vào: SA[MaxSach]; int s; int d (Vi tri can xoa)
Trả về: Thông tin file sách sau xóa
*/
void XoaSach(int d)
{
	DocfileS();
	int flag = 0;
	if (d >= 0 && d < s)
	{
		for (int i = d-1; i < s - 1; i++)
		{
			// Tien hanh sao chep thong tin cua cac quyen sach sau vao cac quyen sach truoc tai vi tri doc gia bi xoa
			
			strcpy_s(SA[i].ISBN, SA[i + 1].ISBN);

			strcpy_s(SA[i].TenSach, SA[i + 1].TenSach);

			strcpy_s(SA[i].TacGia, SA[i + 1].TacGia);

			strcpy_s(SA[i].NhaXB, SA[i + 1].NhaXB);

			strcpy_s(SA[i].NamXB, SA[i + 1].NamXB);

			strcpy_s(SA[i].TheLoai, SA[i + 1].TheLoai);

			strcpy_s(SA[i].GiaSach, SA[i + 1].GiaSach);

			SA[i].SoLuong = SA[i + 1].SoLuong;
		}
		s--;
		flag = 1;
	}
	if (flag == 1)
	{
		printf("\n Danh sach cac quyen sach con sau khi xoa la:\n");
		GhifileS();
		XemSach();
	}
	else
		printf("Khong the thuc hien xoa. Vui long chon doc quyen sach can xoa khac!!!");
}
/********************************************************************************************************************************/


/******************************************************* Tìm sách theo ISBN sách *************************************************/
/*
Nhận vào: SA[MaxSach]; int s; char IS[] (ISBN của quyển sách)
Trả về: Thông tin quyển sách cần tìm.
*/
void TimISBN(char IS[25])
{
	DocfileS();
	int flag = 0;
	for (int i = 0; i < s; i++)
	{
		if (strcmp(SA[i].ISBN, IS) == 0)
		{
			printf("\nThong tin cua quyen sach can tim la:");
			// Xem ISBN cua sach:
			printf("\n ISBN cua quyen sach thu %d: ", i + 1);
			puts(SA[i].ISBN);

			// Xem ten cua quyen sach:
			printf(" Ten cua quyen sach thu %d: ", i + 1);
			puts(SA[i].TenSach);

			// Xem ten cua tac gia:
			printf(" Ten tac gia cua quyen sach thu %d: ", i + 1);
			puts(SA[i].TacGia);

			// Xem nha xuat ban cua quyen sach:
			printf(" Nha xuat ban cua quyen sach thu %d: ", i + 1);
			puts(SA[i].NhaXB);

			// Xem nam xuat ban cua quyen sach:
			printf(" Nam xuat ban cua quyen sach thu %d: ", i + 1);
			puts(SA[i].NamXB);

			// Xem the loai cua quyen sach:
			printf(" The loai cua quyen sach thu %d: ", i + 1);
			puts(SA[i].TheLoai);

			// Xem gia cua quyen sach:
			printf(" Gia cua quyen sach thu %d: ", i + 1);
			puts(SA[i].GiaSach);

			// Xem so luong cua quyen sach:
			printf(" Ngay So luong cua quyen sach thu %d: %d", i + 1, SA[i].SoLuong);

			flag = 1;
		}
	}
	if (flag != 1)
		printf("\nKhong tim thay!!!");
}
/********************************************************************************************************************************/


/******************************************************* Tìm sách theo tên sách *************************************************/
/* 
Nhận vào: SA[MaxSach]; int s; char Sach[] (tên sách)
Trả về: Thông tin quyển sách cần tìm
*/
void TimTenSach(char Sach[25])
{
	DocfileS();
	int flag = 0;
	for (int i = 0; i < s; i++)
	{
		if (strcmp(SA[i].TenSach, Sach) == 0)
		{
			printf("\nThong tin cua quyen sach can tim la:");
			// Xem ISBN cua sach:
			printf("\n ISBN cua quyen sach thu %d: ", i + 1);
			puts(SA[i].ISBN);

			// Xem ten cua quyen sach:
			printf(" Ten cua quyen sach thu %d: ", i + 1);
			puts(SA[i].TenSach);

			// Xem ten cua tac gia:
			printf(" Ten tac gia cua quyen sach thu %d: ", i + 1);
			puts(SA[i].TacGia);

			// Xem nha xuat ban cua quyen sach:
			printf(" Nha xuat ban cua quyen sach thu %d: ", i + 1);
			puts(SA[i].NhaXB);

			// Xem nam xuat ban cua quyen sach:
			printf(" Nam xuat ban cua quyen sach thu %d: ", i + 1);
			puts(SA[i].NamXB);

			// Xem the loai cua quyen sach:
			printf(" The loai cua quyen sach thu %d: ", i + 1);
			puts(SA[i].TheLoai);

			// Xem gia cua quyen sach:
			printf(" Gia cua quyen sach thu %d: ", i + 1);
			puts(SA[i].GiaSach);

			// Xem so luong cua quyen sach:
			printf(" Ngay So luong cua quyen sach thu %d: %d ", i + 1, SA[i].SoLuong);

			flag = 1;
		}
	}
	if (flag != 1)
		printf("\nKhong tim thay!!!");
}
/********************************************************************************************************************************/


/******************************************* Thống kê số lượng sách trong thư viện***********************************************/
/*
Nhận vào: SA[MaxSach]; int s;
Trả về: Số lượng sách trong thư viện
*/
int TKSachTV()
{
	DocfileS();
	int dem = 0;
	for (int i = 0; i < s; i++)
	{
		dem = dem + SA[i].SoLuong;
	}
	return dem;
}
/********************************************************************************************************************************/


/****************************************** Thống kê số luọng sách theo thể loại *************************************************/
/* 
Nhận vào: SA[MaxSach]; int s;
Trả về: Số lượng sách theo từng thể loại
*/
void TKSachTL()
{
	DocfileS();
	int dem = 0;
	for (int i = 0; i < s; i++)
	{
		dem = 0;
		for (int j = 0; j < s; j++)
		{
			if (strcmp(SA[i].TheLoai, SA[j].TheLoai) == 0)
			{
				if (i <= j)
					dem = dem + SA[j].SoLuong;
				else
					break;
			}
		}
		if (dem != 0)
			printf("The loai %s co so luong sach la %d\n", SA[i].TheLoai, dem);
	}
}
/********************************************************************************************************************************/


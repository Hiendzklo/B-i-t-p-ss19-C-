#include <stdio.h>
#include <string.h>

// Khai bao cau truc SinhVien
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} SinhVien;
// Ham hien thi danh sach sinh vien
void hienThiDanhSach(SinhVien *arr, int size) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNumber);
    }
    printf("\n");
}

// Ham them sinh vien
void themSinhVien(SinhVien *arr, int *size, int maxSize) {
    if (*size >= maxSize) {
        printf("Danh sach da day, khong the them sinh vien.\n");
        return;
    }
    SinhVien sv;
    printf("Nhap ID: ");
    scanf("%d", &sv.id);
    printf("Nhap ten: ");
    scanf(" %[^\n]", sv.name);
    printf("Nhap tuoi: ");
    scanf("%d", &sv.age);
    printf("Nhap so dien thoai: ");
    scanf(" %[^\n]", sv.phoneNumber);

    arr[*size] = sv;
    (*size)++;
    printf("Them sinh vien thanh cong.\n\n");
}
// Ham sua thong tin sinh vien
void suaSinhVien(SinhVien *arr, int size) {
    int id, found = 0;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        if (arr[i].id == id) {
            found = 1;
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", arr[i].name);
            printf("Nhap tuoi moi: ");
            scanf("%d", &arr[i].age);
            printf("Nhap so dien thoai moi: ");
            scanf(" %[^\n]", arr[i].phoneNumber);
            printf("Sua thong tin thanh cong.\n\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ID %d.\n\n", id);
    }
}
// Ham xoa sinh vien
void xoaSinhVien(SinhVien *arr, int *size) {
    int id, found = 0;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);

    for (int i = 0; i < *size; i++) {
        if (arr[i].id == id) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            printf("Xoa sinh vien thanh cong.\n\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ID %d.\n\n", id);
    }
}
// Ham chinh
int main() {
    int maxSize = 10; // Kich thuoc toi da cua mang
    SinhVien danhSach[maxSize];
    int soLuong = 0;

    while (1) {
        printf("MENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                hienThiDanhSach(danhSach, soLuong);
                break;
            case 2:
                themSinhVien(danhSach, &soLuong, maxSize);
                break;
            case 3:
                suaSinhVien(danhSach, soLuong);
                break;
            case 4:
                xoaSinhVien(danhSach, &soLuong);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n\n");
        }
    }
}


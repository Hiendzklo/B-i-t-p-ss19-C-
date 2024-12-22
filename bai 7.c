#include <stdio.h>
#include <string.h>

// Khai bao cau truc SinhVien
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} SinhVien;
// Ham in danh sach sinh vien
void printSinhVien(SinhVien *arr, int currentLength) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNumber);
    }
}
// Ham xoa sinh vien theo ID
void xoaSinhVien(int id, SinhVien *arr, int *currentLength) {
    int index = -1; 
    for (int i = 0; i < *currentLength; i++) {
        if (arr[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Khong tim thay sinh vien voi ID = %d\n", id);
        return;
    }
    // Dich chuyen cac phan tu sau vi tri xoa len truoc
    for (int i = index; i < *currentLength - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*currentLength)--; // Giam so luong phan tu hien tai
    printf("Da xoa sinh vien voi ID = %d\n", id);
}

int main() {
    // Khai bao va khoi tao mang sinh vien
    SinhVien students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 21, "0987654321"},
        {3, "Le Van C", 22, "0345678912"},
        {4, "Pham Thi D", 23, "0567891234"},
        {5, "Hoang Van E", 24, "0789123456"}
    };
    int currentLength = 5; // So luong sinh viên hien tai

    // In danh sách sinh viên ban dau
    printf("Danh sach sinh vien ban dau:\n");
    printSinhVien(students, currentLength);
    // Xoa sinh vien theo ID
    int idToDelete;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &idToDelete);

    xoaSinhVien(idToDelete, students, &currentLength);
    // In danh sach sinh vien sau khi xaa
    printf("Danh sach sinh vien sau khi xoa:\n");
    printSinhVien(students, currentLength);
}


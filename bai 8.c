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
void printSinhVien(SinhVien *arr, int size) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNumber);
    }
}

// Ham sap xep sinh vien theo ten
void sapXepSinhVien(SinhVien *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(arr[i].name, arr[j].name) > 0) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
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
    int size = 5; // So luong sinh viên trong mang
    // In danh sach sinh vien ban dau
    printf("Danh sach sinh vien ban dau:\n");
    printSinhVien(students, size);
    // Sap xep sinh vien theo ten
    sapXepSinhVien(students, size);
    // In danh sach sinh vien sau khi sap xep
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printSinhVien(students, size);
}


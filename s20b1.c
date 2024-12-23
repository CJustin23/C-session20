#include <stdio.h>
#include <string.h>

struct Sach {
    char maSach[20];
    char tenSach[50];
    char tacGia[50];
    float giaTien;
    char theLoai[30];
};

struct Sach danhSachSach[100];
int soLuongSach = 0;

void nhapSach() {
    printf("Nhap so luong sach: ");
    scanf("%d", &soLuongSach);

    for (int i = 0; i < soLuongSach; i++) {
        printf("Nhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", danhSachSach[i].maSach);
        printf("Ten sach: ");
        scanf("%s", danhSachSach[i].tenSach);
        printf("Tac gia: ");
        scanf("%s", danhSachSach[i].tacGia);
        printf("Gia tien: ");
        scanf("%f", &danhSachSach[i].giaTien);
        printf("The loai: ");
        scanf("%s", danhSachSach[i].theLoai);
    }
}

void hienThiSach() {
    printf("Danh sach sach:\n");
    for (int i = 0; i < soLuongSach; i++) {
        printf("%d. Ma sach: %s, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The loai: %s\n",
               i + 1, danhSachSach[i].maSach, danhSachSach[i].tenSach, danhSachSach[i].tacGia,
               danhSachSach[i].giaTien, danhSachSach[i].theLoai);
    }
}

void themSach(int viTri, struct Sach sachMoi) {
    if (viTri < 0 || viTri > soLuongSach || soLuongSach >= 100) {
        printf("Vi tri khong hop le hoac danh sach da day.\n");
        return;
    }
    for (int i = soLuongSach; i > viTri; i--) {
        danhSachSach[i] = danhSachSach[i - 1];
    }
    danhSachSach[viTri] = sachMoi;
    soLuongSach++;
    printf("Them sach thanh cong!\n");
}

void xoaSachTheoMa(char *maSach) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].maSach, maSach) == 0) {
            for (int j = i; j < soLuongSach - 1; j++) {
                danhSachSach[j] = danhSachSach[j + 1];
            }
            soLuongSach--;
            printf("Xoa sach thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma %s.\n", maSach);
}

void capNhatThongTinSach(char *maSach) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].maSach, maSach) == 0) {
            printf("Nhap ten sach moi: ");
            scanf("%s", danhSachSach[i].tenSach);
            printf("Nhap tac gia moi: ");
            scanf("%s", danhSachSach[i].tacGia);
            printf("Nhap gia tien moi: ");
            scanf("%f", &danhSachSach[i].giaTien);
            printf("Nhap the loai moi: ");
            scanf("%s", danhSachSach[i].theLoai);
            printf("Cap nhat thong tin sach thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma %s.\n", maSach);
}

void sapXepSach(int tangDan) {
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if ((tangDan && danhSachSach[i].giaTien > danhSachSach[j].giaTien) || (!tangDan && danhSachSach[i].giaTien < danhSachSach[j].giaTien)) {
                struct Sach temp = danhSachSach[i];
                danhSachSach[i] = danhSachSach[j];
                danhSachSach[j] = temp;
            }
        }
    }
    printf("Sap xep sach thanh cong!\n");
}

void timKiemSachTheoTen(char *tenSach) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].tenSach, tenSach) == 0) {
            printf("%d. Ma sach: %s, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The loai: %s\n",
                   i + 1, danhSachSach[i].maSach, danhSachSach[i].tenSach, danhSachSach[i].tacGia,
                   danhSachSach[i].giaTien, danhSachSach[i].theLoai);
            return;
        }
    }
    printf("Khong tim thay sach voi ten %s.\n", tenSach);
}

int main() {
    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapSach();
                break;
            case 2:
                hienThiSach();
                break;
            case 3: {
                int viTri;
                struct Sach sachMoi;
                printf("Nhap vi tri: ");
                scanf("%d", &viTri);
                if (viTri <= soLuongSach) {
                    printf("Nhap ma sach: ");
                    scanf("%s", sachMoi.maSach);
                    printf("Nhap ten sach: ");
                    scanf("%s", sachMoi.tenSach);
                    printf("Nhap tac gia: ");
                    scanf("%s", sachMoi.tacGia);
                    printf("Nhap gia tien: ");
                    scanf("%f", &sachMoi.giaTien);
                    printf("Nhap the loai: ");
                    scanf("%s", sachMoi.theLoai);
                    themSach(viTri - 1, sachMoi);
                } else {
                    printf("Vi tri khong hop le.\n");
                }
                break;
            }
            case 4: {
                char maSach[20];
                printf("Nhap ma sach can xoa: ");
                scanf("%s", maSach);
                xoaSachTheoMa(maSach);
                break;
            }
            case 5: {
                char maSach[20];
                printf("Nhap ma sach can cap nhat: ");
                scanf("%s", maSach);
                capNhatThongTinSach(maSach);
                break;
            }
            case 6: {
                printf("a. Giam dan theo gia\n");
                printf("b. Tang dan theo gia\n");
                char subChoice;
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    sapXepSach(0);
                } else if (subChoice == 'b') {
                    sapXepSach(1);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            }
            case 7: {
                char tenSach[50];
                printf("Nhap ten sach can tim: ");
                scanf("%s", tenSach);
                timKiemSachTheoTen(tenSach);
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }
}


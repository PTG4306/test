# Quản lý tài liệu thư viện - C++ OOP

Bài tập xây dựng chương trình quản lý **Sách**, **Tạp chí**, **Báo** bằng C++11.

## Cấu trúc lớp
- `TaiLieu`: lớp cơ sở trừu tượng có mã tài liệu (duy nhất), tên nhà xuất bản, số bản phát hành.
- `Sach`: tên tác giả, số trang.
- `TapChi`: số phát hành, tháng phát hành.
- `Bao`: ngày phát hành.
- `QuanLyThuVien`: quản lý danh sách bằng `vector<unique_ptr<TaiLieu>>`.

## Tính năng
1. Thêm mới sách/tạp chí/báo.
2. Xóa theo mã tài liệu.
3. Hiển thị toàn bộ tài liệu.
4. Tìm kiếm theo loại.
0. Thoát.

Có kiểm tra mã trùng, giá trị số, tháng và ngày phát hành hợp lệ. Dữ liệu hiện lưu trong bộ nhớ, chưa lưu xuống ổ đĩa.

## Chạy trên Windows hoặc Linux
```bash
g++ -std=c++11 -Wall -Wextra -pedantic quan-ly-thu-vien/main.cpp -o quanlythuvien
./quanlythuvien
```
Trên Windows có thể đặt đầu ra là `quanlythuvien.exe` và chạy tệp đó.

## Visual Studio 2013
Tạo Visual C++ → Win32 Console Application (Empty project), thêm `quan-ly-thu-vien/main.cpp` trong Source Files rồi nhấn Ctrl+F5.

## Ví dụ
- Sách: mã S01, NXB Giao duc, 50 bản, tác giả Nguyen Van A, 200 trang.
- Tạp chí: mã T01, NXB Khoa hoc, 30 bản, số 12, tháng 10.
- Báo: mã B01, NXB Tre, 100 bản, ngày 12/10/2026 (nhập năm → tháng → ngày).

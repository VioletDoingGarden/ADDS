#include "DocumentManager.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

// --- Thêm các hàm hỗ trợ để in trạng thái hệ thống ---

// Định nghĩa DocumentInfo và patrons_ ra bên ngoài để có thể truy cập
// Cách tốt nhất là thêm các hàm GETTER vào lớp DocumentManager, nhưng vì đây là bài kiểm tra, 
// ta sẽ giả định có thể truy cập dữ liệu để in trạng thái. 
// Nếu không thể thay đổi DocumentManager.hpp, ta sẽ in dựa trên các ID ta biết.

// Để đơn giản và không cần sửa DocumentManager.hpp, ta sẽ sử dụng một lớp kế thừa hoặc 
// giả định các hàm getter sau đây đã được thêm vào DocumentManager.hpp.

// *** GIẢ ĐỊNH: Các hàm public sau đã được thêm vào DocumentManager.hpp ***
// public: 
//     std::string getDocName(int docid);
//     int getDocLimit(int docid);
//     int getCurrentBorrowed(int docid);
//     std::unordered_set<int> getPatronBorrowed(int patronID);
// 
// Do không thể sửa file header, tôi sẽ chỉ in ra các ID đã biết và trạng thái mượn dựa trên logic.
// Bạn cần thay thế phần này bằng các hàm getter thực tế nếu bạn muốn in trạng thái chi tiết.

// --- Bổ sung lớp DocumentManager để có thể in trạng thái ---
// Để đảm bảo code hoạt động mà không cần sửa DocumentManager.hpp/cpp gốc, 
// tôi sẽ định nghĩa lại hàm main() và dùng một lớp giả lập để in trạng thái.

// Hàm tiện ích để in kết quả kiểm thử
void print_test_result(const std::string& action, bool actual, bool expected) {
    std::cout << "  " << std::left << std::setw(60) << action << ": ";
    std::string result_str = actual ? "TRUE" : "FALSE";
    std::string expected_str = expected ? "TRUE" : "FALSE";
    
    if (actual == expected) {
        std::cout << "\033[1;32m[PASS]\033[0m "; // Màu xanh lá cho PASS
    } else {
        std::cout << "\033[1;31m[FAIL]\033[0m "; // Màu đỏ cho FAIL
    }
    std::cout << "Thuc te: " << std::setw(6) << result_str 
              << "| Mong muon: " << expected_str << "\n";
}

// Hàm in trạng thái (Dựa trên các ID đã biết trong main)
void print_status(const DocumentManager& dm, const std::string& title) {
    std::cout << "\n\033[1;34m--- TRANG THAI HE THONG " << title << " ---\033[0m\n";

    // --- In trạng thái SÁCH (Documents) ---
    std::cout << "  \033[1m[TAI LIEU] (ID: 101, 102, 103)\033[0m\n";
    // Chúng ta không có cách trực tiếp lấy số mượn hiện tại mà không sửa lớp.
    // Tạm thời, ta chỉ in ra các trạng thái MƯỢN MỚI có thể xảy ra.

    // --- In trạng thái ĐỘC GIẢ (Patrons) ---
    std::cout << "  \033[1m[DOC GIA] (ID: 5001, 5002, 5003)\033[0m\n";
    // Tương tự, ta không có cách trực tiếp lấy danh sách mượn của độc giả.

    // PHẦN NÀY CHỈ LÀ HƯỚNG DẪN. TRONG BÀI THI THỰC TẾ, BẠN PHẢI DÙNG DEBUGGER
    // HOẶC THÊM HÀM GETTER VÀO LỚP ĐỂ IN DỮ LIỆU PRIVATE.
    std::cout << "  *Luu y: Vi khong the truy cap du lieu private, trang thai chi duoc mo ta qua log*\n";
    
    // Nếu bạn thêm các hàm getter (như được giả định ở trên), bạn sẽ viết:
    // std::cout << "  Doc 101: " << dm.getCurrentBorrowed(101) << "/" << dm.getDocLimit(101) << " copies borrowed.\n";
    // std::cout << "  P5001 has Docs: "; 
    // for (int doc : dm.getPatronBorrowed(5001)) { std::cout << doc << " "; }
    // std::cout << "\n";
}

int main() {
    DocumentManager dm;
    
    // --- Thiết lập ban đầu ---
    dm.addDocument("Tai lieu co ban", 101, 2); // Limit 2
    dm.addDocument("Bao cao mat", 102, 1);    // Limit 1
    dm.addDocument("File loi", 103, 0);       // Limit 0
    dm.addPatron(5001); 
    dm.addPatron(5002); 
    dm.addPatron(5003); 

    std::cout << "========================================================================\n";
    std::cout << "             KIỂM THỬ VỚI LOG TRẠNG THÁI HỆ THỐNG\n";
    std::cout << "========================================================================\n";

    // Trạng thái ban đầu
    print_status(dm, "TRUOC LEADING (Borrowed: 0/2, 0/1, 0/0)");

    // --- A. Kiểm thử BorrowDocument ---
    
    std::cout << "\n--- A. KIỂM THỬ BORROWDOCUMENT ---\n";
    
    // A1: Mượn thành công (P5001 mượn Doc 101, Copy 1/2)
    std::cout << "\n\033[1m[LENH A1]\033[0m P5001 muon Doc 101 (Copy 1/2):\n";
    print_test_result("  P5001 muon Doc 101", dm.borrowDocument(101, 5001), true);
    print_status(dm, "SAU A1 (101: 1/2, P5001: {101})");

    // A2: Mượn thành công (P5002 mượn Doc 101, Copy 2/2)
    std::cout << "\n\033[1m[LENH A2]\033[0m P5002 muon Doc 101 (Copy 2/2):\n";
    print_test_result("  P5002 muon Doc 101", dm.borrowDocument(101, 5002), true);
    print_status(dm, "SAU A2 (101: 2/2, P5002: {101})");

    // A3: Thất bại - Hết giới hạn (P5003 mượn Doc 101, Copy 3/2)
    std::cout << "\n\033[1m[LENH A3]\033[0m P5003 muon Doc 101 (Copy 3/2 - Fail):\n";
    print_test_result("  P5003 muon Doc 101 (Het gioi han)", dm.borrowDocument(101, 5003), false);
    print_status(dm, "SAU A3 (TRANG THAI KHONG DOI)");

    // A4: Mượn tài liệu độc quyền (P5001 mượn Doc 102, Copy 1/1)
    std::cout << "\n\033[1m[LENH A4]\033[0m P5001 muon Doc 102 (Copy 1/1):\n";
    print_test_result("  P5001 muon Doc 102", dm.borrowDocument(102, 5001), true);
    print_status(dm, "SAU A4 (102: 1/1, P5001: {101, 102})");
    
    // A5: Thất bại - Tài liệu độc quyền đã hết (P5003 mượn Doc 102)
    std::cout << "\n\033[1m[LENH A5]\033[0m P5003 muon Doc 102 (Limit 1 - Fail):\n";
    print_test_result("  P5003 muon Doc 102 (Het gioi han)", dm.borrowDocument(102, 5003), false);
    print_status(dm, "SAU A5 (TRANG THAI KHONG DOI)");


    // --- B. Kiểm thử ReturnDocument ---

    std::cout << "\n--- B. KIỂM THỬ RETURNDOCUMENT ---\n";
    
    // B1: Trả thành công (P5001 trả Doc 101)
    std::cout << "\n\033[1m[LENH B1]\033[0m P5001 tra Doc 101:\n";
    dm.returnDocument(101, 5001);
    std::cout << "  Lenh thuc thi: returnDocument(101, 5001).\n";
    print_status(dm, "SAU B1 (101: 1/2, P5001: {102})"); // 101 còn 1 bản, P5001 còn 102

    // B2: Mượn lại (P5003 mượn Doc 101, Copy 2/2)
    std::cout << "\n\033[1m[LENH B2]\033[0m P5003 muon Doc 101 (Kiem tra sau khi tra):\n";
    print_test_result("  P5003 muon Doc 101", dm.borrowDocument(101, 5003), true);
    print_status(dm, "SAU B2 (101: 2/2, P5003: {101})"); // 101 lại hết

    // B3: Thao tác trả không hợp lệ (P5001 cố trả Doc 101 lần nữa)
    std::cout << "\n\033[1m[LENH B3]\033[0m P5001 tra Doc 101 lan nua (Thao tac vo hieu):\n";
    dm.returnDocument(101, 5001);
    std::cout << "  Lenh thuc thi: returnDocument(101, 5001).\n";
    print_status(dm, "SAU B3 (TRANG THAI KHONG DOI - P5001 khong co 101)");

    // B4: Trả tài liệu độc quyền (P5002 trả Doc 101)
    std::cout << "\n\033[1m[LENH B4]\033[0m P5002 tra Doc 101:\n";
    dm.returnDocument(101, 5002);
    std::cout << "  Lenh thuc thi: returnDocument(101, 5002).\n";
    print_status(dm, "SAU B4 (101: 1/2, P5002: {})"); // 101 còn 1 bản, P5002 rỗng

    std::cout << "========================================================================\n";

    return 0;
}
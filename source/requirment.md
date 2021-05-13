//mô phỏng máy rút tiền
//funtion operator
- cần có những chức năng đăng nhập
    + có thể thêm chức năng đăng kí
    - Nhập ID, nhập password
      + Nhập đúng hiển thị chức năng(done)
      + sai dưới 5 lần cho nhập tiếp(not done)
        sai 5 quá 5 lần liên tiếp -> khoá thẻ
    - Gửi tiền:
        + lẻ đến 10.000 VND
        + Nhập mệnh giá và số tờ tương ứng
        + Nạp tiền cho người đó (done)
        + Nạp tiền vào máy rút tiền(chỉ rút ra được tối đa số tiền đã nạp) (50%) can fix lai nhieu
    
    - Kiểm tra tài khoản:
    - Rút tiền: withdraw
        + thông báo số tiền nhỏ nhất rút được
        + Nhập số tiền 
        + Kiểm tra:
            + Bội số của số tiền nhỏ nhất;
            + số dư
        + Lấy tiền ra:
            tờ nào ? số tờ trả ra là ít nhất rồi trừ tiền đi
            giải thuật tham lam
    - Lưu lại lịch sử/ xem lịch sử:
        -> thao tác với file
VD nạp vào 100 tớ 500k 
    rút ra 600k phải check xem có trả đc tiền hay ko

    //fix scientific number (fixed)
        (24-04-21)
        //* viet lai hoptien
            //cai dat thuat toan tham lam
                // chua lam chuc nang khoa the
                    // chua lam vong lap vo han (maybe done;)
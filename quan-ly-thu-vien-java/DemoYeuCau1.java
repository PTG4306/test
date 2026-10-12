import java.util.ArrayList;
import java.util.List;

/**
 * Chuong trinh chay thu Yeu cau 1: tao Sach, Tap chi, Bao va hien thi thong tin.
 * Day la file demo de kiem tra cac lop, khong phai menu cua Yeu cau 2.
 * @author Vu Minh Hieu
 */
public class DemoYeuCau1 {
    public static void main(String[] args) {
        // Da hinh: moi phan tu la TaiLieu, nhung thuc chat la Sach / TapChi / Bao
        List<TaiLieu> danhSach = new ArrayList<>();
        danhSach.add(new Sach("S01", "Kim Dong", 100, "Nguyen Nhat Anh", 200));
        danhSach.add(new Sach("S02", "NXB Tre", 50, "Nguyen Du", 350));
        danhSach.add(new TapChi("T01", "NXB Giao Duc", 300, 12, 10));
        danhSach.add(new Bao("B01", "Bao Nhan Dan", 5000, "12/10/2026"));

        System.out.println("===== DANH SACH TAI LIEU (YEU CAU 1) =====");
        for (TaiLieu tl : danhSach) {
            tl.hienThiThongTin();
        }

        // Kiem tra ma tai lieu la duy nhat (equals so sanh theo ma)
        TaiLieu trung = new Bao("S01", "NXB X", 1, "01/01/2026");
        System.out.println("\nTai lieu S01 co trung ma voi Bao moi khong? "
                + danhSach.get(0).equals(trung));

        // Thu doi thong tin bang setter
        Sach s = (Sach) danhSach.get(0);
        s.setSoTrang(250);
        System.out.println("\nSau khi doi so trang sach S01 thanh 250:");
        s.hienThiThongTin();
    }
}
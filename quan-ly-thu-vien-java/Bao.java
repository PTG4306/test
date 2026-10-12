/**
 * Yeu cau 1: Lop Bao ke thua TaiLieu.
 * Them thuoc tinh: ngay phat hanh.
 * @author Vu Minh Hieu
 */
public class Bao extends TaiLieu {
    private String ngayPhatHanh;   // dinh dang dd/MM/yyyy

    public Bao(String ma, String nxb, int soBan, String ngayPhatHanh) {
        super(ma, nxb, soBan);
        this.ngayPhatHanh = ngayPhatHanh;
    }

    public String getNgayPhatHanh() { return ngayPhatHanh; }

    public void setNgayPhatHanh(String ngayPhatHanh) { this.ngayPhatHanh = ngayPhatHanh; }

    @Override
    public String getLoai() { return "Bao"; }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("   -> Ngay phat hanh: " + ngayPhatHanh);
    }
}
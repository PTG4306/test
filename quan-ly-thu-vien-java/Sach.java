/**
 * Yeu cau 1: Lop Sach ke thua TaiLieu.
 * Them thuoc tinh: ten tac gia, so trang.
 * @author Vu Minh Hieu
 */
public class Sach extends TaiLieu {
    private String tenTacGia;
    private int soTrang;

    public Sach(String ma, String nxb, int soBan, String tenTacGia, int soTrang) {
        super(ma, nxb, soBan);
        this.tenTacGia = tenTacGia;
        this.soTrang = soTrang;
    }

    public String getTenTacGia() { return tenTacGia; }
    public int getSoTrang() { return soTrang; }

    public void setTenTacGia(String tenTacGia) { this.tenTacGia = tenTacGia; }
    public void setSoTrang(int soTrang) { this.soTrang = soTrang; }

    @Override
    public String getLoai() { return "Sach"; }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("   -> Tac gia: " + tenTacGia + " | So trang: " + soTrang);
    }
}
/**
 * Yeu cau 1: Lop TapChi ke thua TaiLieu.
 * Them thuoc tinh: so phat hanh, thang phat hanh.
 * @author Vu Minh Hieu
 */
public class TapChi extends TaiLieu {
    private int soPhatHanh;
    private int thangPhatHanh;

    public TapChi(String ma, String nxb, int soBan, int soPhatHanh, int thangPhatHanh) {
        super(ma, nxb, soBan);
        this.soPhatHanh = soPhatHanh;
        this.thangPhatHanh = thangPhatHanh;
    }

    public int getSoPhatHanh() { return soPhatHanh; }
    public int getThangPhatHanh() { return thangPhatHanh; }

    public void setSoPhatHanh(int soPhatHanh) { this.soPhatHanh = soPhatHanh; }
    public void setThangPhatHanh(int thangPhatHanh) { this.thangPhatHanh = thangPhatHanh; }

    @Override
    public String getLoai() { return "Tap chi"; }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("   -> So phat hanh: " + soPhatHanh + " | Thang phat hanh: " + thangPhatHanh);
    }
}
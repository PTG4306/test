/**
 * Yeu cau 1: Lop cha truu tuong TaiLieu.
 * Chua cac thuoc tinh chung cua Sach, Tap chi, Bao.
 * @author Vu Minh Hieu
 */
public abstract class TaiLieu {
    private String maTaiLieu;      // ma tai lieu (duy nhat trong thu vien)
    private String tenNhaXuatBan;  // ten nha xuat ban
    private int soBanPhatHanh;     // so ban phat hanh

    public TaiLieu(String maTaiLieu, String tenNhaXuatBan, int soBanPhatHanh) {
        this.maTaiLieu = maTaiLieu;
        this.tenNhaXuatBan = tenNhaXuatBan;
        this.soBanPhatHanh = soBanPhatHanh;
    }

    // ----- Getter -----
    public String getMaTaiLieu() { return maTaiLieu; }
    public String getTenNhaXuatBan() { return tenNhaXuatBan; }
    public int getSoBanPhatHanh() { return soBanPhatHanh; }

    // ----- Setter (khong co setter cho ma vi ma la duy nhat, khong doi) -----
    public void setTenNhaXuatBan(String tenNhaXuatBan) { this.tenNhaXuatBan = tenNhaXuatBan; }
    public void setSoBanPhatHanh(int soBanPhatHanh) { this.soBanPhatHanh = soBanPhatHanh; }

    /** Tra ve loai tai lieu: "Sach", "Tap chi" hoac "Bao". Moi lop con tu dinh nghia. */
    public abstract String getLoai();

    /** Hien thi thong tin chung cua tai lieu. Lop con goi super roi in them thuoc tinh rieng. */
    public void hienThiThongTin() {
        System.out.println("Loai: " + getLoai()
                + " | Ma: " + maTaiLieu
                + " | NXB: " + tenNhaXuatBan
                + " | So ban phat hanh: " + soBanPhatHanh);
    }

    /** Hai tai lieu la mot neu cung ma (vi ma la duy nhat). */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof TaiLieu)) return false;
        TaiLieu khac = (TaiLieu) o;
        return maTaiLieu.equalsIgnoreCase(khac.maTaiLieu);
    }

    @Override
    public int hashCode() {
        return maTaiLieu.toLowerCase().hashCode();
    }
}
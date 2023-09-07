using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System;

// Class Barang
public class Barang
{
    public string Kode { get; set; }
    public string Nama { get; set; }
    public int Harga { get; set; }
    public int Stok { get; set; }
}

// Class Pembelian
public class Pembelian
{
    public string NoTransaksi { get; set; }
    public string NamaPembeli { get; set; }
    public DateTime Tanggal { get; set; }

    public void TampilkanTransaksi()
    {
        Console.WriteLine("Detail Transaksi Pembelian");
        Console.WriteLine("No. Transaksi: " + NoTransaksi);
        Console.WriteLine("Nama Pembeli: " + NamaPembeli);
        Console.WriteLine("Tanggal Pembelian: " + Tanggal.ToString("dd-MM-yyyy"));
    }
}

// Class DetailPembelian
public class DetailPembelian
{
    public string NoTransaksi { get; set; }
    public Barang BarangPembelian { get; set; }
    public int Jumlah { get; set; }
    public int TotalHarga { get { return Jumlah * BarangPembelian.Harga; } }
    public string Catatan { get; set; }

    public void TampilkanPembayaranCash()
    {
        Console.WriteLine("Detail Pembayaran Cash");
        Console.WriteLine("No. Transaksi: " + NoTransaksi);
        Console.WriteLine("Barang: " + BarangPembelian.Nama);
        Console.WriteLine("Jumlah: " + Jumlah);
        Console.WriteLine("Total Harga: " + TotalHarga);
        Console.WriteLine("Catatan: " + Catatan);
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Membuat instance dari class Barang
        Barang barang1 = new Barang
        {
            Kode = "B001",
            Nama = "Baju",
            Harga = 100000,
            Stok = 10
        };

        // Membuat instance dari class Pembelian
        Pembelian pembelian1 = new Pembelian
        {
            NoTransaksi = "T001",
            NamaPembeli = "John Doe",
            Tanggal = DateTime.Now
        };

        // Membuat instance dari class DetailPembelian
        DetailPembelian detailPembelian1 = new DetailPembelian
        {
            NoTransaksi = "T001",
            BarangPembelian = barang1,
            Jumlah = 2,
            Catatan = "Diskon 10%"
        };

        // Menampilkan transaksi pembelian
        pembelian1.TampilkanTransaksi();

        // Menampilkan pembayaran cash
        detailPembelian1.TampilkanPembayaranCash();

        Console.ReadLine();
    }
}
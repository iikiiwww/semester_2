using System;

class TicketOrder
{
    private string name;
    private string nik;
    private string phoneNumber;
    private string vaccineCardNumber;
    private string address;

    // Getter dan Setter untuk masing-masing atribut
    public string Name
    {
        get { return name; }
        set { name = value; }
    }

    public string Nik
    {
        get { return nik; }
        set { nik = value; }
    }

    public string PhoneNumber
    {
        get { return phoneNumber; }
        set { phoneNumber = value; }
    }

    public string VaccineCardNumber
    {
        get { return vaccineCardNumber; }
        set { vaccineCardNumber = value; }
    }

    public string Address
    {
        get { return address; }
        set { address = value; }
    }

    // Metode untuk melakukan pemesanan tiket
    public void PlaceOrder()
    {
        // Implementasi logika untuk pemesanan tiket
        Console.WriteLine("Ticket order placed successfully!");
    }
}

class Program
{
    static void Main()
    {
        // Penggunaan kelas TicketOrder dengan encapsulation
        TicketOrder ticketOrder = new TicketOrder();
        ticketOrder.Name = "John Doe";
        ticketOrder.Nik = "123456789";
        ticketOrder.PhoneNumber = "081234567890";
        ticketOrder.VaccineCardNumber = "VAX123";
        ticketOrder.Address = "123 Main St, City";

        ticketOrder.PlaceOrder();
    }
}

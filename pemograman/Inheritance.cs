using System;

class TicketOrder
{
    // Implementasi seperti contoh sebelumnya
    // ...

    public void PlaceOrder()
    {
        Console.WriteLine("Ticket order placed successfully!");
    }
}

class BusTicketOrder : TicketOrder
{
    public void SelectSeat()
    {
        Console.WriteLine("Seat selected: Window seat.");
    }
}

class Program
{
    static void Main()
    {
        // Penggunaan kelas BusTicketOrder yang mewarisi dari TicketOrder
        BusTicketOrder busTicketOrder = new BusTicketOrder();
        busTicketOrder.Name = "Alice Smith";
        busTicketOrder.Nik = "987654321";
        busTicketOrder.PhoneNumber = "082345678901";
        busTicketOrder.VaccineCardNumber = "VAX456";
        busTicketOrder.Address = "456 Park Ave, Town";

        busTicketOrder.PlaceOrder();
        busTicketOrder.SelectSeat();
    }
}

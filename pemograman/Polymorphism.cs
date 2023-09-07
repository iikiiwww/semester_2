using System;

abstract class TransportationTicket
{
    public string Name { get; set; }
    public string Nik { get; set; }
    public string PhoneNumber { get; set; }
    public string VaccineCardNumber { get; set; }
    public string Address { get; set; }

    // Metode abstrak untuk melakukan pemesanan tiket
    public abstract void PlaceOrder();
}

class BusTicket : TransportationTicket
{
    public override void PlaceOrder()
    {
        Console.WriteLine("Bus ticket order placed successfully!");
    }
}

class TrainTicket : TransportationTicket
{
    public override void PlaceOrder()
    {
        Console.WriteLine("Train ticket order placed successfully!");
    }
}

class Program
{
    static void Main()
    {
        // Penggunaan polimorfisme dengan kelas BusTicket dan TrainTicket
        TransportationTicket busTicket = new BusTicket();
        busTicket.Name = "Bob Johnson";
        busTicket.Nik = "543216789";
        busTicket.PhoneNumber = "085678901234";
        busTicket.VaccineCardNumber = "VAX789";
        busTicket.Address = "789 Oak St, Village";

        TransportationTicket trainTicket = new TrainTicket();
        trainTicket.Name = "Eva Lee";
        trainTicket.Nik = "432187654";
        trainTicket.PhoneNumber = "088765432109";
        trainTicket.VaccineCardNumber = "VAX321";
        trainTicket.Address = "321 Elm St, County";

        busTicket.PlaceOrder();
        trainTicket.PlaceOrder();
    }
}

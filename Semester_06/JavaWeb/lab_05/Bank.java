import java.io.*;
import java.util.*;

class Bank{

public static void main (String args[]) throws IOException, ClassNotFoundException {

    AcountRecordSerializable wo2=new AcountRecordSerializable();
    wo2.openAccount();
    FileOutputStream fos=new FileOutputStream("Data.txt");
    ObjectOutputStream oos_1 = new ObjectOutputStream(fos);
    oos_1.writeObject(wo2);
    wo2.Retrieve();

    AcountRecordSerializable wo=new AcountRecordSerializable();
    wo.openAccount();

    AcountRecordSerializable wo1=new AcountRecordSerializable();
    wo1.openAccount();

    ArrayList<AcountRecordSerializable> woi=new ArrayList<>();
    try {
        FileOutputStream fop=new FileOutputStream("Hello.txt");
        ObjectOutputStream oos=new ObjectOutputStream(fop);
        woi.add(wo);
        woi.add(wo1);
        oos.writeObject(woi);
        wo.RetrieveAll();
    } catch (Exception e) {
        System.out.println(e);
    }
}

}

class AcountRecordSerializable implements Serializable{
    public int getBalance() {
        return balance;
    }

    public String getAcc_no() {
        return acc_no;
    }

    public String getFirstname() {
        return firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }

    public void setAcc_no(String acc_no) {
        this.acc_no = acc_no;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    int balance;
String acc_no,firstname,lastname;

void openAccount() throws IOException {

Scanner str,in;
str = new Scanner(System.in);
in=new Scanner(System.in);

System.out.println("Enter firstname");
firstname = str.nextLine();

System.out.println("Enter lastname");
lastname = str.nextLine();

System.out.println("Enter bal");
balance = in.nextInt();

System.out.println("Enter Account Number");
acc_no = str.nextLine();

}

void Retrieve() throws IOException, ClassNotFoundException {
    FileInputStream fileInputStream=new FileInputStream("Data.txt");
    ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
    System.out.println(objectInputStream.readObject());

}

 @Override
    public String toString() {
        return "Name " + firstname + ' ' + lastname + '\n' + "Balance " + balance + '\n' + "Account Number "+ acc_no;
    }

void RetrieveAll() throws IOException, ClassNotFoundException {
    FileInputStream fis = new FileInputStream("Hello.txt");
    ArrayList<AcountRecordSerializable> objectsList = new ArrayList<>();
    ObjectInputStream input = new ObjectInputStream(fis);

    objectsList = (ArrayList<AcountRecordSerializable>) input.readObject();


    for(int i = 0 ; i<objectsList.size();i++){
        System.out.println(objectsList.get(i));
    }



}
}



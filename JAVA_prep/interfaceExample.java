interface Printable {
    void print();
}

class Print1 implements Printable {
    public void print() {
        System.out.println("Hello Print - 1");
    }
}

class Print2 implements Printable {
    public void print() {
        System.out.println("Hello Print - 2");
    }
}

public class interfaceExample {
    public static void main(String[] args) {
        Printable p1 = new Print1();
        p1.print();
        Printable p2 = new Print2();
        p2.print();
    }
}
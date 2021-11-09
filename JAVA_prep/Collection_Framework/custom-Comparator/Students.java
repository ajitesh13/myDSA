import java.lang.instrument.UnmodifiableClassException;

public class students {
    String name;
    int rollNumber;

    students(String name, int rollNum) {
        this.name = name;
        this.rollNumber = rollNum;
    }

    public String toString() {
        return this.name + " " + this.rollNumber;
    }
}
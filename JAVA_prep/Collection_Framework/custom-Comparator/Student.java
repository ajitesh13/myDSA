public class Student implements Comparable<Student> {
    String name;
    int rollNo;

    Student(String name, int rollNo) {
        this.name = name;
        this.rollNo = rollNo;
    }

    @Override
    public String toString() {
        return this.name + " " + this.rollNo;
    }

    @Override
    public int compareTo(Student o) {
        /*
            It will compare the current Student with the passed Student 'o' 
            if current Student > Student 'o' then return positive 
            if current Student < Student 'o' then return negative 
            if current Student == Student 'o' then return 0
        */

        return this.rollNo - o.rollNo;
    }
}

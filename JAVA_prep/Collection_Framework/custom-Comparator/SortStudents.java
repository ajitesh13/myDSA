import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class SortStudents {
    public static void main(String[] args) {
        List<Student> list = new ArrayList<>();
        list.add(new Student("Ajitesh", 22));
        list.add(new Student("Panda", 33));
        list.add(new Student("Eoin", 44));
        list.add(new Student("Morgan", 11));
        list.add(new Student("Jyoti", 5));
        list.add(new Student("Vardhan", 99));
        list.add(new Student("Bjitesh", 22));

        Student s1 = new Student("Yash1", 3);
        Student s2 = new Student("Yash2", 4);
        System.out.println(s1.compareTo(s2)); // will use the compareTo function and return -1 == 3 - 4

        Collections.sort(list); // sort according to the compareTo function by using integer
        System.out.println(list);

        Collections.sort(list, new Comparator<Student>() { // defining a custom comparator (sorting on the basis of name)
            @Override
            public int compare(Student o1, Student o2) {
                return o1.name.compareTo(o2.name);
            }
        });
        // Collections.sort(list, (o1, o2) -> o1.name.compareTo(o2.name)); // sorting with name(same as above) using lambda function
        System.out.println(list);
    }
}

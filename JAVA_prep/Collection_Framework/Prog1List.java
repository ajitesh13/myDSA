import java.util.ArrayList;
import java.util.List;
import java.util.*;

public class Prog1List {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("Ajitesh");
        list.add("is");
        list.add("my");
        list.add("name");
        System.out.println(list);

        List<Integer> list2 = new ArrayList<>();
        list2.add(3);
        list2.add(5);
        list2.add(9);
        System.out.println(list2); // everytime we sysout the list, the list.toString() method is invoked 

        list2.add(8);
        list2.add(10);
        System.out.println(list2);

        list2.add(1, 400); // add 400 in index 1 --> O(n)
        System.out.println(list2);

        List<Integer> newList = new ArrayList<>();
        newList.add(34);
        newList.add(23);
        newList.add(8);
        System.out.println(newList);
        list2.addAll(newList);
        System.out.println(list2);

        System.out.println(list2.get(5)); // get element from ArrayList by index
        list2.set(2, 199999); // update the value at 2nd index
        System.out.println(list2.contains(199999)); // return true as present --> O(n)
        System.out.println(list2.contains(500)); // return false as not present --> O(n)

        list2.remove(1); // remove 1st index value  --> O(n)
        System.out.println(list2);
        list2.remove(Integer.valueOf(8)); // remove first occurance of 8
        System.out.println(list2);
        newList.clear(); // clear the list newList

        Iterator<Integer> it = list2.iterator(); // iterator to iterator thorugh the container
        while (it.hasNext()) {
            System.out.println("Iterator: " + it.next());
        }

        Stack<Integer> st = new Stack<>(); // declaring a stack 

    }
}

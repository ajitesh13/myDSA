import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class prog7CollectionsClass {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        list.add(34);
        list.add(12);
        list.add(9);
        list.add(9);
        list.add(76);
        list.add(29);
        list.add(75);
        System.out.println(Collections.min(list)); // return the min element of the list 
        System.out.println(Collections.max(list)); // return the max element of the list 
        System.out.println(Collections.frequency(list, 9)); // return the frequency of the perticular element in the list
        System.out.println(list);
        Collections.sort(list); // sort list in acending order 
        System.out.println(list);
        Collections.sort(list, Comparator.reverseOrder()); // sort list in decending order
        System.out.println(list);
    }
}

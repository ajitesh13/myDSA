import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeSet;

public class Prog4Set {
    public static void main(String[] args) {
        Set<Integer> st = new HashSet<>(); // order is not maintained due to internal hashing
        // Set<Integer> st = new LinkedHashSet<>(); // order of element is maintained becuz of linkedlist
        // Set<Integer> st = new TreeSet<>(); // keeps the order of element always sorted 
        st.add(13);
        st.add(3);
        st.add(4);
        st.add(5);
        st.add(3);
        st.add(7);
        System.out.println(st); 
        st.remove(3);
        System.out.println(st);
        System.out.println(st.contains(3)); // false
        System.out.println(st.contains(5)); // true
        System.out.println(st.size());
        st.clear();
        System.out.println(st);
    }
}

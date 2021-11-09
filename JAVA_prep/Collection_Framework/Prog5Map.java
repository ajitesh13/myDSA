import java.security.KeyStore.Entry;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Prog5Map {
    public static void main(String[] args) {
        // Map<Integer, String> mp = new HashMap<>();
        Map<Integer,String> mp = new TreeMap<>(); // store the pairs in sorted order (sorted according to key)
        mp.put(1, "one");
        mp.put(2, "two");
        mp.put(3, "three");
        System.out.println(mp);
        System.out.println(mp.containsKey(3)); // true 
        System.out.println(mp.containsKey(4)); // false
        System.out.println(mp.containsValue("two")); // true
        System.out.println(mp.containsValue("four")); // false
        mp.remove(3); // remove the specific key
        mp.putIfAbsent(4, "four"); // check if key is present or not if present ignord or add
        mp.putIfAbsent(5, "five");
        System.out.println(mp);

        for (Map.Entry<Integer, String> e: mp.entrySet()) {
            System.out.println(e);
            System.out.println(e.getKey() + " " + e.getValue());
        }

        for (Integer key: mp.keySet()) {
            System.out.println(key);
        }

        for (String value: mp.values()) {
            System.out.println(value);
        }


    }
}
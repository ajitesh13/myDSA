import java.util.ArrayList;
import java.util.List;

class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class sol {
    
    public static void main(String[] args) {
        List<Pair> list = new ArrayList<>();
        list.add(new Pair(2, 3));
        list.add(new Pair(5, 5));
        list.add(new Pair(8, 4));

        for (int i=0; i<list.size(); i++) {
            System.out.println(list.get(i).first + " " + list.get(i).second);
        }

    }
}
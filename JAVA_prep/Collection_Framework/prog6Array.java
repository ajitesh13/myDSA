import java.util.Arrays;

public class prog6Array {
    public static void main(String[] args) {
        int[] ar = {5, 4, 3, 2, 1};
        Arrays.sort(ar); // sort the array
        System.out.println(Arrays.binarySearch(ar, 4)); // operate binary search and return the index
        Arrays.fill(ar, 12); // to fill all the elemnt of the array 
        
        for (int i: ar) {
            System.out.println(i);
        }
    }
}

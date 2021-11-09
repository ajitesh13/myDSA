import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Prog2Queue {
    public static void main(String[] args) {
        /*  LinkedList class is basically implementing the queue interface 
            So now, the LinkedList menthod have all the method the queue has provided to it
        */
        Queue<Integer> q = new LinkedList<>(); 
        q.offer(12);
        q.offer(13);
        q.offer(17);
        System.out.println(q);
        System.out.println(q.poll());
        System.out.println(q);
        System.out.println(q.peek());

        // Queue<Integer> pq = new PriorityQueue<>(); // min heap
        Queue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder()); // max heap
        pq.offer(40);
        pq.offer(12);
        pq.offer(24);
        pq.offer(36);
        System.out.println(pq); // [12, 36, 24, 40]
        System.out.println(pq.poll()); // 12
        System.out.println(pq); // [24, 36, 40]
        System.out.println(pq.peek());
    }
}

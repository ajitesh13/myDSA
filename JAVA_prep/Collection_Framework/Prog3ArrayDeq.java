import java.util.ArrayDeque;

public class Prog3ArrayDeq {
    public static void main(String[] args) {
        ArrayDeque<Integer> deq = new ArrayDeque<>();
        
        deq.offer(4);
        deq.offer(5);
        deq.offer(7);
        System.out.println(deq);
        
        deq.offerFirst(199);
        deq.offerFirst(188);
        System.out.println(deq);
        
        deq.offerLast(200);
        deq.offerLast(201);
        System.out.println(deq);

        System.out.println(deq.poll());
        System.out.println(deq);
        System.out.println(deq.pollFirst());
        System.out.println(deq);
        System.out.println(deq.pollLast());
        System.out.println(deq);

        System.out.println(deq.peek());
        System.out.println(deq.peekFirst());
        System.out.println(deq.peekLast());

        

    }
}

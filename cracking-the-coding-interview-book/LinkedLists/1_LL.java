class Node{
    Node next = null;
    int data;
    public Node(int d){
        data = d;
    }
    void appendtoTail(int d){
        Node end = new Node(d);
        Node n = ths;
        while(n.next != null){
            n = n.next;
        }
        n.next = end;
    }
}
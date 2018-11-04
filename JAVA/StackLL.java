public class StackLL<T>
{
    private Node first = null;

    private class Node
    {
        T item;
        Node next;
    }

    public boolean isEmpty()
    {
        return first == null;
    }

    public void push(T item)
    {
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
    }

    public T pop()
    {
        T item = first.item;
        first = first.next;
        return item;
    }
}

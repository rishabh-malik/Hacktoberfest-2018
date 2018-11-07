public class QueueLinkedList<T>
{
    private Node first, last;

    private class Node
    {
        T item;
        Node next;
    }

    public boolean isEmpty()
    {
        return first == null;
    }

    public void enqueue(T item)
    {
        Node oldLast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if (isEmpty())
        {
            first = last;
        }
        else
        {
            oldLast.next = last;
        }
    }

    public T dequeue()
    {
        T item = first.item;
        first = first.next;
        if (isEmpty())
        {
            last = null;
        }
        return item;
    }
}

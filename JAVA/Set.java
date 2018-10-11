import java.util.AbstractCollection;
import java.util.Iterator;

/**
 * A set or collection of distinct objects.
 * @param <T> Type of objects in this set.
 * @version 0.1.0
 * @author Patrick Schemering
 */
public class Set<T> extends AbstractCollection<T>
{
    // Data
    /**
     * First element in the set.
     */
    private Node head;

    /**
     * Last element in the set.
     */
    private Node tail;

    /**
     * Size of the set.
     */
    private int size = 0;

    // Public Methods

    /**
     * Add an element to the set.
     * O(1) time.
     * @param item Data of element.
     * @return true if successful.
     */
    public boolean add(T item)
    {
        if( item == null )
            return false;
        if( size == 0 )
            head = new Node(item);
        if ( size == 1 ) {
            tail = new Node(item);
            head.next = tail;
        }
        if ( size > 1 ) {
            Node addElement = new Node(item);
            tail.next = addElement;
            tail = addElement;
        }
        size++;
        return true;
    }

    /**
     * Add a set of elements to the set.
     * O(1) time.
     * @param other Set to add to this set.
     * @return True if successful.
     */
    public boolean addAll(Set<T> other)
    {
        if( other == null || other.size == 0)
            return false;

        if ( size == 0 )
            this.head = other.head;

        if ( size == 1 )
            head.next = other.head;

        if ( size > 1 )
            tail.next = other.head;

        if ( other.size > 1 )
            tail = other.tail;
        else
            tail = other.head;

        size += other.size;
        return true;
    }

    /**
     * Clear the set to the empty set.
     * O(1) time.
     */
    public void clear()
    {
        size = 0;
        head = null;
    }

    /**
     * Get the size of the set.
     * O(1) time.
     * @return size of the set.
     */
    public int size()
    {
        return size;
    }

    /**
     * Implements Iterator.
     * @return an iterator starting at the first element.
     */
    public Iterator<T> iterator()
    {
        return new Iterator<T>()
        {
            /**
             * Starting point of iterator.
             */
            private Node current = head;

            /**
             * Next element in the set.
             * @return Data of next element.
             * @throws RuntimeException when no more elements exist - Should be NoSuchElementException but project rules don't allow import of additional libraries ie: java.util.NoSuchElementException
             */
            public T next()
            {
                if ( !hasNext() )
                    throw new RuntimeException("No more elements exist."); // note: Should be NoSuchElementException but not allowed to import additional libraries ( java.util.NoSuchElementExpression )
                T temp = current.data;
                current = current.next;
                return temp;
            }

            /**
             * Check if more elements exist.
             * @return true if more elements exist.
             */
            public boolean hasNext()
            {
                return current != null;
            }
        };
    }

    // Private Helpers

    /**
     * Nodes hold elements in a set.
     * @author Patrick Schemering
     */
    class Node{
        /**
         * data connected to an element.
         */
        T data;
        /**
         * next element in the set.
         */
        Node next;

        /**
         * Initialise node with a data element.
         * @param data data element.
         */
        Node(T data){   this.data = data;   }
    }
}

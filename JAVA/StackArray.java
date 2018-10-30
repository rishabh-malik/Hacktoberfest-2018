public class StackArray<T>
{
    T[] stackArray;
    int N;

    public StackArray()
    {
        // Java does not allow for generic array creation so a cast of an Object array is needed.
        stackArray = new (T) Object[1];
        N = 0;
    }

    public boolean isEmpty() { return N == 0; }

    public void push(T item)
    {
        // Double array size when length is reached
        if (N == stackArray.length) { resize(stackArray.length * 2); }
        stackArray[N++] = item;
    }

    public T pop()
    {
        T item = stackArray[--N];
        stackArray[N] = null;
        // Halve array size when array is one-quarter full (avoids "thrashing")
        if (N > 0 && N == stackArray.length/4) { resize(stackArray.length/2); }
        return item;
    }

    private void resize(int capacity)
    {
        T[] copy = new (T) Object[capacity];
        for (int i = 0; i < N; i++) { copy[i] = stackArray[i]; }
        stackArray = copy;
    }
}

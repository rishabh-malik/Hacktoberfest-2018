import java.util.ArrayList;

/**
 * Disjoint set class, using union by size and path compression.
 * Elements in the set are numbered starting at 0.
 * @version 0.1.0
 * @author Mark Allen Weiss
 * @author Patrick Schemering
 */
public class DisjointSets<T>
{
    //Constructor
    /**
     * Construct the disjoint sets object.
     * Initiate internal array based on data size.
     * @param data The initial set of data.
     */
    public DisjointSets( ArrayList<T> data  )
    {
        numSets = data.size();
        sets = new ArrayList<>();
        for(Object o : data) {
            Set<T> singleSet = new Set<>();
            singleSet.add( (T) o );
            sets.add(singleSet);
        }
        s = new int [numSets];
        for( int i = 0; i < numSets; i++ )
            s[i] = -1;
    }

    //  Public Methods

    /**
     * Union two disjoint sets using the height heuristic.
     * root1 and root2 are distinct and represent set names.
     * O(1) time.
     * @param root1 the root of set 1.
     * @param root2 the root of set 2.
     * @return Root of union set
     * @throws IllegalArgumentException if root1 or root2 are not distinct roots.
     */
    public int union( int root1, int root2 )
    {
        assertIsRoot(root1);
        assertIsRoot(root2);
        if( root1 == root2 )
            throw new IllegalArgumentException( "Union: root1 == root2 " + root1 );

        // Track for new root and updating sets.
        int dstRoot;
        int srcRoot;

        if( s[root2] < s[root1] ) {  // root2 is deeper
            s[root2] += s[root1]; //Update height.
            s[root1] = root2;   // Make root2 new root
            dstRoot = root2;
            srcRoot = root1;
        }
        else
        {
            s[root1] += s[root2]; //Update height.
            s[root2] = root1;        // Make root1 new root
            dstRoot = root1;
            srcRoot = root2;
        }

        //Update sets.
        sets.get(dstRoot).addAll( sets.get(srcRoot) );
        //sets.get(srcRoot).clear();
        numSets--;
        return dstRoot;
    }

    /**
     * Perform a find with path compression.
     * @param x the element being searched for.
     * @return the set containing x.
     * @throws IllegalArgumentException if x is not valid.
     */
    public int find( int x )
    {
        assertIsItem(x);
        return ( s[x] < 0 ) ? x : find( s[x] );
    }

    /**
     * Get all data in the same set.
     * O(1) time.
     * @param root of subset.
     * @return root of set.
     */
    public Set<T> get( int root )
    {
        return sets.get( find(root) );
    }

    /**
     * Get the number of disjoint sets.
     * O(1) time.
     * @return The number of disjoint sets remaining.
     */
    public int getNumSets()
    {
        return numSets;
    }

    //  Private Helpers

    /**
     * Verify this index is a root
     * @param root Index to assert.
     */
    private void assertIsRoot(int root) {
        assertIsItem( root );
        if( s[root] >= 0 )
            throw new IllegalArgumentException( "Union: " + root + " not a root" );
    }

    /**
     * Verify this item exists
     * @param x item
     */
    private void assertIsItem( int x ) {
        if( x < 0 || x >= s.length )
            throw new IllegalArgumentException( "Disjoint sets: " + x + " not an item" );
    }

    //Data

    /**
     * Internal array represents DisJointSets data structure.
     */
    private int [ ] s;
    /**
     * Set of actual data.
     */
    private ArrayList<Set<T>> sets;
    /**
     * Keep track number of DisjointSets.
     */
    private int numSets;
}


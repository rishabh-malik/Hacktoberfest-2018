ing System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// <para>
    /// Bubble Sort algorithm - O(n^2)
    /// Sorts an array of integers from low to high by comparing each element to the next, then swapping them
    /// if the comparison is greater. Any detected swaps result in looping through the collection again.
    /// </para>
    /// <para>
    /// The algorithm below can absolutely be refactored into something more appropriate (for modern OOP), and
    /// could take advantage of many advanced C# features. I prefer it to remain straightforward and classical
    /// as a learning example.
    /// </para>
    /// </summary>
    /// <returns>A sorted array of integers.</returns>
    class BubbleSort
    {
        public int[] Sort(int[] intArrayToSort)
        {
            bool swapped = true;

            while (swapped)
            {
                swapped = false;

                for (int i = 0; i < intArrayToSort.Length - 1; i++)
                {
                    if (intArrayToSort[i] > intArrayToSort[i + 1])
                    {
                        var _temp = intArrayToSort[i];
                        intArrayToSort[i] = intArrayToSort[i + 1];
                        intArrayToSort[i + 1] = _temp;
                        swapped = true;
                    }
                }
            }

            return intArrayToSort;
        }
    }
}


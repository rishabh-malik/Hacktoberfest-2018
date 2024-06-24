

// Function to reverse arr[] from start to end
fun reverseArray(array: ArrayList<Int>): ArrayList<Int> {

   //logic to reverse an array
    for (i in 0 until array.size/2) {
        val temp = array[i]
        array[i] = array[array.size -i -1]
        array[array.size -i -1] = temp
    }

    return array   //printing the reverse array
}




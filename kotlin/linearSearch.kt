fun linearSearch(list:List<Any>, key:Any):Int?{
	for ((ind, val) in list.withIndex()) {
		if (val == key){
			return ind
		}
	}
	return null
}
fun main(args: Array<String>) {

    val aList = listOf(90,90,"Kim")
    val name = "Kim"
    val pos = linearSearch(aList, name)
    println("${name} is in the position ${pos} \n")
}

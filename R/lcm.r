lcm<-function(x,y)
{
    a=x
    b=y
    while (a != b)
  {
    if (a > b)
    {
      a = a - b
    }
    else
    {
      b = b - a
    }
  }
  print((x*y)/a)
}
        
       
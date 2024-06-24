bd<-function(n)
{
  d= 0
  i= 0
    while (n!=0)
  {
    r=n%%10;
    n=n%/%10;
    d=d+ r*(2^i)
    i=i+1
  }
  return(d)
}
n=scan()
flag=0
if ( n >= 1 )
{
  print(2)
}

for (i in 2:n)
{
  flag=0;
  for (j in 2:(i/2))
  {
    if ( i%%j == 0 )
    {
       flag=1
       break
  }
}
  if ( flag == 0 )
  {
    print(i)
  }
}
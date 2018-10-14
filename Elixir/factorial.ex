defmodule Factorial do
   def fact(res, num) do
   if num === 1 do
      res
   else
      new_res = res * num
      fact(new_res, num-1)
      end
   end
end

IO.puts(Factorial.fact(1,5))
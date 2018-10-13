defmodule MergeSort do
  def sort(l) do
    cond do
      l == [] -> []
      length(l) <= 1 -> l
      true ->
        middle = div(length(l), 2)
        left = Enum.slice(l, 0, middle)
        right = Enum.slice(l, middle, length(l) - length(left))
        left = sort(left)
        right = sort(right)
        merge(left, right)
    end
  end

  def merge(left, right) do
    cond do
      left == [] -> right
      right == [] -> left
      hd(left) <= hd(right) -> [hd(left)] ++ merge(tl(left), right)
      true -> [hd(right)] ++ merge(left, tl(right))
    end
  end
end

MergeSort.sort([4, 3, 2, 1])
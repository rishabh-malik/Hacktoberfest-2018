defmodule NN do
    def sigmoid(x), do: 1 / (1 + :math.exp(-x))
end
IO.puts NN.sigmoid(0.458)
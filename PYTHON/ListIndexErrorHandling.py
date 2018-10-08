list = ["one", "two"]
# list = 1

try:
    print("Third element -> " + list[2])
except IndexError:
    print("No third element!")
except TypeError:
    print("Not a list!")

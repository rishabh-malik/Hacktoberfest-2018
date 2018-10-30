def triangle(a,b,c):
    p = (a + b + c) / 2
    s = float((p * (p-a) * (p-b) * (p-c)) ** 0.5)
    return s

def square(a,b):
    s = float(a * b)
    return s

def circle(a):
    s = float(a ** 2 * 3.14)
    return s

def main():
    while True:
      shape = input("Choose a shape: triangle, square or circle:")
      if shape == "triangle":
        a, b, c = [int(input("Enter side length:")) for _ in range(3)]
        print(f"Triandle area equals {triangle(a,b,c)}")
      elif shape == "square":
        a, b = [int(input("Enter side length:")) for _ in range(2)]
        print(f"Square area equals {square(a,b)}")
      elif shape == "circle":
        a = int(input("Enter radius:"))
        print(f"Cirle area equals {circle(a)}")
      elif shape == "q":
        break
      else:
        continue

main()

# volPrism calculates the volumes of rectangular prisms.
def volPrism():

    edge1 = float(input("What is the length of the base length? "))
    edge2 = float(input("What is the length of the base width? "))    
    edge3 = float(input("What is the length of the height? "))
    
    vol = edge1 * edge2 * edge3
    
    print("Volume is: " + vol)
    
    return vol
    
volPrism()

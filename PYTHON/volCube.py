# volCube calculates cube volume from cube edge
def volCube():
    
    edge = float(input("What is the length of the edge? "))
    
    vol = edge**3
    
    print("Cube volume is " + vol)
    
    return vol
    
volCube()    

# volCylinder.py calculates cylinder volume from radius, and height
def volCylinder():

    rad = float(input("What is the radius of the base of the cylider? "))
    height = float(input("What is the height of the cylinder? "))
    
    vol = pi * rad * rad * height
    
    print("Volume is",vol)
    
    return vol
    
volCylinder()    

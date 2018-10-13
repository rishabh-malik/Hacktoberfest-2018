import random

class DiamondSquare:

    def jitterValue(self):
        sign = random.sample([-1,1],1)[0]
        value = random.random()
        return sign * value

    def getCenter(self, xStart, yStart, xEnd, yEnd):
        return ((xStart + xEnd) // 2, (yStart + yEnd) // 2)

    def setValue(self, heightMap, x, y, value):
        heightMap[x][y] = value

    def getMidpoints(self, xStart, yStart, xEnd, yEnd):
        m1 = (xStart, (yStart + yEnd) // 2)
        m2 = ((xStart + xEnd) // 2, yStart)
        m3 = (xEnd, (yStart + yEnd) // 2)
        m4 = ((xStart + xEnd) // 2, yEnd)
        return (m1, m2, m3, m4)

    def diamondSquare(self, n, heightMap, xStart, yStart, xEnd, yEnd):
        xCenter, yCenter = self.getCenter(xStart, yStart, xEnd, yEnd)
        value = round(min((heightMap[xStart][yStart] + heightMap[xStart][yEnd] + heightMap[xEnd][yStart] + heightMap[xEnd][yEnd]) / 4 + random.random() / 1000, 1.0),2)
        self.setValue(heightMap, xCenter, yCenter, value)

        midPoints = self.getMidpoints(xStart, yStart, xEnd, yEnd)

        m1Value = round(min(max((heightMap[xStart][yStart] + heightMap[xStart][yEnd] + heightMap[xCenter][yCenter]) / 3 + self.jitterValue(),0), 1.0),2)
        m2Value = round(min(max((heightMap[xStart][yStart] + heightMap[xEnd][yStart] + heightMap[xCenter][yCenter]) / 3 + self.jitterValue(),0), 1.0),2)
        m3Value = round(min(max((heightMap[xEnd][yStart] + heightMap[xEnd][yEnd] + heightMap[xCenter][yCenter]) / 3 + self.jitterValue(),0), 1.0),2)
        m4Value = round(min(max((heightMap[xStart][yEnd] + heightMap[xEnd][yEnd] + heightMap[xCenter][yCenter]) / 3 + self.jitterValue(),0), 1.0),2)

        mValues = (m1Value, m2Value, m3Value, m4Value)

        for i in range(len(midPoints)):
            self.setValue(heightMap, midPoints[i][0], midPoints[i][1], mValues[i])

        if n == 1:
            return

        else:
            self.diamondSquare(n-1, heightMap, xStart, yStart, xCenter, yCenter)
            self.diamondSquare(n-1, heightMap, xCenter, yStart, xEnd, yCenter)
            self.diamondSquare(n-1, heightMap, xStart, yCenter, xCenter, yEnd)
            self.diamondSquare(n-1, heightMap, xCenter, yCenter, xEnd, yEnd)

    def createMap(self, n):

        if n <= 0:
            return None

        size = 2**n + 1
        heightMap = [[0 for j in range(size)] for i in range(size)]

        self.setValue(heightMap, 0, 0, round(random.random(),2))
        self.setValue(heightMap, size-1, 0, round(random.random(),2))
        self.setValue(heightMap, 0, size-1, round(random.random(),2))
        self.setValue(heightMap, size-1, size-1, round(random.random(),2))

        self.diamondSquare(n, heightMap, 0, 0, size-1, size-1)

        return heightMap

    def printMap(self, heightMap):
        if not heightMap is None:
            width = len(heightMap)
            for i in range(width):
                for j in range(width):
                    print("%.2f" % (heightMap[i][j]), end=" ")
                print()

### Usage ###

# square = DiamondSquare()
# newMap = square.createMap(3)
# square.printMap(newMap)



def hash(num):
    return num % 500069


class RollingHash():
    def __init__(self, word, length):
        self.hash = 0
        self.sum = 0
        self.length = length
        self.salt = 0
        self.magic = hash(256**self.length)
        for i in range(0, length):
            self.sum += ord(word[i]) * 256 ** (length - 1 - i)
        self.hash = hash(self.sum)

    def moveWindow(self, new, old):
        self.hash = hash((self.hash * 256) -
                         (ord(old) * self.magic) + ord(new))


file = open("karp-test.txt", "r")
test = file.read()
#test = "test policy fj policy.dshfjkshfkj h h fh"
word = "checksum"

wordR = RollingHash(word, len(word))
testR = RollingHash(test[0:len(word)], len(word))

for i in range(0, len(test) - len(word)):
    if(wordR.hash == testR.hash):
        if(test[i:i + len(word)] == word):
            print("Found at ", i)
    testR.moveWindow(test[i + len(word)], test[i])

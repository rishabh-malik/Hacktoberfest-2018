import pygame
import sys
import random

# consts
width,height = 500,500
FPS = 60
running = True
SCL = 10

WHITE = (255,255,255)
BLACK = (0,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)
RED = (255,0,0)
#pygame set
clock = pygame.time.Clock()
screen =  pygame.display.set_mode((width, height))

canvas = []
cols = round(width/SCL)
rows = round(height/SCL)

class Maze():
    """docstring for Maze"""
    def __init__(self):
        
        self.ant = Ant()
        self.initCanvas()

        while running:
            self.events()
            self.update()
            pygame.display.update()
            clock.tick(10000/FPS)

    def initCanvas(self):
        for i in range(cols):
            canvas.append([])
            for j in range(rows):
                canvas[i].append( WHITE )  
            

    def update(self):

        self.ant.draw()

        self.render()

        self.ant.update()

        self.drawAxes()
        self.printSteps()

    def render(self):
        for i in range(cols):
            for j in range(rows):
                if(len(canvas[i][j]) == 2):
                    pygame.draw.rect(screen, canvas[i][j][1], [i*SCL,j*SCL,SCL,SCL])
                else:
                    pygame.draw.rect(screen, canvas[i][j], [i*SCL,j*SCL,SCL,SCL])

    def events(self):
        for e in pygame.event.get():
            if e.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if e.type == pygame.KEYDOWN:
                if e.key == pygame.K_q:
                    pygame.quit()
                    sys.exit()

    def drawAxes(self):
        for i in range(width):
            for j in range(height):
                pygame.draw.line(screen,(0,0,100), [i*SCL,0],[i*SCL,height])
                pygame.draw.line(screen,(0,0,100), [0,j*SCL],[width,j*SCL])

    def printSteps(self):
        tamFont = 45
        pygame.font.init()
        font = pygame.font.get_default_font()
        fontJogo = pygame.font.SysFont(font,tamFont)
        steps = fontJogo.render('Step: {}'.format(self.ant.step),1,RED)
        screen.blit(steps, (10,10))

class Ant():    
    def __init__(self):
        self.x,self.y = int(rows/2),int(cols/2)
        self.dir = 1
        self.step = 0

    def draw(self):
        canvas[self.x][self.y] = [canvas[self.x][self.y],GREEN]

    def update(self):
        if( self.y+1 >= rows or self.y-1 < 0):            
            return
        elif(self.x+1 >= cols or self.x-1 < 0):
            return

        if(canvas[self.x][self.y][0] == WHITE):
            canvas[self.x][self.y] = BLACK
            self.rotate(1)
            self.move()
        elif(canvas[self.x][self.y][0] == BLACK):
            canvas[self.x][self.y] = WHITE
            self.rotate(-1)
            self.move()
        
    def rotate(self,a=1):
        # 1 = 90 graus pra dir, -1 = 90 graus pra esq
        # N = 1, L = 2, S = 3, O = 4
        self.dir += a

        if(self.dir > 4):
            self.dir = 1
        elif(self.dir <= 0):
            self.dir = 4

    def move(self):
        if self.dir == 1:
            self.y -= 1
        elif self.dir == 2:
            self.x += 1
        elif self.dir == 3:
            self.y += 1
        elif self.dir == 4:
            self.x -= 1

        self.step += 1


if __name__ == '__main__':
    Maze()
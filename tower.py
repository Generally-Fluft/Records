class Disc:
    def __init__(self, size):
        self.size = size
    def __str__(self):
        return str(self.size)

class Tower:
    def __init__(self, height):
        self.height = height
        self.discs = []
    
    def add_disc(self, disc):
        self.discs.append(disc)    

    def remove_disc(self):
        return self.discs.pop()

    def display(self):
        for i in range(self.height):
            if len(self.discs) < self.height - i:
                print("   0   ")
            else:
                print("  ", self.discs[self.height - i - 1].size)
        print("=======")

    def top(self):
        t = Disc(0)
        for d in self.discs:
            if d.size > 0:
                t = d
                continue
            else:
                break
        return t

    def sizes(self):
        l = []
        for d in self.discs:
            l.append(d.size)
        return l


def move_disc(fr, to):
    if len(fr.discs):
        if fr.top().size < to.top().size or to.top().size == 0:
            to.add_disc(fr.remove_disc())
            return True
    return False

def print_towers():
    print((' ' + ' ' * numDiscs + "||" + ' ' * (numDiscs + 1) + ' ') * 3)
    for j in range(numDiscs):
        for i in range(3):
            if len(towers[i].discs) >= numDiscs - j:
                print(' ', ' ' * (numDiscs - towers[i].discs[numDiscs - j - 1].size), '#' * (towers[i].discs[numDiscs - j - 1].size), sep='', end='')
                print('||', '#' * (towers[i].discs[numDiscs - j - 1].size), ' ' * (numDiscs - towers[i].discs[numDiscs - j - 1].size), sep='', end='  ')
            else:
                print(' ' + ' ' * numDiscs + "||" + ' ' * numDiscs + ' ', end=' ')
        print()
    print(('=' * (numDiscs + 2) * 2 + ' ') * 3)
    print()

def index(array, item):
    idx = 0
    for a in array:
        if i == item:
            return idx
        idx += 1
    return -1

def getMove(string):
    move = int(input(string))
    while not (move == 1 or move == 2 or move == 3):
        print("Invalid Move")
        move = int(input(string))
    return move

numDiscs = int(input("Number of discs: "))
winCond = Tower(numDiscs)

towers = [Tower(numDiscs), Tower(numDiscs), Tower(numDiscs)]
for d in range(numDiscs, 0, -1):
    towers[0].add_disc(Disc(d))
    winCond.add_disc(Disc(d))

win = False

print_towers()

while not win:
    fr = getMove("From: ")
    to = getMove("To: ")

    move_disc(towers[fr - 1], towers[to - 1])

    print_towers()

    if towers[1].sizes() == winCond.sizes():
        win = True
        print("You Won!")

from dataclasses import replace


def main():
    with open('input.in') as input:
        data = input.read().replace('\n', '').split(', ')
    
    dir = 0
    x = 0
    y = 0
    visited = set()
    visited.add((0,0))
    visitedTwice = []

    for c in data:
        num = int(c.replace(c[0], ''))
        if c[0] == 'R':
            dir += 90
        else:
            dir -= 90
        
        if dir == 360:
            dir = 0
            
        if dir == 270:
            dir = -90
        if dir == -270: 
            dir = 90

        for _ in range(num):
            if dir == 0:
                y += 1
            elif dir == 90:
                x += 1
            elif dir == 180 or dir == -180:
                y -= 1
            elif dir == -90:
                x -= 1
            if (x,y) in visited:
                visitedTwice.append(abs(x) + abs(y))
            else:
                visited.add((x,y))

    # Part 1
    print("Part 1:" , abs(x) + abs(y))

    # Part 2
    print("Part 2:" , min(visitedTwice))

if __name__ == '__main__':
    main()
with open('input.in') as input:
        data = input.read()

def part1():
    num = 5
    results = []

    for c in data:
        if c == 'R' and num != 3 and num != 6 and num != 9:
            num += 1
        elif c == 'L' and num != 1 and num != 4 and num != 7:
            num -= 1
        elif c == 'U' and num > 3:
            num -= 3
        elif c == 'D' and num < 7:
            num += 3
        if c == '\n':
            results.append(num)

    print('Part 1: ', results)

def part2():
    results = []
    pos = 5

    for c in data:
        if c == 'R' and pos != 1 and pos != 4 and pos != 9 and pos < 12:
            pos += 1
        elif c == 'L' and pos > 2 and pos != 5 and pos != 10 and pos != 13:
            pos -= 1
        elif c == 'U' and pos > 2 and pos != 4 and pos != 5 and pos != 9:
            if (pos > 5 and pos < 9) or (pos > 9 and pos < 13):
                pos -= 4
            elif pos == 3 or pos == 13:
                pos -= 2

        elif c == 'D' and pos != 5 and pos != 9 and pos != 10 and pos < 12:
            if (pos > 5 and pos < 9) or (pos > 1 and pos < 5):
                pos += 4
            elif pos == 1 or pos == 11:
                pos += 2
        if c == '\n':
            if pos == 10:
                results.append('A')
            elif pos == 11:
                results.append('B')
            elif pos == 12:
                results.append('C')
            elif pos == 13:
                results.append('D')
            else:
                results.append(pos)

    print('Part 2: ', results)

   
    

if __name__ == '__main__':
    part1()
    part2()
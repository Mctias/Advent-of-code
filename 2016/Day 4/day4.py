from collections import OrderedDict

def format_string(s):
    data = []
    word = ''
    num = ''
    for c in s:
        if c.isnumeric():
            num += c
        elif c == '[' or c == ']':
            data.append(word.replace('-',''))
            word= ''
        else:
            word+=c
    data.append(num)
    return data

with open('input.in') as input:
    ins_list = list(input)
    data = []
    for i in ins_list:
        data.append(format_string(i))

def removeDup(str):
    return "".join(OrderedDict.fromkeys(str))

to_delete = []

def part1():
    sum = 0
    count = 0
    
    for i in data:
        # Sorted by alphabet
        alph_sorted = sorted(i[0])

        # Sorted by number of occurences
        num_sorted = sorted(alph_sorted, key=lambda c: -alph_sorted.count(c))

        # This string is sorted numerically then alphabetically
        final = removeDup("".join(num_sorted))
        
        # The final string should only be 5 chars
        final = final[:5]
        # If our string is the equal to the given string we add the numbers
        if final == i[1]:
            sum += int(i[2])
        else:
            to_delete.append(count)
        count += 1
    
    print('Part 1:', sum)

def part2():
    new_data = [j for i, j in enumerate(data) if i not in to_delete]
    results = []
    
    # Find all the rooms by incrementing letters
    for i in new_data:
        resulting_room = ''
        for c in i[0]:
            for _ in range(int(i[2])):
                if c == 'z':
                    c = 'a'
                    continue
                c = chr(ord(c) + 1)
            resulting_room += c
        results.append((resulting_room, int(i[2])))
    
    # Search for northpole in all of the strings (rooms)
    for i in results:
        if 'northpole' in i[0]:
            print('Part 2:', i[1], '(', i[0], ')')        



if __name__ == '__main__':
    part1()
    part2()
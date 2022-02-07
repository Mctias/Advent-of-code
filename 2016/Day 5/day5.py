import hashlib

def part1():
    input = 'reyedfim'

    password = ''
    count = 0
    num = 0

    while count < 8:
        string = input + str(num)
        hash = hashlib.md5(string.encode()).hexdigest()

        if hash[:5] == '00000':
            password += hash[5]
            count += 1

        num += 1
    
    print('Part 1:', password)

def part2():
    input = 'reyedfim'

    password = []
    final_password = ''
    filled = []
    count = 0
    num = 0
    
    while count < 8:
        string = input + str(num)
        hash = hashlib.md5(string.encode()).hexdigest()
        
        num += 1

        if hash[:5] == '00000':
            if hash[5].isalpha() or int(hash[5]) > 7 or hash[5] in filled:
                continue
            password.append((hash[5], hash[6]))
            filled.append(hash[5])
            count += 1
    
    password.sort()

    for i in password:
        final_password += i[1]

    print('Part 2:', final_password)




if __name__ == '__main__':
    part1()
    part2()
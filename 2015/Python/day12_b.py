import json

def solution(data):
    if type(data) == int:
        return data
    if type(data) == list:
        return sum([solution(data) for data in data])
    if type(data) != dict:
        return 0
    if 'red' in data.values():
        return 0
    
    return solution(list(data.values()))

f = open('input.json')

data = json.load(f)

print(solution(data))
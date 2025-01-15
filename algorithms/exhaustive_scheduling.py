from itertools import combinations

events = [
    {'name': 'A', 'start': 1, 'end': 4},
    {'name': 'B', 'start': 3, 'end': 5},
    {'name': 'C', 'start': 0, 'end': 6},
    {'name': 'D', 'start': 5, 'end': 7},
    {'name': 'E', 'start': 8, 'end': 9}
]

def is_non_overlaping(subset):
    for i in range(len(subset) - 1):
        if subset[i]['end'] > subset[i + 1]['start']:
            return False
    return True

def exhaustive_scheduling(events):
    max_non_overlaping = []

    for r in range(1, len(events) + 1):
        for  subset in combinations(events, r):
            subset = sorted(subset, key=lambda x: x['start'])
            if is_non_overlaping(subset) and len(subset) > len(max_non_overlaping):
                max_non_overlaping = subset
    return max_non_overlaping


exhaustive_schedule = exhaustive_scheduling(events)
for film in exhaustive_schedule:
    print(f"Film {film['name']} : du jour {film['start']} au jour {film['end']}")
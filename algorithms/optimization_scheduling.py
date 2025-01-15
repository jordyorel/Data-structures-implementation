

events = [
    {'name': 'A', 'start': 1, 'end': 4},
    {'name': 'B', 'start': 3, 'end': 5},
    {'name': 'C', 'start': 0, 'end': 6},
    {'name': 'D', 'start': 5, 'end': 7},
    {'name': 'E', 'start': 8, 'end': 9}
]






def optimimal_scheduling(events):
    # sort films by ending dates
    sorted_event = sorted(events, key=lambda x: x['end']) 

    selected_event = []
    last_end_time = 0

    for event in sorted_event:
        if event['start'] >= last_end_time:
            selected_event.append(event)

            last_end_time = event['end']
    return selected_event


optimal_schedule = optimimal_scheduling(events)
for film in optimal_schedule:
    print(f"Film {film['name']} : du jour {film['start']} au jour {film['end']}")


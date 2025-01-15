


# def increment(y):
#     if y == 0:
#         return 1
#     elif y % 2 == 1:
#         return 2 * increment(y / 2)
#     else:
#         return y + 1



# print(increment(2))

print()
def f(ham: str, eggs: str = 'eggs') -> str:
    print("Annotations:", f.__annotations__)
    print("Hello")
    print("Arguments:", ham, eggs)
    return ham + ' and ' + eggs

f("ham")

print()

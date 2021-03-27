from operator import attrgetter

e1 = ('Carl', 37, 70000)
e2 = ('Sarah', 29, 80000)
e3 = ('John', 43, 90000)

employees = [e1, e2, e3]

s_employees = sorted(employees. key=attrgetter('age'))
print(s_employees)
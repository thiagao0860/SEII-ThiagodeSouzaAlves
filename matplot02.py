import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

labels = ['a', 'b', 'c']
values = [1, 3, 2]

bars = plt.bar(labels, values)

patterns = ['/', 'O', '*']

for bar in bars:
    bar.set_hatch(patterns.pop(0))

# bars[1].set_hatch('o')
# bars[0].set_hatch('/')
# bars[2].set_hatch('*')


plt.show()



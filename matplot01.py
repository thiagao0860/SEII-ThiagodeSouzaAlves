import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

x = [1,2,3]
y = [2,4,6]

plt.figure(figsize=(5, 3), dpi=100)
#plt.plot(x, y, label='2x', color='red', linewidth='0.5', marker='.', linestyle='--')
plt.plot(x, y,'r.--', label='2x')

x2 = np.arange(0, 9, 0.5)
y2 = x2**2
plt.plot(x2[:3], y2[:3], 'b-', label='^2')
plt.plot(x2[2:], y2[2:], 'b--')

plt.title("My first Graph!")
plt.xlabel("eixo X")
plt.ylabel("eixo y")

#plt.xticks([1,2,3,4,5,6,7,8,9,])
#plt.yticks([1,2,3,4,5,6,7,8,9,])

plt.legend()

plt.savefig('mygraph.png', dpi=500)

plt.show()
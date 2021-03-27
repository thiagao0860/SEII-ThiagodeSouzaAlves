import os
from datetime import datetime

os.chdir('/home/thiago/Desktop')

print(os.environ.get('HOME'))

file_path = os.path.join(os.environ.get('HOME'), 'test.txt')
print(file_path)
